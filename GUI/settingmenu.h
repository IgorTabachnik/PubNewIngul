#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QRadioButton>

namespace Ui {
class SettingMenu;
}

class SettingMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingMenu(QWidget *parent = nullptr);
    ~SettingMenu();
    QList<QPushButton*> pause_buttons;
    QList<QRadioButton*> color_buttons;
    QList<QPushButton*> system_buttons; //go del exit
    QList<QPushButton*> size_change_buttons;

private:
    Ui::SettingMenu *ui;
    void InitLists();
    void InitEvents();

private slots:
    void TimeCallback();
    void SizeCallback();
    void VelocityCallback();
    void TargetsCallback();
    void ShotsCallback();
    void PauseCallback();
    void SizeChangeCallback();
    void TimeChangeCallback();
};

#endif // SETTINGMENU_H
