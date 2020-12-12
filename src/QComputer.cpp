#include "QComputer.h"

QComputer::QComputer(QWidget* parent) : QWidget(parent) {
  pile_ = new Pile;
  controller_ = new Controller(LiteralManager::GetInstance(), *pile_);
  // Créer la barre de message pour l'utilisateur.
  message_ = new QLineEdit;
  message_->setReadOnly(true);

  // Créer et customiser la panel de pile.
  vue_pile_ = new QTableWidget(pile_->GetNbDisplay(), 1);
  vue_pile_->horizontalHeader()->setVisible(false);
  vue_pile_->horizontalHeader()->setStretchLastSection(true);

  QStringList labelList;
  for (size_t i = pile_->GetNbDisplay(); i > 0; --i) {
    QString str = QString::number(i);
    labelList << str;
  }
  vue_pile_->setVerticalHeaderLabels(labelList);
  // vue_pile->setDisabled(true);  // Mettre la pile non modiable.

  for (size_t i = 0; i < pile_->GetNbDisplay(); i++) {
    vue_pile_->setItem(i, 0, new QTableWidgetItem(""));
  }

  // Créer la barre de commande.
  commande_ = new QLineEdit;

  // Mettre un titre à la fenêtre.
  setWindowTitle("Comp'UT");

  // Créer les buttons pour les claviers cliquables.
  // Expressions litérales.
  QPushButton* un = new QPushButton("1");
  connect(un, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* deux = new QPushButton("2");
  connect(deux, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* trois = new QPushButton("3");
  connect(trois, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* quatre = new QPushButton("4");
  connect(quatre, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* cinq = new QPushButton("5");
  connect(cinq, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* six = new QPushButton("6");
  connect(six, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* sept = new QPushButton("7");
  connect(sept, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* huit = new QPushButton("8");
  connect(huit, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* neuf = new QPushButton("9");
  connect(neuf, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* zero = new QPushButton("0");
  connect(zero, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* point = new QPushButton(".");
  connect(point, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* paren_ouvrante = new QPushButton("[");
  connect(paren_ouvrante, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* paren_ferrmante = new QPushButton("]");
  connect(paren_ferrmante, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* guillemet_simp = new QPushButton("'");
  connect(guillemet_simp, SIGNAL(clicked()), this, SLOT(OnClick()));

  // Opérandes.
  QPushButton* plus = new QPushButton("+");
  connect(plus, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* moins = new QPushButton("-");
  connect(moins, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* fois = new QPushButton("*");
  connect(fois, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* division = new QPushButton("/");
  connect(division, SIGNAL(clicked()), this, SLOT(OnClick()));

  // Les touches Entrée & Eval.
  QPushButton* entree = new QPushButton("ENTREE");
  connect(entree, SIGNAL(clicked()), this, SLOT(GetNextCommande()));
  QPushButton* eval = new QPushButton("EVAL");
  connect(eval, SIGNAL(clicked()), this, SLOT(OnClick()));

  QHBoxLayout* line0 = new QHBoxLayout;
  line0->addWidget(guillemet_simp);
  line0->addWidget(zero);
  line0->addWidget(point);
  line0->addWidget(entree);

  QHBoxLayout* line1 = new QHBoxLayout;
  line1->addWidget(un);
  line1->addWidget(deux);
  line1->addWidget(trois);
  line1->addWidget(plus);

  QHBoxLayout* line2 = new QHBoxLayout;
  line2->addWidget(quatre);
  line2->addWidget(cinq);
  line2->addWidget(six);
  line2->addWidget(moins);

  QHBoxLayout* line3 = new QHBoxLayout;
  line3->addWidget(sept);
  line3->addWidget(huit);
  line3->addWidget(neuf);
  line3->addWidget(fois);

  QHBoxLayout* line4 = new QHBoxLayout;
  line4->addWidget(eval);
  line4->addWidget(paren_ouvrante);
  line4->addWidget(paren_ferrmante);
  line4->addWidget(division);

  // La 'couche1' contient les chiffres et les opérandes +,-,*,/
  QVBoxLayout* couche1 = new QVBoxLayout;
  couche1->addLayout(line4);
  couche1->addLayout(line3);
  couche1->addLayout(line2);
  couche1->addLayout(line1);
  couche1->addLayout(line0);

  // Opérateurs numériques
  QPushButton* div = new QPushButton("DIV");
  connect(div, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* mod = new QPushButton("MOD");
  connect(mod, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* neg = new QPushButton("NEG");
  connect(neg, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* sq_root = new QPushButton("SQRT");
  connect(sq_root, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* pow = new QPushButton("POW");
  connect(pow, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* exp = new QPushButton("EXP");
  connect(exp, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* ln = new QPushButton("LN");
  connect(ln, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* num = new QPushButton("NUM");
  connect(num, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* den = new QPushButton("DEN");
  connect(den, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* sin = new QPushButton("SIN");
  connect(sin, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* cos = new QPushButton("COS");
  connect(cos, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* tan = new QPushButton("TAN");
  connect(tan, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* arcsin = new QPushButton("ARCSIN");
  connect(arcsin, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* arccos = new QPushButton("ARCCOS");
  connect(arccos, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* arctan = new QPushButton("ARCTAN");
  connect(arctan, SIGNAL(clicked()), this, SLOT(OnClick()));

  QHBoxLayout* line5 = new QHBoxLayout;
  line5->addWidget(neg);
  line5->addWidget(den);
  line5->addWidget(num);

  QHBoxLayout* line6 = new QHBoxLayout;
  line6->addWidget(sq_root);
  line6->addWidget(div);
  line6->addWidget(mod);

  QHBoxLayout* line7 = new QHBoxLayout;
  line7->addWidget(pow);
  line7->addWidget(exp);
  line7->addWidget(ln);

  QHBoxLayout* line8 = new QHBoxLayout;
  line8->addWidget(sin);
  line8->addWidget(cos);
  line8->addWidget(tan);

  QHBoxLayout* line9 = new QHBoxLayout;
  line9->addWidget(arcsin);
  line9->addWidget(arccos);
  line9->addWidget(arctan);

  // La 'couche2' contient les opérateurs numériques.
  QVBoxLayout* couche2 = new QVBoxLayout;
  couche2->addLayout(line5);
  couche2->addLayout(line6);
  couche2->addLayout(line7);
  couche2->addLayout(line8);
  couche2->addLayout(line9);

  // Opérateurs logiques.
  QPushButton* equal = new QPushButton("=");
  connect(equal, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* diff = new QPushButton("!=");
  connect(diff, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* sup = new QPushButton(">");
  connect(sup, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* inf = new QPushButton("<");
  connect(inf, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* et = new QPushButton("AND");
  connect(et, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* ou = new QPushButton("OR");
  connect(ou, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* non = new QPushButton("NOT");
  connect(non, SIGNAL(clicked()), this, SLOT(OnClick()));

  // La 'couche3' contient les opérateurs logiques.
  QHBoxLayout* couche3 = new QHBoxLayout;
  couche3->addWidget(et);
  couche3->addWidget(ou);
  couche3->addWidget(non);
  couche3->addWidget(equal);
  couche3->addWidget(diff);
  couche3->addWidget(sup);
  couche3->addWidget(inf);

  // Opérateurs de manipulation.
  QPushButton* dup = new QPushButton("DUP");
  connect(dup, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* drop = new QPushButton("DROP");
  connect(drop, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* echanger = new QPushButton("SWAP");
  connect(echanger, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* effacer = new QPushButton("CLEAR");
  connect(effacer, SIGNAL(clicked()), this, SLOT(OnClick()));

  // Opérateurs conditionnels et de boucle.
  QPushButton* ift = new QPushButton("IFT");
  connect(ift, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* ifte = new QPushButton("IFTE");
  connect(ifte, SIGNAL(clicked()), this, SLOT(OnClick()));
  QPushButton* tant_que = new QPushButton("WHILE");
  connect(tant_que, SIGNAL(clicked()), this, SLOT(OnClick()));

  // La 'couche4' contient les opérateurs de manipulation et opérateurs
  // conditionnels et de boucle.
  QHBoxLayout* couche4 = new QHBoxLayout;
  couche4->addWidget(ift);
  couche4->addWidget(ifte);
  couche4->addWidget(tant_que);
  couche4->addWidget(dup);
  couche4->addWidget(drop);
  couche4->addWidget(echanger);
  couche4->addWidget(effacer);

  QHBoxLayout* couche12 = new QHBoxLayout;
  couche12->addLayout(couche2);
  couche12->addLayout(couche1);

  QVBoxLayout* clavier_ = new QVBoxLayout;
  clavier_->addLayout(couche4);
  clavier_->addLayout(couche3);
  clavier_->addLayout(couche12);

  // Aligner tous les objets précédents.
  couche_ = new QVBoxLayout;
  couche_->addWidget(message_);
  couche_->addWidget(vue_pile_);
  couche_->addWidget(commande_);
  couche_->addLayout(clavier_);
  setLayout(couche_);

  connect(pile_, SIGNAL(ModifyStatus()), this, SLOT(Refresh()));
  connect(commande_, SIGNAL(ReturnPressed()), this, SLOT(GetNextCommande()));
}

void QComputer::Refresh() {
  message_->setText(pile_->GetMessage());

  for (size_t i = 0; i < pile_->GetNbDisplay(); i++) {
    vue_pile_->item(i, 0)->setText("");
  }

  size_t nb = 0;
  for (Pile::Iterator it = pile_->begin();
       it != pile_->end() && nb < pile_->GetNbDisplay(); ++it) {
    vue_pile_->item(pile_->GetNbDisplay() - nb - 1, 0)->setText((*it).Print());
    nb++;
  }
}

void QComputer::GetNextCommande() {
  QString c = commande_->text();  // On récupère la ligne de commande.
  controller_->Commande(c);
  commande_->clear();
}

void QComputer::OnClick() {
  QPushButton* button = (QPushButton*)sender();
  QString c = commande_->text();  // On récupère la ligne de commande.
  c += button->text();
  commande_->setText(c);
}
