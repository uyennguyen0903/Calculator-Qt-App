#ifndef QCOMPUTER_H_
#define QCOMPUTER_H_
#include <QDebug>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <iostream>

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
  QGroupBox* wClavier;     // Clavier cliquable.
  QVBoxLayout* couche;     // Servir à aligner tous les objets précédents.
  Pile* pile;
  Controller* controleur;

 public:
  explicit QComputer(QWidget* parent = nullptr);
  bool checkInput(QChar input);
 public slots:
  void refresh();
  void getNextCommande();
  void onClick();
};

#endif  // QCOMPUTER_H
