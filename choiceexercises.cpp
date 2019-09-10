#include "choiceexercises.h"
#include "ui_choiceexercises.h"

ChoiceExercises::ChoiceExercises(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChoiceExercises)
{
    ui->setupUi(this);
    connect(ui->push_btn_go,&QPushButton::clicked,this,&ChoiceExercises::clickedBtnGo);
    connect(ui->push_button_static,&QPushButton::clicked,this,&ChoiceExercises::clickedBtnStatic);
    connect(ui->push_button_moving,&QPushButton::clicked,this,&ChoiceExercises::clickedBtnMoving);
}

ChoiceExercises::~ChoiceExercises()
{
    delete ui;
}
