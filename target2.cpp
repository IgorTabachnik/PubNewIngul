#include "target2.h"

Target2::Target2(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_Hover);
    //setAttribute(Qt::WA_TranslucentBackground);
    LoadImage();
}

void Target2::LoadImage()
{
    this->img.load(":/media/Target_green.png");
}

void Target2::LoadTexture(target_type target)
{
    QRect text;
    float x, y, w, h;
    switch (target) {
        case circle:
            text.setX(110);//x = 110;
            text.setY(90);//y = 90;
            text.setWidth(415);//w = 415;
            text.setHeight(415);// = 415;
            break;
        case chest:
            x = 100;
            y = 690;
            w = 425;
            h = 415;
            break;
        case torso:
            x = 878;
            y = 106;
            w = 326;
            h = 985;
            break;
        case body:
            text.setX(1470);//x = 1470;
            text.setY(142);//y = 142;
            text.setWidth(383);//w = 383;
            text.setHeight(1383);// = 1383;
            break;
    }

    //this->texture = img.copy(x, y, w, h);
    this->texture = img.copy(text).scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    mask = texture.createMaskFromColor(QColor(0,0,0,0));
    setMask(mask);
}

void Target2::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    QColor red("#ff0000");
    //painter.setBrush(QBrush(red,Qt::SolidPattern));
    //painter.setPen(QPen(Qt::red,1,Qt::SolidPattern));
    //painter.drawEllipse(0,0,this->width(),height());
    painter.drawPixmap(0, 0, this->width(), this->height(), texture);
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
        case QEvent::HoverEnter:
            LoadTexture(circle);
            event->accept();
        return true;

        case QEvent::HoverLeave:
            LoadTexture(body);
            event->accept();
        return true;

        default:
        return QWidget::event(event);
    }

}
