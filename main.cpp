#include "mainwindow.h"
#include <QApplication>
#include <QCursor>
#include <QLabel>
#include "tir.h"

class CursorPosition : public QWidget
{
public:
    explicit CursorPosition(int updateInterval = 100, QWidget *parent =0)
        :QWidget(parent),
          position(new QLabel(this))
    {
        position->resize(100,20);
        startTimer(updateInterval);
    }

    void timerEvent(QTimerEvent *event)
    {
        QPoint p = QCursor::pos();
        position->setText(QString("%1;%2").arg(p.x()).arg(p.y()));
    }
private:
    QLabel *position;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    //CursorPosition widget;
    //widget.show();

    Tir t;
    t.show();

    return a.exec();
}
