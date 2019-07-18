#ifndef TARGET2_H
#define TARGET2_H

#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QBitmap>
#include <QPropertyAnimation>

class Target2 : public QWidget
{
    Q_OBJECT
public:
    enum target_type { circle, chest, torso, body };

    explicit Target2(QWidget *parent = nullptr);
    void LoadImage();
    void LoadTexture(target_type target);
    void SetMovements(QList<QPointF>);


private:
    target_type type;
    bool event(QEvent* event);
    void paintEvent(QPaintEvent* event);
    QPixmap img;
    QPixmap texture;
    QBitmap mask;
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
