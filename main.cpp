#include <QApplication>
#include <QCursor>
#include <QLabel>
#include "choicewindow.h"
#include "mainwindow.h"
#include "tir.h"

// class CursorPosition : public QWidget
//{
// public:
//    explicit CursorPosition(int updateInterval = 100, QWidget *parent =0)
//        :QWidget(parent),
//          position(new QLabel(this))
//    {
//        position->resize(100,20);
//        startTimer(updateInterval);
//    }

//    void timerEvent(QTimerEvent *)
//    {
//        QPoint p = QCursor::pos();
//        position->setText(QString("%1;%2").arg(p.x()).arg(p.y()));
//    }
// private:
//    QLabel *position;
//};

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  //    MainWindow w;
  //    w.show();

  MainWindow t;
  t.show();

  return a.exec();
}
