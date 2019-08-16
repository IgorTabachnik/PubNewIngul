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
    void LoadTexture(TargetImage*);
    void SetMovements(QList<QPointF>);
    void StartAnimation();
    void SetAnimationType(ANIM_TYPE);
    ANIM_TYPE anim_type;


private:
    bool event(QEvent* event);
    void paintEvent(QPaintEvent*);
    void TracePosition();
    TargetImage *target;
    QList<QPointF> bullets;
    QList<QRectF> movements;
    QPropertyAnimation *anim;
    uint16_t curr_animation;
    uint16_t curr_speed;
    QPixmap pixmap;
    uint8_t percent_size;

signals:
    void AnimationEnd(Target2*);
    void DeleteHandler(Target2*);
    void ZoneHandler(uint8_t); //Зона попадания

public slots:
    void NextAnimation();
    void SetSize(uint8_t);
    void SetSpeed(int);
};

#endif // TARGET2_H
