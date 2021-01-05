#ifndef QCOMPUTER_H_
#define QCOMPUTER_H_
#include <QChar>
#include <QDebug>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTabWidget>
#include <QTableWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>
#include <iostream>

#include "ClavierVar.h"
#include "Layout.h"
#include "ComputerException.h"
#include "Controller.h"
#include "Item.h"
#include "Literal.h"
#include "LiteralManager.h"
#include "Pile.h"

class QComputer : public QWidget {
  Q_OBJECT

  QLineEdit* message;   // Barre de message pour l'utilisateur.
  QLineEdit* commande;  // Barre de commande affichant la suite d'opérandes en
                        // train d'être saisies.
  QTableWidget* vue_pile;  // Panel affichant X derniers éléments de la pile.
  QGroupBox* wClavier;     // Clavier cliquable
  ClavierVar& wClavierVar =
      ClavierVar::GetInstance();  // clavier cliquable variables et programmes
  QVBoxLayout* vue_principale;  // layout de la vue principale (message commande
                                // vue pile wClavier wclavierVar)

  QVBoxLayout* vue_parametre;  // layout de la vue paramatre
  VariableLayout& wVariable = VariableLayout::GetInstance();   // layout de la vue gestion des variables
  ProgramLayout& wProgramme = ProgramLayout::GetInstance();  // layout de la vue gestion des programmes
  QSpinBox* spinBox; // spin box pour la vue paramatre.

  QVBoxLayout* wMenu;  // fenêtre

  Pile* pile;
  Controller* controleur;

  size_t nb_pile_param = 5;

  int increasedSize = 0;

 public:
  explicit QComputer(QWidget* parent = nullptr);
  bool checkInput(QChar input);
  void setCommande(QString& text);
  QString getMessage() const;
 public slots:
  void refresh();
  void getNextCommande();
  void onClick();
  void modifyPileParam();
};



#endif  // QCOMPUTER_H
