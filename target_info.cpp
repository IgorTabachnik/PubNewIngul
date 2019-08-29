#include "target_info.h"
#include <QImage>
#include <QPainter>
#include <QtSvg>

TargetInfo::TargetInfo()
{
    LoadTargets();
    targets.append(&circle);
    targets.append(&chest);
    targets.append(&torso);
    targets.append(&MKPS);
    targets.append(&polygon);
}

void TargetInfo::LoadTargets()
{
    QSvgRenderer rend(QString(":/media/Circles.svg"));
    QImage *img = new QImage(rend.viewBox().width()*2,rend.viewBox().height()*2,QImage::Format::Format_ARGB32);
    img->fill(0x00);
    QPainter *painter = new QPainter(img);
    rend.render(painter);
    circle.texture = QPixmap::fromImage(*img);
    circle.mask = circle.texture.createMaskFromColor(QColor(0,0,0,0));
    circle.color_mask = circle.texture.createMaskFromColor(img->pixel(img->width()/2,img->height()/2),Qt::MaskOutColor);
    circle.zone_mask = circle.texture.createMaskFromColor(QColor(0,0,0,255),Qt::MaskMode::MaskOutColor); //цвет окружности (чёрный)

    rend.load(QString(":/media/FullSize3.svg"));
    img = new QImage(rend.viewBox().width()*2, rend.viewBox().height()*2,QImage::Format::Format_ARGB32);
    img->fill(0x00);
    painter = new QPainter(img);
    rend.render(painter);
    torso.texture = QPixmap::fromImage(*img);
    torso.mask = torso.texture.createMaskFromColor(QColor(0,0,0,0));
    torso.color_mask = torso.texture.createMaskFromColor(img->pixel(img->width()/2,img->height()/2),Qt::MaskOutColor);
    torso.zone_mask = torso.texture.createMaskFromColor(QColor(0,0,0,255),Qt::MaskMode::MaskOutColor); //цвет окружности (чёрный)

    rend.load(QString(":/media/Star.svg"));
    img = new QImage(rend.viewBox().width()*2, rend.viewBox().height()*2,QImage::Format::Format_ARGB32);
    img->fill(0x00);
    painter = new QPainter(img);
    rend.render(painter);
    polygon.texture = QPixmap::fromImage(*img);
    polygon.mask = polygon.texture.createMaskFromColor(QColor(0,0,0,0));
    polygon.color_mask = polygon.texture.createMaskFromColor(img->pixel(img->width()/2,img->height()/2),Qt::MaskOutColor);
    polygon.zone_mask = polygon.texture.createMaskFromColor(QColor(0,0,0,255),Qt::MaskMode::MaskOutColor);

    rend.load(QString(":/media/MKPS.svg"));
    img = new QImage(rend.viewBox().width()*2, rend.viewBox().height()*2,QImage::Format::Format_ARGB32);
    img->fill(0x00);
    painter = new QPainter(img);
    rend.render(painter);
    MKPS.texture = QPixmap::fromImage(*img);
    MKPS.mask = MKPS.texture.createMaskFromColor(QColor(0,0,0,0));
    MKPS.color_mask = MKPS.texture.createMaskFromColor(img->pixel(img->width()/2,img->height()/2),Qt::MaskOutColor);
    MKPS.zone_mask = MKPS.texture.createMaskFromColor(QColor(0,0,0,255),Qt::MaskMode::MaskOutColor);

    rend.load(QString(":/media/Breast.svg"));
    img = new QImage(rend.viewBox().width()*2, rend.viewBox().height()*2,QImage::Format::Format_ARGB32);
    img->fill(0x00);
    painter = new QPainter(img);
    rend.render(painter);
    chest.texture = QPixmap::fromImage(*img);
    chest.mask = chest.texture.createMaskFromColor(QColor(0,0,0,0));
    chest.color_mask = chest.texture.createMaskFromColor(img->pixel(img->width()/2,img->height()/2),Qt::MaskOutColor);
    chest.zone_mask = chest.texture.createMaskFromColor(QColor(0,0,0,255),Qt::MaskMode::MaskOutColor);

}

void TargetInfo::ChangeColor(QColor color)
{
    QPainter painter;

    for(int i = 0;i<targets.length();++i)
    {
        painter.begin(&targets[i]->texture);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(color);
        painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
        painter.drawPixmap(QRect(0,0,targets[i]->texture.width(),targets[i]->texture.height()),targets[i]->color_mask);
        painter.end();
    }
}
