#include "choicewindow.h"
#include "ui_choicewindow.h"

ChoiceWindow::ChoiceWindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::ChoiceWindow) {
  ui->setupUi(this);
}

ChoiceWindow::~ChoiceWindow() { delete ui; }

void ChoiceWindow::on_run_pbtn_clicked() {
  /*if (ui->two_chest_btn->isChecked()) {
    app = new Tir;
    app->AddTargetsChest(2);
    app->show();
  } else if (ui->tree_chest_btn->isChecked()) {
    app = new Tir;
    app->AddTargetsChest(3);
    app->show();
  } else if (ui->four_chest_btn->isChecked()) {
    app = new Tir;
    app->AddTargetsChest(4);
    app->show();
  } else if (ui->tw_circle_btn->isChecked()) {
    app = new Tir;
    app->AddTargetsCircle(2);
    app->show();

  } else if (ui->tree_circle_btn->isChecked()) { app = new Tir;
      app->AddTargetsCircle(3);
      app->show();
  } else if (ui->four_circle_btn->isChecked()) { app = new Tir;
      app->AddTargetsCircle(4);
      app->show();
  } else if (ui->five_circle_btn->isChecked()) { app = new Tir;
      app->AddTargetsCircle(5);
      app->show();
  } else if (ui->two_body_btn->isChecked()) {  app = new Tir;
      app->AddTargetsTorso(2);
      app->show();
  } else if (ui->tree_body_btn->isChecked()) {  app = new Tir;
      app->AddTargetsTorso(3);
      app->show();
  } else {  app = new Tir;
      app->AddTargetsTorso(4);
      app->show();
  }*/
}
