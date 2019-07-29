#ifndef TIR_H
#define TIR_H

#include <QApplication>
#include <QCursor>
#include <QLabel>
#include <QList>
#include <QPainter>
#include <QTimer>
#include <QWidget>
#include "bullet_info.h"
#include "target.h"

namespace Ui {
class Tir;
}

class Tir : public QWidget {
  Q_OBJECT

 public:
  explicit Tir(int updateInterval = 33, QWidget *parent = nullptr);
  ~Tir() override;
  void AddTargetsChest(int countOfTargets);
  void AddTargetsCircle(int countOfTargets);
  void AddTargetsTorso(int countOfTargets);
  void AddTargetsBody(int countOfTargets);
public slots:
  void ChangePos();

private slots:
  void on_pushButton_clicked();

private:
  QTimer * timer ;
  Ui::Tir *ui;
  QList<Target> targets;
  QList<int> focused_targets;
  QList<BulletInfo> bullets;
  int countOfTargets_;
  void timerEvent(QTimerEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;
  void paintEvent(QPaintEvent *event) override;
   QBrush * brush;
   QPalette * palette;
};

#endif  // TIR_H
