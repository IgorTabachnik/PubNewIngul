#include "target2.h"

Target2::Target2(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_Hover);
    LoadImage();
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

    this->texture = img.copy(text).scaled(width(),height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    mask = texture.createMaskFromColor(QColor(0,0,0,0));
    setMask(mask);
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
