#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QWidget>

namespace Ui {
class SettingMenu;
}

class SettingMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingMenu(QWidget *parent = nullptr);
    ~SettingMenu();

private:
    Ui::SettingMenu *ui;
};

#endif // SETTINGMENU_H
