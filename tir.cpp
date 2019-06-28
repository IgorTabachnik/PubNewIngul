#include "tir.h"
#include "ui_tir.h"
#include <QThread>

Tir::Tir(int updateInterval, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tir)
{

    startTimer(updateInterval);
    ui->setupUi(this);
    hid_detect = false;

    xpos = 0;
    ypos = 0;
}

Tir::~Tir()
{
    delete ui;
}

void Tir::mouseReleaseEvent(QMouseEvent * event )
{
    /*QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    qreal rx = 5;
    qreal ry = 5;
    painter.drawEllipse(QCursor::pos(),rx,ry);*/
    xpos = QCursor::pos().x() - this->x()-8;
    ypos = QCursor::pos().y() - this->y()-30;
    //f = QPointF(QCursor::pos());
    if(hid_detect){
        points_hid.append(QPointF(xpos,ypos));
    }
    repaint();
}

void Tir::timerEvent(QTimerEvent *event)
{
    QPoint p = QCursor::pos();
    ui->posCursor->setText(QString("x = %1; y = %2").arg(p.x()).arg(p.y()));
    ui->WidgetZ->setText(QString("Wx = %1; Wy = %2").arg(this->x()).arg(this->y()));
    double Xw = this->x();
    double Yw = this->y();
    double Xc = p.x();
    double Yc = p.y();
    const double dx = 8;
    const double dy = 30;
    double h = sqrt(pow((Xc-(200+Xw+dx)),2)+pow((Yc-(200+Yw+dy)),2));

    ui->hvalue->setText(QString("h=%1").arg(h));
    if(h<=50){
        hid_detect = true;
        ui->hidDetector->setText("Hid Detect!");
        ui->hidDetector->setStyleSheet("background: #B22222;");
    }else{
        hid_detect = false;
        ui->hidDetector->setText("Shoot Miss!");
        ui->hidDetector->setStyleSheet("background: #432;");
    }
}

void Tir::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    //painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern));
    //painter.drawEllipse(150, 50, 150, 150);

    //painter.setBrush(Qt::NoBrush);
    //painter.drawRect(150,50,150,150);

    painter.setBrush(QBrush(Qt::cyan, Qt::SolidPattern));
    QPointF center(200,200);
    qreal rx = 50;
    qreal ry = 50;
    painter.drawEllipse(center,rx,ry);

    foreach (QPointF p, points_hid) {
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
        painter.drawEllipse(p,2,2);
    }

}
