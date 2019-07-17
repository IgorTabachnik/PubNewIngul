#include "tir.h"
#include "ui_tir.h"
#include <QThread>
//#include <QRect>
//#include <QDebug>

Tir::Tir(int updateInterval, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tir)
{
    startTimer(updateInterval);
    ui->setupUi(this);

    targets.append(Target(Target::body, QPointF(50, 50), QPointF(150, 150)));
    targets2.append(new Target2(this));
    targets2[0]->setGeometry(300,300,150,150);
    targets2[0]->LoadTexture(Target2::body);

}

Tir::~Tir()
{
    delete ui;
}

void Tir::mouseReleaseEvent(QMouseEvent *)
{
    if (this->focused_targets.length() > 0) {
        QPointF pos = this->mapFromGlobal(QCursor::pos());
        for (int i = 0; i < this->focused_targets.length(); i++) {
            this->bullets.append(BulletInfo(
                this->targets[this->focused_targets[i]], pos
            ));
        }
    }
}

void Tir::timerEvent(QTimerEvent *)
{
    QPointF cursor = this->mapFromGlobal(QCursor::pos());
    this->focused_targets.clear();

    for (int i = 0; i < this->targets.length(); i++) {
        bool focused = this->targets[i].hid_detected(cursor);
        if (focused) {
            this->focused_targets.append(i);
        }
    }

    this->repaint();
}

void Tir::paintEvent(QPaintEvent *evt)
{
    QPainter painter(this);

    for (int i = 0; i < this->targets.length(); i++) {
        this->targets[i].draw(painter);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));

    for (int i = 0; i < this->bullets.length(); i++) {
        if (this->bullets[i].get_target_info()->visible == true) {
            painter.drawEllipse(this->bullets[i].get_position() - QPointF(1.5f, 1.5f), 3, 3);
        }
    }
    QWidget::paintEvent(evt);
}
