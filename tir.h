#ifndef TIR_H
#define TIR_H

#include <QWidget>
#include <QLabel>
#include <QCursor>
#include <QPainter>
#include <QList>
#include <QApplication>
#include <QDebug>
#include "target.h"
#include "bullet_info.h"

namespace Ui {
class Tir;
}

class Tir : public QWidget
{
    Q_OBJECT

public:
    explicit Tir(int updateInterval = 1, QWidget *parent = 0);
    ~Tir();

private:
    Ui::Tir *ui;
    QPolygonF poly;
    QList<Target> targets;
    QList<int> focused_targets;
    QList<BulletInfo> bullets;

    void timerEvent(QTimerEvent *event) override;
    void mouseReleaseEvent(QMouseEvent * event ) override;
    void paintEvent(QPaintEvent* event);

    int case_state;
protected:
    virtual void keyPressEvent(QKeyEvent *event);

};

#endif // TIR_H
