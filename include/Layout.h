#ifndef LAYOUT_H
#define LAYOUT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QStringList>

#include "Atom.h"
#include "Program.h"
using namespace std;

class Layout: public QWidget {
    Q_OBJECT
protected:
    int nb_element=0;
    QList<QString> ids;
    ~Layout();
    Layout(const QString title, const QString contentName);

    Layout(const Layout& programLayout) = delete;
    Layout& operator=(const Layout& programLayout) = delete;
    QVBoxLayout* layout;
    QVBoxLayout* contentBox;
    QLineEdit* message;
    const QString title = "";
    const QString contentName = "";
public:

    void addElement(const QString id, const QString content);
    void deleteElement(const QString id);
    void deletePtr(QObject* obj);
    virtual void extendModify(const QString edit, const QString label) {
        std::ignore = edit;
        std::ignore = label;
        return;
    };
    void sendCommand(const QString edit, const QString label);

public slots:
    void modify();
};

class ProgramLayout: public Layout {
    ~ProgramLayout();
    ProgramLayout() : Layout("Gestion et édition des programmes utilisateurs", "Programme") {}
    ProgramLayout(const ProgramLayout& programLayout) = delete;
    ProgramLayout& operator=(const ProgramLayout& programLayout) = delete;

    // Design Pattern Singleton.
    struct ProgramLayoutHandler {
      ProgramLayout* instance;
      ProgramLayoutHandler() : instance(nullptr) {};
      ~ProgramLayoutHandler() {}
    };

    static ProgramLayoutHandler programLayout_handler_;

public:
    static ProgramLayout& GetInstance();
    static void FreeInstance();
    void extendModify(const QString edit, const QString label);
};

class VariableLayout: public Layout {
    ~VariableLayout();
    VariableLayout() : Layout("Gestion et édition des variables utilisateurs", "Valeur") {};
    VariableLayout(const VariableLayout& variableLayout) = delete;
    VariableLayout& operator=(const VariableLayout& variableLayout) = delete;

    // Design Pattern Singleton.
    struct VariableLayoutHandler {
      VariableLayout* instance;
      VariableLayoutHandler() : instance(nullptr) {};
      ~VariableLayoutHandler() {}
    };

    static VariableLayoutHandler variableLayout_handler_;

public:
    static VariableLayout& GetInstance();
    static void FreeInstance();
    void extendModify(const QString edit, const QString label);
};


#endif // LAYOUT_H
