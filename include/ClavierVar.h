#ifndef CLAVIERVAR_H
#define CLAVIERVAR_H
#include <QDebug>
#include <QGroupBox>
#include <QList>
#include <QWidget>
#include <QScrollArea>

using namespace std;

class ClavierVar : public QWidget {
  QScrollArea* scrollArea;
  int nb_bouton = 0;
  QList<QString> ids;

  ~ClavierVar();
  ClavierVar();
  ClavierVar(const ClavierVar& clavier_var) = delete;
  ClavierVar& operator=(const ClavierVar& clavier_var) = delete;

  // Design Pattern Singleton.
  struct ClavierVarHandler {
    ClavierVar* instance;
    ClavierVarHandler() : instance(nullptr){};
    ~ClavierVarHandler() { delete instance; }
  };

  static ClavierVarHandler clavierVar_handler_;

 public:
  static ClavierVar& GetInstance();
  static void FreeInstance();
  void addButton(QString id);
  QGroupBox* getClavier();
  QScrollArea* getScrollableClavier();
  int getNbBoutons() const {return nb_bouton;}
};

#endif  // CLAVIERVAR_H
