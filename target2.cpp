#include "target2.h"
#include <QtSvg>

#define PIXELS_PER_SPEED 500

Target2::Target2(TargetInfo *t_info, QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_Hover);
    this->t_info = t_info;
    anim = new QPropertyAnimation(this,"pos");
    QList<QString> prop_name;
    for(int i = 0;i<this->metaObject()->propertyCount();++i)
    {
        prop_name.append(this->metaObject()->property(i).name());
    }
    anim->setDuration(1000);
    anim->setEasingCurve(QEasingCurve::Linear);
    curr_speed = 1000;
    percent = 40;
    this->setGeometry(0,0,t_info->curr_target.texture.size().width()*percent/100,t_info->curr_target.texture.size().height()*percent/100);
    setMask(t_info->curr_target.mask.scaled(this->size()));
}

void Target2::SetSize(int percent)
{

    if(anim->state() == QAbstractAnimation::State::Running) anim->pause();

    this->percent = percent;
    this->setGeometry(this->geometry().x(),this->geometry().y(),t_info->curr_target.texture.size().width()*percent/100,t_info->curr_target.texture.size().height()*percent/100);
    setMask(t_info->curr_target.mask.scaled(this->size()));
    repaint();
    if(anim->state() == QAbstractAnimation::State::Paused) anim->resume();
}

void Target2::SetMovements(QList<QPointF> move)
{
    disconnect(anim,&QPropertyAnimation::finished,this,&Target2::NextAnimation);
    anim->stop();
    movements.clear();
    foreach(QPointF point,move)
    {
        movements.append(point - QPointF(geometry().width()/2,geometry().height()/2)); //set coordinates to 0 point
    }
    curr_animation = 0;
    connect(anim,&QPropertyAnimation::finished,this,&Target2::NextAnimation);
    anim->setStartValue(geometry());
    anim->setEndValue(movements[0]);
    anim->setDuration(QLineF(geometry().topLeft(),movements[0]).length()*curr_speed/PIXELS_PER_SPEED);
    anim->start();
}

void Target2::SetSpeed(int speed)
{
    curr_speed = speed;
}

void Target2::NextAnimation()
{

    anim->setStartValue(movements[curr_animation]);
    anim->setDuration(QLineF(movements[curr_animation],movements[(curr_animation+1)%movements.length()]).length()*curr_speed/PIXELS_PER_SPEED);
    curr_animation++;
    if(curr_animation == movements.length())
    {
        anim->stop();
        emit this->TargetEndSignal();
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
    //QSvgRenderer rend(QString(":/media/Circles.svg"));
    //rend.render(&painter);
    //painter.drawPixmap(0,0,target->texture);
    painter.drawPixmap(0, 0, this->width(), this->height(), t_info->curr_target.texture);

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
