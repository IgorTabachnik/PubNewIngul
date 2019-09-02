#include "settingmenu.h"
#include "ui_settingmenu.h"

SettingMenu::SettingMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingMenu)
{
    ui->setupUi(this);
    InitEvents();
}

SettingMenu::~SettingMenu()
{
    delete ui;

}

void SettingMenu::InitLists()
{

    /*pause buttons*/
    pause_buttons.append(ui->pushButton);
    pause_buttons.append(ui->pushButton_2);

    /*colors buttons*/
    color_buttons.append(ui->colorblack_rb);
    color_buttons.append(ui->colorblue_rb);
    color_buttons.append(ui->colorgreen_rb);
    color_buttons.append(ui->colorsea_rb);
    color_buttons.append(ui->colorred_rb);
    color_buttons.append(ui->colorpurple_rb);
    color_buttons.append(ui->colorhacky_rb);
    color_buttons.append(ui->colorgrey_rb);
    color_buttons.append(ui->colordgrey_rb);
    color_buttons.append(ui->colordblue_rb);
    color_buttons.append(ui->colorlgreen_rb);
    color_buttons.append(ui->colorlsea_rb);
    color_buttons.append(ui->colorred_rb_2);
    color_buttons.append(ui->colorpurple_rb);

}

void SettingMenu::InitEvents()
{
    connect(ui->p10,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p15,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p20,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p25,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p30,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p40,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p50,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p75,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p100,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p200,&QPushButton::clicked,this,&SettingMenu::TimeCallback);
    connect(ui->p300,&QPushButton::clicked,this,&SettingMenu::TimeCallback);

    connect(ui->scale1,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale2,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale3,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale4,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale5,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale6,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale7,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale8,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale9,&QPushButton::clicked,this,&SettingMenu::SizeCallback);
    connect(ui->scale10,&QPushButton::clicked,this,&SettingMenu::SizeCallback);

    connect(ui->velocity1,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity2,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity3,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity4,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity5,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity6,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity7,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity8,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity9,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);
    connect(ui->velocity10,&QPushButton::clicked,this,&SettingMenu::VelocityCallback);

    connect(ui->count6,&QPushButton::clicked,this,&SettingMenu::TargetsCallback);
    connect(ui->count8,&QPushButton::clicked,this,&SettingMenu::TargetsCallback);
    connect(ui->count10,&QPushButton::clicked,this,&SettingMenu::TargetsCallback);
    connect(ui->count30,&QPushButton::clicked,this,&SettingMenu::TargetsCallback);
    connect(ui->count100,&QPushButton::clicked,this,&SettingMenu::TargetsCallback);

    connect(ui->cshoots6,&QPushButton::clicked,this,&SettingMenu::ShotsCallback);
    connect(ui->cshoots8,&QPushButton::clicked,this,&SettingMenu::ShotsCallback);
    connect(ui->cshoots10,&QPushButton::clicked,this,&SettingMenu::ShotsCallback);
    connect(ui->cshoots20,&QPushButton::clicked,this,&SettingMenu::ShotsCallback);
    connect(ui->cshoots30,&QPushButton::clicked,this,&SettingMenu::ShotsCallback);
    connect(ui->cshoots100,&QPushButton::clicked,this,&SettingMenu::ShotsCallback);

    connect(ui->pushButton,&QPushButton::clicked,this,&SettingMenu::PauseCallback);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&SettingMenu::PauseCallback);

    connect(ui->pushButton_4,&QPushButton::clicked,this,&SettingMenu::SizeChangeCallback);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&SettingMenu::SizeChangeCallback);

    connect(ui->pushButton_5,&QPushButton::clicked,this,&SettingMenu::TimeChangeCallback);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&SettingMenu::TimeChangeCallback);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&SettingMenu::TimeChangeCallback);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&SettingMenu::TimeChangeCallback);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&SettingMenu::TimeChangeCallback);
    connect(ui->pushButton_10,&QPushButton::clicked,this,&SettingMenu::TimeChangeCallback);
}

void SettingMenu::VelocityCallback()
{
    QPushButton* btn = static_cast<QPushButton*>(sender());
    uint16_t num = 0;

    if(btn == ui->velocity1) num = 1;
    else if(btn == ui->velocity2) num = 2;
    else if(btn == ui->velocity3) num = 3;
    else if(btn == ui->velocity4) num = 4;
    else if(btn == ui->velocity5) num = 5;
    else if(btn == ui->velocity6) num = 6;
    else if(btn == ui->velocity7) num = 7;
    else if(btn == ui->velocity8) num = 8;
    else if(btn == ui->velocity9) num = 9;
    else if(btn == ui->velocity10) num = 10;

    ui->velocity_edit->setText(QString::number(num));
}

void SettingMenu::SizeCallback()
{
    QPushButton* btn = static_cast<QPushButton*>(sender());
    uint16_t num = 0;

    if(btn == ui->scale1) num = 1;
    else if(btn == ui->scale2) num = 2;
    else if(btn == ui->scale3) num = 3;
    else if(btn == ui->scale4) num = 4;
    else if(btn == ui->scale5) num = 5;
    else if(btn == ui->scale6) num = 6;
    else if(btn == ui->scale7) num = 7;
    else if(btn == ui->scale8) num = 8;
    else if(btn == ui->scale9) num = 9;
    else if(btn == ui->scale10) num = 10;

    ui->scale_edit->setText(QString::number(num));
}

void SettingMenu::TimeCallback()
{
    QPushButton* btn = static_cast<QPushButton*>(sender());
    uint16_t num = 0;

    if(btn == ui->p10) num=10;
    else if(btn == ui->p15) num=15;
    else if(btn == ui->p20) num = 20;
    else if(btn == ui->p25) num = 25;
    else if(btn == ui->p30) num = 30;
    else if(btn == ui->p40) num = 40;
    else if(btn == ui->p50) num = 50;
    else if(btn == ui->p75) num = 75;
    else if(btn == ui->p100) num = 100;
    else if(btn == ui->p200) num = 200;
    else if(btn == ui->p300) num = 300;

    ui->time_edit->setText(QString::number(num));
}

void SettingMenu::TargetsCallback()
{
    QPushButton* btn = static_cast<QPushButton*>(sender());
    uint16_t num = 0;

    if(btn == ui->count6) num=6;
    else if(btn == ui->count8) num=8;
    else if(btn == ui->count10) num=10;
    else if(btn == ui->count30) num=30;
    else if(btn == ui->count100) num=100;

    ui->count_edit->setText(QString::number(num));
}

void SettingMenu::ShotsCallback()
{
    QPushButton* btn = static_cast<QPushButton*>(sender());
    uint16_t num = 0;

    if(btn == ui->cshoots6) num=6;
    else if(btn == ui->cshoots8) num=8;
    else if(btn == ui->cshoots10) num=10;
    else if(btn == ui->cshoots20) num=20;
    else if(btn == ui->cshoots30) num=30;
    else if(btn == ui->cshoots100) num=100;

    ui->countshoots_edit->setText(QString::number(num));
}

void SettingMenu::PauseCallback()
{
    QPushButton* btn = static_cast<QPushButton*>(sender());

    uint32_t num = ui->pause_edit->text().toUInt();

    if(btn == ui->pushButton) num=num>0?num-1:0;
    else if(btn == ui->pushButton_2) num=num<500?num+1:500;

    ui->pause_edit->setText(QString::number(num));
}

void SettingMenu::SizeChangeCallback()
{
    QPushButton* btn = static_cast<QPushButton*>(sender());

    uint32_t num = ui->lineEdit->text().toUInt();

    if(btn == ui->pushButton_4) num=num>0?num-1:0;
    else if(btn == ui->pushButton_3) num=num<500?num+1:500;

    ui->lineEdit->setText(QString::number(num));
}

void SettingMenu::TimeChangeCallback()
{
    QPushButton* btn = static_cast<QPushButton*>(sender());

    uint32_t num = ui->lineEdit_2->text().toUInt();

    if(btn == ui->pushButton_5) num=num>9?num-10:0;
    else if(btn == ui->pushButton_6) num=num>4?num-5:0;
    else if(btn == ui->pushButton_7) num=num>0?num-1:0;
    else if(btn == ui->pushButton_8) num=num<500?num+1:500;
    else if(btn == ui->pushButton_9) num=num<495?num+5:500;
    else if(btn == ui->pushButton_10) num=num<490?num+10:500;

    ui->lineEdit_2->setText(QString::number(num));
}
