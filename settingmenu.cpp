#include "settingmenu.h"
#include "ui_settingmenu.h"

SettingMenu::SettingMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingMenu)
{
    ui->setupUi(this);
}

SettingMenu::~SettingMenu()
{
    delete ui;
}
