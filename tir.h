#ifndef TIR_H
#define TIR_H

#include <QWidget>
#include <QLabel>
#include <QCursor>
#include <QPainter>

namespace Ui {
class Tir;
}

class Tir : public QWidget
{
    Q_OBJECT

public:
    explicit Tir(int updateInterval = 100, QWidget *parent = 0);
    ~Tir();

    void timerEvent(QTimerEvent *event) override;

protected:
    void paintEvent(QPaintEvent* event);


private:
    Ui::Tir *ui;
};

#endif // TIR_H
