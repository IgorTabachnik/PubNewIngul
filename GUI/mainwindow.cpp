#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
connect(ui->choice_menu,&ChoiceExercises::clickedBtnMoving,ui->exercises,&MovingExercises::CheckMoving);
connect(ui->choice_menu,&ChoiceExercises::clickedBtnStatic,ui->exercises,&MovingExercises::CheckStatic);
connect(ui->choice_menu,&ChoiceExercises::clickedBtnGo,ui->exercises,&MovingExercises::ChoiceMoving);
connect(ui->choice_menu,&ChoiceExercises::clickedBtnGo,ui->exercises,&MovingExercises::ChoiceStatic);
}

//MainWindow::MainWindow(QApplication *app):app();
//{

//}

MainWindow::~MainWindow() { delete ui; }
