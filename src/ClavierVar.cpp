#include "ClavierVar.h"

#include <QChar>
#include <QDebug>
#include <iostream>

#include "QComputer.h"

ClavierVar::ClavierVarHandler ClavierVar::clavierVar_handler_;

// retravailler le destructeur
ClavierVar::~ClavierVar(){
    // delete wClavierVar;
    // pas besoin de delete le pointeur ici car lorsque l'on ajoute le QGroupBox
    // à notre vue principale, celle ci se charge de son cycle de vie et de
    // mort,
    // ici il y avait donc un double appel au destructeur du QGruopBox pointé:
    //- un ici (dans ~ClavierVar() )
    //- un à la destruction de vue_principale
    // par contre on aurai un problème si on ne l'ajoute pas à une vue mais j'ai
    // pas d'autre idée
};

ClavierVar::ClavierVar() {
    scrollArea = new QScrollArea;
    scrollArea->setWidget(new QGroupBox);
    scrollArea->setWidgetResizable(true);
};

ClavierVar& ClavierVar::GetInstance() {
  if (clavierVar_handler_.instance == nullptr) {
    clavierVar_handler_.instance = new ClavierVar;
  }
  return *(clavierVar_handler_.instance);
};

void ClavierVar::FreeInstance() {
  delete clavierVar_handler_.instance;
  clavierVar_handler_.instance = nullptr;
};

void ClavierVar::addButton(QString id) {
  if (ids.indexOf(id) == -1) {  // si le bouton n'existe pas déjà
    // récupération du clavier et des layouts fils nécessaires
    QGroupBox* clavier = ClavierVar::GetInstance().getClavier();
    QVBoxLayout* layout_clavier =
        clavier->findChild<QVBoxLayout*>(QString(), Qt::FindDirectChildrenOnly);
    QList<QHBoxLayout*> childrenLayout =
        layout_clavier->findChildren<QHBoxLayout*>(QString(),
                                                   Qt::FindDirectChildrenOnly);
    QHBoxLayout* current_line = childrenLayout.back();

    // récupération de l'ancêtre le plus haut (c'est un objet QComputer)
    QObject* parent = ClavierVar::GetInstance().getClavier()->parent();
    while (parent->parent() != nullptr) {
      parent = parent->parent();
    }

    QPushButton* bouton = new QPushButton(id);
    bouton->setFixedSize(76, 30);
    connect(bouton, SIGNAL(clicked()), parent, SLOT(onClick()));
    ids.push_back(id);
    nb_bouton++;

    if ((nb_bouton - 1) % 7 !=
        0) {  // il y a de la place sur la ligne => ajout en bout de ligne
      // ajout du boutons sur la ligne courrante
      current_line->addWidget(bouton);
      if (nb_bouton % 7 == 0) current_line->setAlignment(Qt::AlignCenter);
    } else {  // plus de place sur cet ligne => il faut en créer une nouvelle
              // (c'est un HLayout)
      QHBoxLayout* new_line = new QHBoxLayout;
      new_line->addWidget(bouton);
      new_line->setAlignment(Qt::AlignLeft);
      layout_clavier->addLayout(new_line);
    }
  }
};

QGroupBox* ClavierVar::getClavier() { return (QGroupBox*)scrollArea->widget(); }
QScrollArea* ClavierVar::getScrollableClavier() { return scrollArea; }

