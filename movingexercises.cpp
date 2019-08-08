#include "movingexercises.h"
#include "ui_movingexercises.h"

MovingExercises::MovingExercises(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MovingExercises)
{
    ui->setupUi(this);
}

MovingExercises::~MovingExercises()
{
    delete ui;
}
