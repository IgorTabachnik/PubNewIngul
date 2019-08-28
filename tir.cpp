#include "tir.h"
#include "ui_tir.h"
#include <QThread>
#include <QSpinBox>
#include <QSlider>
#include <QtMath>
//#include <QRect>
//#include <QDebug>

Tir::Tir(int updateInterval, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tir)
{
    QRandomGenerator rand;
    startTimer(updateInterval);
    ui->setupUi(this);

    ui->red_slider->setValue(target.current_color.red());
    ui->green_slider->setValue(target.current_color.green());
    ui->blue_slider->setValue(target.current_color.blue());

    connect(ui->red_slider,&QSlider::valueChanged,this,&Tir::ChangeColor);
    connect(ui->green_slider,&QSlider::valueChanged,this,&Tir::ChangeColor);
    connect(ui->blue_slider,&QSlider::valueChanged,this,&Tir::ChangeColor);

}

Tir::~Tir()
{
    delete ui;
}

void Tir::GeneratePoints(Target2* tgt)
{
    QRandomGenerator rand(QTime::currentTime().msec());
    QList<QPointF> new_points;
    qreal x_zero,y_zero;
    switch(tgt->anim_type)
    {
    case ANIM_SQUARE:
    case ANIM_ZOOM:
        for(uint i = 0;i<(rand.generate()%7)+2;++i)
        {
            new_points.append(QPointF(rand.generate()%this->geometry().width(),rand.generate()%this->geometry().height()));
        }
        tgt->SetMovements(new_points);
        tgt->StartAnimation();
    break;

    case ANIM_PARABOLA:
        x_zero = rand.generate()%(this->geometry().width()-20) + 20;
        y_zero = this->geometry().height()/2 + rand.generate()%80;
        //function: y = -(x-x_zero)^2 + y_zero;
        for(qreal i = 0;i<150;i+=1)
        {
            if(i == 0.0) new_points.append(QPointF(x_zero,y_zero));
            else
            {
                new_points.append(QPointF(x_zero-i,qPow(i,2)/10.0+y_zero));
                new_points.prepend(QPointF(x_zero+i,qPow(-i,2)/10.0+y_zero));
            }
        }
        tgt->SetMovements(new_points);
        tgt->StartAnimation();
    break;

    case ANIM_STATIC:
        tgt->setGeometry(rand.generate()%this->geometry().width(),rand.generate()%this->geometry().height(),tgt->width(),tgt->height());
        tgt->show();

    default:
        break;
    }

}

void Tir::Deleter(Target2* tgt)
{
    targets2.removeOne(tgt);
    tgt->close();
    tgt->deleteLater();
    delete tgt;
}

bool Tir::event(QEvent* event)
{
    switch(event->type())
    {

        case QEvent::MouseButtonRelease:
        {
            event->accept();
            QMouseEvent *evt = static_cast<QMouseEvent*>(event);
            if(evt->button() == Qt::MouseButton::RightButton) CreateTarget();
        }
        return true;

        default:
        return QWidget::event(event);
    }
}

void Tir::CreateTarget()
{
    targets2.append(new Target2(this));
    targets2.last()->LoadTexture(&target.torso);
    targets2.last()->SetAnimationType(ANIM_TYPE::ANIM_STATIC);
    targets2.last()->SetSize(100);
    //points fo animation
    GeneratePoints(targets2.last());
    connect(ui->speed,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),targets2.last(),&Target2::SetSpeed);
    connect(targets2.last(),&Target2::DeleteHandler,this,&Tir::Deleter);
    connect(targets2.last(),&Target2::AnimationEnd,this,&Tir::GeneratePoints);
    connect(targets2.last(),&Target2::ZoneHandler,this,&Tir::ZoneShow);
}

void Tir::ZoneShow(uint8_t zone)
{
    ui->zone_label->setText("Zone: " + QVariant(zone).toString());
}

void Tir::ChangeColor()
{
    target.ChangeColor(QColor(ui->red_slider->value(),ui->green_slider->value(),ui->blue_slider->value()));
}

