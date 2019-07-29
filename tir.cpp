#include "tir.h"
#include <QThread>
#include "ui_tir.h"
//#include <QRect>
//#include <QDebug>
#include <QTimer>
#include <ctime>

Tir::Tir(int updateInterval, QWidget *parent)
    : QWidget(parent), ui(new Ui::Tir) {
  startTimer(updateInterval);
  ui->setupUi(this);
  Tir::showFullScreen();
 palette=new QPalette;
 brush=new QBrush;
 brush->setTextureImage(QImage(":/media/vodopad.jpg"));
 palette->setBrush(QPalette::Window,*brush);
 this->setPalette(*palette);
  //  targets.append(Target(Target::body, QPoint(100, 100), QPoint(150, 150)));

  //  targets.append(Target(Target::circle, QPointF(50, 50), QPointF(150,
  //  150)));
  timer=new QTimer;
  srand (time(NULL));
  connect(timer, SIGNAL(timeout()), this, SLOT(ChangePos()));
    timer->start(2000);

}

Tir::~Tir() { delete ui; }

void Tir::AddTargetsTorso(int countOfTargets) {
  for (int count = 0; count < countOfTargets; ++count) {
    targets.append(Target(Target::torso, QPoint(rand()%100+100+70, rand()%100+100), QPoint(150, 150)));
  }
}

void Tir::AddTargetsBody(int countOfTargets) {
  for (int count = 0; count < countOfTargets; ++count) {
    targets.append(Target(Target::body, QPoint(rand()%100+100+70, rand()%100), QPoint(150, 150)));
  }
}


void Tir::ChangePos()
{
 for (auto i: targets){
     i.SetTargetPosition();
 }
//  repaint();
}

void Tir::AddTargetsChest(int countOfTargets) {
  for (int count = 0; count < countOfTargets; ++count) {
    targets.append(Target(Target::chest, QPoint(rand()%800+70, rand()%100), QPoint(150, 150)));
  }
}

void Tir::AddTargetsCircle(int countOfTargets) {
  for (int count = 0; count < countOfTargets; ++count) {
    targets.append(Target(Target::circle, QPoint(rand()%800+70, rand()%100), QPoint(150, 150)));
  }
}

void Tir::mouseReleaseEvent(QMouseEvent *) {
  if (this->focused_targets.length() > 0) {
    QPointF pos = this->mapFromGlobal(QCursor::pos());
    for (int i = 0; i < this->focused_targets.length(); i++) {
      this->bullets.append(
          BulletInfo(this->targets[this->focused_targets[i]], pos));
    }
  }
}

void Tir::timerEvent(QTimerEvent *) {
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

void Tir::paintEvent(QPaintEvent *) {
  QPainter painter(this);

  for (int i = 0; i < this->targets.length(); i++) {
    this->targets[i].draw(painter);
  }

  painter.setPen(Qt::NoPen);
  painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));

  for (int i = 0; i < this->bullets.length(); i++) {
    if (this->bullets[i].get_target_info()->visible == true) {
      painter.drawEllipse(this->bullets[i].get_position() - QPointF(1.5f, 1.5f),
                          3, 3);
    }
  }
}

void Tir::on_pushButton_clicked()
{
    Tir::close();
}

