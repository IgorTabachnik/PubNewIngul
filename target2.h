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

    explicit Target2(QWidget *parent = nullptr);
    void LoadTexture(TargetImage *target);
    void SetMovements(QList<QPointF>);


private:
    bool event(QEvent* event);
    void paintEvent(QPaintEvent* event);
    TargetImage *target;
    QList<QPointF> bullets;
    QList<QRectF> movements;
    QPropertyAnimation *anim;
    uint16_t curr_animation;
    uint16_t curr_speed;

signals:

public slots:
    void NextAnimation();
    void SetSpeed(int speed);
};

#endif // TARGET2_H
