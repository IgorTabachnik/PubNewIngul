#include "target2.h"

#define PIXELS_PER_SPEED 500

Target2::Target2(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_Hover);
    LoadImage();
    anim = new QPropertyAnimation(this,"geometry");
    anim->setDuration(1000);
    anim->setEasingCurve(QEasingCurve::Linear);
    curr_speed = 1000;
}

void Target2::LoadImage()
{
    this->img.load(":/media/Target_green.png");
}

void Target2::LoadTexture(target_type target)
{
    QRect text;
    switch (target) {
        case circle:
            text.setX(110);//x = 110;
            text.setY(90);//y = 90;
            text.setWidth(415);//w = 415;
            text.setHeight(415);// = 415;
            break;
        case chest:
            text.setX(100);//x = 100;
            text.setY(690);//y = 690;
            text.setWidth(425);//w = 425;
            text.setHeight(415);// = 415;
            break;
        case torso:
            text.setX(878);//x = 878;
            text.setY(106);//y = 106;
            text.setWidth(326);//w = 326;
            text.setHeight(985);//h = 985;
            break;
        case body:
            text.setX(1470);//x = 1470;
            text.setY(142);//y = 142;
            text.setWidth(383);//w = 383;
            text.setHeight(1383);// = 1383;
            break;
    }

    this->texture = img.copy(text).scaled(width(),height()/*,Qt::IgnoreAspectRatio,Qt::SmoothTransformation*/);
    mask = texture.createMaskFromColor(QColor(0,0,0,0));
    setMask(mask);
}

void Target2::SetMovements(QList<QPointF> move)
{
    disconnect(anim,&QPropertyAnimation::finished,this,&Target2::NextAnimation);
    anim->stop();
    movements.clear();
    foreach(QPointF point,move)
    {
        movements.append(QRectF(point - QPointF(geometry().width()/2,geometry().height()/2),geometry().size())); //set coordinates to 0 point
    }
    curr_animation = 0;
    connect(anim,&QPropertyAnimation::finished,this,&Target2::NextAnimation);
    anim->setStartValue(geometry());
    anim->setEndValue(movements[0]);
    anim->setDuration(QLineF(geometry().topLeft(),movements[0].topLeft()).length()*curr_speed/PIXELS_PER_SPEED);
    anim->start();
}

void Target2::SetSpeed(int speed)
{
    curr_speed = speed;
}

void Target2::NextAnimation()
{

    anim->setStartValue(movements[curr_animation]);
    anim->setDuration(QLineF(movements[curr_animation].topLeft(),movements[(curr_animation+1)%movements.length()].topLeft()).length()*curr_speed/PIXELS_PER_SPEED);
    curr_animation++;
    curr_animation%=movements.length();
    anim->setEndValue(movements[curr_animation]);
    anim->start();
}

void Target2::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), texture);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));

    for (int i = 0; i < this->bullets.length(); i++)
    {
        painter.drawEllipse(this->bullets[i] - QPointF(1.5, 1.5), 3, 3);
    }
    switch(event->type())
    {
        default:
        QWidget::paintEvent(event);
        break;
    }
}

bool Target2::event(QEvent* event)
{
    switch(event->type())
    {

        case QEvent::MouseButtonRelease:
        {
            event->accept();
            QMouseEvent *evt = static_cast<QMouseEvent*>(event);
            for(int i = 0;i<bullets.length();++i)
            {
                if(bullets[i] == evt->pos()) return true;
            }
            bullets.append(evt->pos());
            repaint();
        }
        return true;

        default:
        return QWidget::event(event);
    }

}
