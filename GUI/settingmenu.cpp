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

void SettingMenu::InitLists()
{
    for(int i = 0;i<ui->splitter_5->children().length();++i)
    {
    }
}
