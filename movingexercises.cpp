#include "movingexercises.h"
#include "ui_movingexercises.h"
#include "iostream"
#include<QMessageBox>
#define path1 ":/new/prefix1/menu/ingul2.png"
#define path2 ":/new/prefix1/menu/ingul.png"
MovingExercises::MovingExercises(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MovingExercises)
{
    ui->setupUi(this);
    ui->listWidget->setStyleSheet(
                "QListWidget{"
                "background-image: url(:/new/prefix1/menu/sky.jpg);"
                "padding:15px;"
                "}"
                "QListWidget::item {"
                "color:black;"

                "background-color: transparent;"
                "}"
                "QListWidget::item:selected {"
                "background-color: rgba(0,0,100,0.2);"
                "}");

}

MovingExercises::~MovingExercises()
{
    delete ui;
}

void MovingExercises::CheckStatic()
{
    ui->listWidget->clear();
    QListWidgetItem * item1 = new QListWidgetItem(QIcon(path1),"2 Chest Targets");
    ui->listWidget->addItem(item1);
    QListWidgetItem * item2 = new QListWidgetItem(QIcon(path1),"3 Chest Targets");
    ui->listWidget->addItem(item2);
      QListWidgetItem * item3 = new QListWidgetItem(QIcon(path1),"4 Chest Targets");
    ui->listWidget->addItem(item3);
      QListWidgetItem * item4 = new QListWidgetItem(QIcon(path1),"5 Chest Targets");
    ui->listWidget->addItem(item4);
      QListWidgetItem * item5 = new QListWidgetItem(QIcon(path2),"3 Circle Targets");
    ui->listWidget->addItem(item5);
    QListWidgetItem * item6 = new QListWidgetItem(QIcon(path2),"4 Circle Targets");
    ui->listWidget->addItem(item6);
    QListWidgetItem * item7 = new QListWidgetItem(QIcon(path2),"5 Circle Targets");
    ui->listWidget->addItem(item7);
    QListWidgetItem * item8 = new QListWidgetItem(QIcon(path1),"2 Body Targets");
    ui->listWidget->addItem(item8);
    QListWidgetItem * item9 = new QListWidgetItem(QIcon(path1),"3 Body Targets");
    ui->listWidget->addItem(item9);
    QListWidgetItem * item10= new QListWidgetItem(QIcon(path1),"4 Body Targets");
    ui->listWidget->addItem(item10);
    QListWidgetItem * item11 = new QListWidgetItem(QIcon(path2),"5 Chest + Time");
    ui->listWidget->addItem(item11);
   QListWidgetItem * item12 = new QListWidgetItem(QIcon(path2),"5 Body + Time");
    ui->listWidget->addItem(item12);
}

void MovingExercises::CheckMoving()
{
    ui->listWidget->clear();
     QListWidgetItem * item1 = new QListWidgetItem(QIcon(path1),"Circle on Waterfall");
    ui->listWidget->addItem(item1);
     QListWidgetItem * item2 = new QListWidgetItem(QIcon(path1),"Flying sauser");
    ui->listWidget->addItem(item2);
    QListWidgetItem * item3 = new QListWidgetItem(QIcon(path1),"2 Flying sauser");
    ui->listWidget->addItem(item3);
    QListWidgetItem * item4 = new QListWidgetItem(QIcon(path1),"3 Flying sauser");
    ui->listWidget->addItem(item4);
    QListWidgetItem * item5= new QListWidgetItem(QIcon(path1),"3 Sausers with  Reflection");
    ui->listWidget->addItem(item5);
    QListWidgetItem * item6 = new QListWidgetItem(QIcon(path1),"2 Appearing Chest");
    ui->listWidget->addItem(item6);
    QListWidgetItem * item7 = new QListWidgetItem(QIcon(path2),"Portrait in Town");
    ui->listWidget->addItem(item7);
     QListWidgetItem * item8 = new QListWidgetItem(QIcon(path2),"2 Appearing with different color");
    ui->listWidget->addItem(item8);
      QListWidgetItem * item9 = new QListWidgetItem(QIcon(path1),"2 Circle at the same time");
    ui->listWidget->addItem(item9);
     QListWidgetItem * item10 = new QListWidgetItem(QIcon(path1),"4 Appearing Chest Targets");
    ui->listWidget->addItem(item10);
    QListWidgetItem * item11 = new QListWidgetItem(QIcon(path1),"4 Targets with knockout(little)");
    ui->listWidget->addItem(item11);
    QListWidgetItem * item12 = new QListWidgetItem(QIcon(path1),"4 Targets with knockout(middle)");
    ui->listWidget->addItem(item12);
     QListWidgetItem * item13 = new QListWidgetItem(QIcon(path1),"4 Targets with knockout(big)");
    ui->listWidget->addItem(item13);
    QListWidgetItem * item14 = new QListWidgetItem(QIcon(path1),"2 Groups of circle targets");
    ui->listWidget->addItem(item14);
    QListWidgetItem * item15= new QListWidgetItem(QIcon(path2),"Stand shooting");
    ui->listWidget->addItem(item15);
     QListWidgetItem * item16= new QListWidgetItem(QIcon(path2),"Silhouets approaching");
    ui->listWidget->addItem(item16);
     QListWidgetItem * item17= new QListWidgetItem(QIcon(path2),"4 Targets with knockout(little)");
    ui->listWidget->addItem(item17);
     QListWidgetItem * item18= new QListWidgetItem(QIcon(path2),"Silhouets outgoing");
    ui->listWidget->addItem(item18);
    QListWidgetItem * item19= new QListWidgetItem(QIcon(path2),"Silhouets running");
    ui->listWidget->addItem(item19);

}

void MovingExercises::ChoiceStatic()
{
//switch (ui->listWidget->children();){
//case(1):                                                              //Метод выбора из списка для статика
//    QMessageBox::information(this,"kek","1");
//case(2):
//    QMessageBox::information(this,"kek","2");
}


void MovingExercises::ChoiceMoving()                                    //Метод выбора из спмска для мовинга
{

}
