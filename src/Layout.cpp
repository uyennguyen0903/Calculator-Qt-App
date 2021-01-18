#include "Layout.h"

#include "QComputer.h"

ProgramLayout::ProgramLayoutHandler ProgramLayout::programLayout_handler_;
VariableLayout::VariableLayoutHandler VariableLayout::variableLayout_handler_;

Layout::Layout(const QString title, const QString contentName)
    : title(title), contentName(contentName) {
  QLabel* label_tab = new QLabel(title);
  label_tab->setAlignment(Qt::AlignCenter);

  // Créer la barre de message pour l'utilisateur dans la vue de programme.
  message = new QLineEdit;
  message->setReadOnly(true);
  message->setFixedHeight(40);
  message->setAlignment(Qt::AlignCenter);
  message->setStyleSheet("font:20px");

  // Description des colonnes
  QHBoxLayout* description = new QHBoxLayout;
  QLabel* nameLabel = new QLabel("Nom");
  nameLabel->setFixedWidth(74);
  QLabel* conentLabel = new QLabel(contentName);
  description->addWidget(nameLabel);
  description->addWidget(conentLabel);

  // La partie qui affiche les programmes ou variable
  QScrollArea* contentArea = new QScrollArea;
  QWidget* mainElementWidget = new QWidget();
  contentBox = new QVBoxLayout(mainElementWidget);
  contentBox->setAlignment(Qt::AlignTop);
  contentArea->setWidget(mainElementWidget);
  contentArea->setWidgetResizable(true);

  // La vue
  layout = new QVBoxLayout;
  layout->addWidget(label_tab);
  layout->addWidget(message);
  layout->addLayout(description);
  layout->addWidget(contentArea);
  layout->setAlignment(Qt::AlignTop);
  this->setLayout(layout);
}

Layout::~Layout(){};

VariableLayout::~VariableLayout() {}

ProgramLayout::~ProgramLayout() {}

void Layout::addElement(const QString id, const QString content) {
  // Obtenir l'id
  if (ids.indexOf(id) == -1) {  // si l'element n'existe pas déjà
    ids.push_back(id);

    QLineEdit* label = new QLineEdit(id);
    label->setReadOnly(true);
    label->setFixedWidth(72);

    QLineEdit* edit = new QLineEdit(content);

    QPushButton* modifyElement = new QPushButton("Modifier");
    connect(modifyElement, SIGNAL(clicked()), this, SLOT(modify()));

    QWidget* subElementWidget = new QWidget();
    QHBoxLayout* new_line = new QHBoxLayout(subElementWidget);
    new_line->addWidget(label);
    new_line->addWidget(edit);
    new_line->setAlignment(Qt::AlignLeft);
    new_line->addWidget(modifyElement);
    contentBox->addWidget(subElementWidget);
    nb_element++;
  } else {  // si l'element existe déjà
    // retrouver le HBox qui contient cet element
    for (int i = 0; i < contentBox->count(); ++i) {
      QHBoxLayout* line = dynamic_cast<QHBoxLayout*>(
          contentBox->itemAt(i)->widget()->children().at(0));
      QLineEdit* label = dynamic_cast<QLineEdit*>(line->itemAt(0)->widget());

      // retrouver l'element dans la liste des elements
      if (label->text() == id) {
        QLineEdit* edit = dynamic_cast<QLineEdit*>(line->itemAt(1)->widget());
        edit->setText(content);
        break;
      }
    }
  }
};

void Layout::deleteElement(const QString id) {
  if (ids.indexOf(id) != -1) {  // si l'element existe
    for (int i = 0; i < contentBox->count(); ++i) {
      QWidget* widget = contentBox->itemAt(i)->widget();
      QHBoxLayout* line = dynamic_cast<QHBoxLayout*>(widget->children().at(0));
      QLineEdit* label = dynamic_cast<QLineEdit*>(line->itemAt(0)->widget());

      // retrouver l'element dans la liste des elements
      if (label->text() == id) {
        contentBox->removeWidget(widget);
        deletePtr(widget);
        break;
      }
    }
    ids.removeAll(id);
  }
}

void Layout::sendCommand(const QString edit, const QString label) {
  // Creer la commande
  QString commande = edit + " '" + label + "' STO";
  // récupération de l'ancêtre le plus haut (c'est un objet QComputer)
  QObject* parent = this->parent();
  while (parent->parent() != nullptr) {
    parent = parent->parent();
  }
  QComputer* computer = dynamic_cast<QComputer*>(parent);

  // Passer cette commande pour modifier l'element
  computer->setCommande(commande);
  computer->getNextCommande();

  QString msg = computer->getMessage();
  if (msg != "") {  // s'il y a un message d'erreur
    message->setText(msg);
    message->setStyleSheet("color: red");
  } else {  // si l'element est bien modifie
    msg = label + " : " + edit;
    message->setText(msg);
    message->setStyleSheet("color: black");
  }
}

void Layout::modify() {  // lorsqu'on clique sur le button Modifier
  QPushButton* button = (QPushButton*)sender();

  // retrouver le HBox qui contient cet element
  for (int i = 0; i < contentBox->count(); ++i) {
    QHBoxLayout* line = dynamic_cast<QHBoxLayout*>(
        contentBox->itemAt(i)->widget()->children().at(0));
    QPushButton* temp = dynamic_cast<QPushButton*>(line->itemAt(2)->widget());

    // Verifier si c'est bien le boutton clique
    if (button == temp) {
      QLineEdit* label = dynamic_cast<QLineEdit*>(line->itemAt(0)->widget());
      QLineEdit* edit = dynamic_cast<QLineEdit*>(line->itemAt(1)->widget());

      try {
        extendModify(edit->text(), label->text());
      } catch (ComputerException& error) {
        message->setText(error.GetInfo());
        message->setStyleSheet("color: red");
      }

      break;
    }
  }
}

void ProgramLayout::extendModify(const QString edit, const QString label) {
  QStringList list =
      edit.split(QRegExp("\\s+"), QString::SplitBehavior::SkipEmptyParts);
  if (list.length() == 0 or list.at(0) != "[")
    throw ComputerException("Programme invalide.");
  int position = 1, cnt = 1;
  do {
    const QString cur_operand = list.at(position++);
    if (cur_operand == "[") {
      ++cnt;
    } else if (cur_operand == "]") {
      if (cnt > 0) {
        --cnt;
      } else {
        throw(ComputerException("Programme invalide."));
      }
    } else if (FindTypeOperand(cur_operand) ==
               Operand::OperandType::kUndefined) {
      throw(ComputerException("Programme contient operand inconnu."));
    }
  } while (position < list.size());

  if (cnt != 0) {
    throw(ComputerException("Programme invalide."));
  }
  sendCommand(edit, label);
}

void VariableLayout::extendModify(const QString edit, const QString label) {
  QStringList list =
      edit.split(QRegExp("\\s+"), QString::SplitBehavior::SkipEmptyParts);
  if (list.length() != 1) throw ComputerException("Valeur invalide");
  Operand::OperandType type = FindTypeOperand(edit);
  if (type != Operand::OperandType::kInteger and
      type != Operand::OperandType::kReal and
      type != Operand::OperandType::kFraction)
    throw ComputerException("Valeur invalide");
  sendCommand(edit, label);
}

void Layout::deletePtr(QObject* obj) {
  for (int i = 0; i < obj->children().length(); i++) {
    deletePtr(obj->children().at(i));
  }
  delete obj;
  obj = nullptr;
}

ProgramLayout& ProgramLayout::GetInstance() {
  if (programLayout_handler_.instance == nullptr) {
    programLayout_handler_.instance = new ProgramLayout;
  }
  return *(programLayout_handler_.instance);
};

void ProgramLayout::FreeInstance() {
  delete programLayout_handler_.instance;
  programLayout_handler_.instance = nullptr;
};

VariableLayout& VariableLayout::GetInstance() {
  if (variableLayout_handler_.instance == nullptr) {
    variableLayout_handler_.instance = new VariableLayout;
  }
  return *(variableLayout_handler_.instance);
};

void VariableLayout::FreeInstance() {
  delete variableLayout_handler_.instance;
  variableLayout_handler_.instance = nullptr;
};
