#ifndef PILE_H_
#define PILE_H_

#include <QObject>
#include <vector>

#include "Item.h"

using namespace std;

class Pile : public QObject {
 private:
  Q_OBJECT;
  vector<Item> items_;
  QString message_;
  size_t nb_display_ = 5;

 public:
  Pile() : message_(""), nb_display_(5){};

  Pile(vector<Item> items, QString message, size_t nb_display)
      : items_(items), message_(message), nb_display_(nb_display){};

  ~Pile() = default;

  void Push(Literal& literal);

  void Pop();

  Literal& Top() const;

  void SetNbDisplay(size_t nb) { nb_display_ = nb; }

  size_t GetNbDisplay() const { return nb_display_; }

  void SetMessage(const QString& message) {
    message_ = message;
    ModifyStatus();
  }

  QString GetMessage() const { return message_; }

  size_t GetPileSize() const { return items_.size(); }

  // Design pattern momento.

  Pile* SaveStatus() const{ return new Pile(items_, message_, nb_display_); }

  void Restore(Pile* const memento);

  // Design pattern iterator.
  class Iterator {
   private:
    vector<Item> items_;

    size_t cur_position_;

    Iterator(vector<Item> items, size_t pos)
        : items_(items), cur_position_(pos){};

    friend class Pile;

   public:
    Literal& operator*() const { return items_[cur_position_].GetLiteral(); }

    bool operator!=(Iterator it) const {
      return it.cur_position_ != cur_position_;
    }

    Iterator& operator++() {
      --cur_position_;
      return *this;
    }
  };

  Iterator begin() { return Iterator(items_, items_.size() - 1); }
  Iterator end() { return Iterator(items_, -1); }

 signals:
  void ModifyStatus();
};

#endif  // PILE_H_
