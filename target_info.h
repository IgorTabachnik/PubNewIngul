#ifndef TARGET_INFO_H
#define TARGET_INFO_H

#include <QBitmap>
#include <QColor>

struct TargetImage
{
    QPixmap texture;
    QBitmap mask;
    QPixmap color_mask;
};

class TargetInfo
{
public:
    TargetInfo();
    void ChangeColor(QColor color);
    TargetImage body;
    TargetImage circle;
    TargetImage torso;
    TargetImage chest;
    QColor current_color;
    QList<TargetImage*> targets;

private:
    void LoadTargets();
};

#endif // TARGET_INFO_H
