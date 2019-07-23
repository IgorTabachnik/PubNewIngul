#include "target_info.h"
#include <QImage>
#include <QPainter>

TargetInfo::TargetInfo()
{
    LoadTargets();
    targets.append(&circle);
    targets.append(&chest);
    targets.append(&torso);
    targets.append(&body);
}

void TargetInfo::LoadTargets()
{
    QPixmap main_img(":/media/Target_green.png");
    current_color = QImage(":/media/Target_green.png").pixel(110+415/2,90+415/2);

    circle.texture = main_img.copy(QRect(110,90,415,415));
    circle.mask = circle.texture.createMaskFromColor(QColor(0,0,0,0));
    circle.color_mask = circle.texture.createMaskFromColor(current_color,Qt::MaskOutColor);

    chest.texture = main_img.copy(QRect(100,690,425,415));
    chest.mask = chest.texture.createMaskFromColor(QColor(0,0,0,0));
    chest.color_mask = chest.texture.createMaskFromColor(current_color,Qt::MaskOutColor);

    torso.texture = main_img.copy(QRect(878,106,326,985));
    torso.mask = torso.texture.createMaskFromColor(QColor(0,0,0,0));
    torso.color_mask = torso.texture.createMaskFromColor(current_color,Qt::MaskOutColor);

    body.texture = main_img.copy(QRect(1470,142,383,1383));
    body.mask = body.texture.createMaskFromColor(QColor(0,0,0,0));
    body.color_mask = body.texture.createMaskFromColor(current_color,Qt::MaskOutColor);


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
