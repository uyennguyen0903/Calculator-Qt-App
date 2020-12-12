#ifndef QCOMPUTER_H_
#define QCOMPUTER_H_

#include <QDebug>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QTableWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include "ComputerException.h"
#include "Controller.h"
#include "Item.h"
#include "Literal.h"
#include "LiteralManager.h"
#include "Pile.h"

class QComputer : public QWidget {
  Q_OBJECT
  QLineEdit* message_;   // Barre de message pour l'utilisateur.
  QLineEdit* commande_;  // Barre de commande affichant la suite d'opérandes en
                         // train d'être saisies.
  QTableWidget* vue_pile_;  // Panel affichant X derniers éléments de la pile.
  QHBoxLayout* clavier_;    // Clavier cliquable.
  QVBoxLayout* couche_;     // Servir à aligner tous les objets précédents.
  Pile* pile_;
  Controller* controller_;

 public:
  explicit QComputer(QWidget* parent = nullptr);

 public slots:
  void Refresh();

  void GetNextCommande();
  void OnClick();
};

#endif  // QCOMPUTER_H_
