#include "tir.h"
#include "ui_tir.h"
#include <QThread>
//#include <QRect>
//#include <QDebug>

Tir::Tir(int updateInterval, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tir)
{
    ui->setupUi(this);
    targets.append(Target(Target::circle, QPointF(0, 0), QPointF(412, 412)));

    startTimer(updateInterval);
    case_state = 0;
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

    if(case_state == 1){
        QPointF pos = this->mapFromGlobal(QCursor::pos());
        poly<<QPointF(pos);
    }

    if(case_state == 0){
        poly.clear();
    }

    repaint();
}

void Tir::timerEvent(QTimerEvent *)
{
    QPointF cursor = this->mapFromGlobal(QCursor::pos());
    this->focused_targets.clear();

    for (int i = 0; i < this->targets.length(); i++) {
        Target::StateHid state = this->targets[i].hid_detected(cursor);
        if (state.hid) {
            this->focused_targets.append(i);            
        }
        ui->Score->setText(QString("Score = %1").arg(state.score));
        ui->Xcur->setText(QString("Xcur = %1").arg(state.Xm));
        ui->Ycur->setText(QString("Ycur = %1").arg(state.Ym));
        ui->H->setText(QString("Hyp = %1").arg(state.h));

        ui->Xc->setText(QString("Xc = %1").arg(state.Xc));
        ui->Yc->setText(QString("Xc = %1").arg(state.Yc));
    }
    //targets[0].position += QPointF(1,1);
}

void Tir::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    for (int i = 0; i < this->targets.length(); i++) {
        this->targets[i].draw(painter);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));

    for (int i = 0; i < this->bullets.length(); i++) {
        if (this->bullets[i].get_target_info()->visible == true) {
            painter.drawEllipse(this->bullets[i].get_position(), 3, 3);
        }
    }

    if(case_state == 3){
        painter.drawPolygon(targets[0].poly_m);
    }
}

void Tir::keyPressEvent(QKeyEvent *event){
    int key=event->key();
    QString str = QString(QChar(key));
    qInfo()<<"Press key : "<<QString("%1").arg(key)<<" ~ "<<str;
    if(str=="R"){
        case_state = 0;
        qInfo()<<"Reset state = \n"<<QString("%1").arg(case_state);
    }else if(str == "F"){
        case_state = 1;
        qInfo()<<"Fix coordinate state = \n"<<QString("%1").arg(case_state);
    }else if(str == "S"){
        case_state = 2;
        qInfo()<<"Stop fix coordinate state = \n"<<QString("%1").arg(case_state);
    }else if(str == "V"){
        case_state = 3;
        qInfo()<<"Visible polygon state = \n"<<QString("%1").arg(case_state);
    }else if(str == "\u0012"){
        system("CLS");


        case_state = 4;
        qInfo()<<"State = \n"<<QString("%1").arg(case_state);
        qInfo()<<targets[0].printPolygon();
    }else if(str == "\u0013"){
        system("CLS");
        case_state = 5;
        //ui->textBrowser->clear();
        //ui->textBrowser->append(targets[0].printPolygon());
        qInfo()<<"State = \n"<<QString("%1").arg(case_state);
    }else if(str == "\u0014"){
        system("CLS");
        case_state = 6;
        //ui->textBrowser->clear();
        //ui->textBrowser->append(targets[0].printPolygon());
        qInfo()<<"State = \n"<<QString("%1").arg(case_state);
    }else if(str == "\u0015"){
        system("CLS");
        case_state = 7;
        //ui->textBrowser->clear();
       // ui->textBrowser->append(targets[0].printPolygon());
        qInfo()<<"State = \n"<<QString("%1").arg(case_state);
    }
}
