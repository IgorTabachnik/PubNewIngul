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
    uint16_t shot_time;
    uint16_t size;
    uint16_t velocity;
    uint16_t max_targets;
    uint16_t max_shots;
    uint16_t pause;
    uint16_t size_change;
    uint16_t time_change;
    uint16_t difficulty_change;

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
