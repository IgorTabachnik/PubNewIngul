#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QWidget>
#include <QList>
#include <QPushButton>

namespace Ui {
class SettingMenu;
}

class SettingMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingMenu(QWidget *parent = nullptr);
    ~SettingMenu();
    QList<QPushButton*> time_buttons;

private:
    Ui::SettingMenu *ui;
    void InitLists();
};

#endif // SETTINGMENU_H
