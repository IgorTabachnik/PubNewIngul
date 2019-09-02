#ifndef SETTINGMENU_H
#define SETTINGMENU_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QRadioButton>

namespace Ui {
class SettingMenu;
}

struct SettingParams
{
    SettingParams() {}
    QColor color;


};

class SettingMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SettingMenu(QWidget *parent = nullptr);
    ~SettingMenu();
    SettingParams GetParams();

private:
    Ui::SettingMenu *ui;
    void InitEvents();
    QColor GetColor();

private slots:
    void TimeCallback();
    void SizeCallback();
    void VelocityCallback();
    void TargetsCallback();
    void ShotsCallback();
    void PauseCallback();
    void SizeChangeCallback();
    void TimeChangeCallback();

signals:
    void ApplySignal();
};

#endif // SETTINGMENU_H
