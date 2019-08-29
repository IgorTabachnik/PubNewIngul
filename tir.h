#ifndef TIR_H
#define TIR_H

#include <QWidget>
#include <QLabel>
#include <QCursor>
#include <QPainter>
#include <QList>
#include <QApplication>
#include "target2.h"
#include "bullet_info.h"
#include "target_info.h"
#include "GUI/settingmenu.h"

namespace Ui {
class Tir;
}

class Tir : public QWidget
{
    Q_OBJECT

public:
    explicit Tir(int updateInterval = 33, QWidget *parent = nullptr);
    ~Tir();

private:
    Ui::Tir *ui;

    QList<Target2*> targets2;
    QList<int> focused_targets;
    TargetInfo target;
    SettingMenu *menu;

    bool event(QEvent*);
    void CreateTarget();

private slots:
    void ChangeColor();
    void GeneratePoints(Target2*);
    void Deleter(Target2*);
    void ZoneShow(uint8_t);

};

#endif // TIR_H
