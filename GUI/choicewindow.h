#ifndef CHOICEWINDOW_H
#define CHOICEWINDOW_H

#include <tir.h>
#include <ui_tir.h>
#include <QWidget>

namespace Ui {
class ChoiceWindow;
}

class ChoiceWindow : public QWidget {
  Q_OBJECT

 public:
  explicit ChoiceWindow(QWidget *parent = 0);
  ~ChoiceWindow();

 private slots:

    void on_run_pbtn_clicked();

private:
  Tir *app;
  Ui::ChoiceWindow *ui;
};

#endif  // CHOICEWINDOW_H
