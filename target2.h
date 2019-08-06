#ifndef TARGET2_H
#define TARGET2_H

#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QBitmap>
#include <QPropertyAnimation>
#include "target_info.h"

class Target2 : public QWidget
{
    Q_OBJECT
public:

    explicit Target2(TargetInfo *t_info, QWidget *parent = nullptr);
    void SetMovements(QList<QPointF>);



private:
    bool event(QEvent* event);
    void paintEvent(QPaintEvent* event);
    TargetInfo* t_info;
    QList<QPointF> bullets;
    QList<QPointF> movements;
    QPropertyAnimation *anim;
    uint16_t curr_animation;
    uint16_t curr_speed;
    QPixmap pixmap;
    uint8_t percent;

signals:
    void TargetEndSignal();

public slots:
    void NextAnimation();
    void SetSpeed(int speed);
    void SetSize(int percent);
};

#endif // TARGET2_H
