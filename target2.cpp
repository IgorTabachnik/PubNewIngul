#include "target2.h"
#include <QtSvg>

#define PIXELS_PER_SPEED 500

Target2::Target2(QWidget *parent) : QWidget(parent)
{
    //setAttribute(Qt::WA_Hover);
    anim = new QPropertyAnimation(this,"geometry");
    anim->setDuration(1000);
    anim->setEasingCurve(QEasingCurve::Linear);
    curr_speed = 1000;
    this->hide();
}

void Target2::SetSize(uint8_t percent)
{

}

void Target2::SetAnimationType(ANIM_TYPE anim)
{
    this->anim_type = anim;
}

void Target2::LoadTexture(TargetImage *target)
{
    this->target = target;
    setMask(target->mask.scaled(width(),height()));

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
    connect(anim,&QPropertyAnimation::finished,this,&Target2::NextAnimation);

}

void Target2::StartAnimation()
{
    anim->setStartValue(movements[0]);
    anim->setEndValue(movements[1]);
    curr_animation = 1;
    anim->setDuration(QLineF(geometry().topLeft(),movements[0].topLeft()).length()*curr_speed/PIXELS_PER_SPEED);
    anim->start();
    this->show();
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
    if(curr_animation == movements.length())
    {
        this->hide();
        anim->stop();
        emit AnimationEnd(this);
    }
    else
    {
        anim->setEndValue(movements[curr_animation]);
        anim->start();
    }
}


void Target2::paintEvent(QPaintEvent *event)
{

    event->accept();
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(), this->height(), target->texture);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));

    for (int i = 0; i < this->bullets.length(); i++)
    {
        painter.drawEllipse(this->bullets[i] - QPointF(1.5, 1.5), 3, 3);
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
            if(evt->button() == Qt::MouseButton::LeftButton)
            {
                for(int i = 0;i<bullets.length();++i)
                {
                    if(bullets[i] == evt->pos()) return true;
                }
                bullets.append(evt->pos());
                repaint();
            }
            else if(evt->button() == Qt::MouseButton::RightButton) emit DeleteHandler(this);
        }
        return true;

        default:
        return QWidget::event(event);
    }

}
