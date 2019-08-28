#ifndef TARGET_INFO_H
#define TARGET_INFO_H

#include <QBitmap>
#include <QColor>

struct TargetImage
{
    QPixmap texture;
    QBitmap mask;
    QBitmap color_mask;
    QBitmap zone_mask;
};

enum ANIM_TYPE
{
    ANIM_SQUARE,
    ANIM_ZOOM,
    ANIM_PARABOLA,
    ANIM_STATIC
};

class TargetInfo
{
public:
    TargetInfo();
    void ChangeColor(QColor color);
    TargetImage MKPS;
    TargetImage circle;
    TargetImage torso;
    TargetImage chest;
    TargetImage polygon;
    QColor current_color;
    QList<TargetImage*> targets;

private:
    void LoadTargets();
};

#endif // TARGET_INFO_H
