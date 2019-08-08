#include "tir.h"
#include "ui_tir.h"
#include <QThread>
#include <QSpinBox>
#include <QSlider>
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

    QList<QPointF> points;

    for(int i = 0;i<10;++i)
    {
        targets2.append(new Target2(this));
        targets2[i]->setGeometry(300,300,150,150);
        targets2[i]->LoadTexture(&target.svg_test);
        //targets2[i]->LoadTexture(target.targets[rand.generate()%target.targets.length()]);
        points.clear();

        //points fo animation
        for(uint8_t j = 0;j<(rand.generate()%7)+3;++j) points.append(QPointF(rand.generate()%width(),rand.generate()%height()));


        targets2[i]->SetMovements(points);
        connect(ui->speed,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),targets2[i],&Target2::SetSpeed);
    }

}

Tir::~Tir()
{
    delete ui;
}

void Tir::ChangeColor()
{
    target.ChangeColor(QColor(ui->red_slider->value(),ui->green_slider->value(),ui->blue_slider->value()));
}

