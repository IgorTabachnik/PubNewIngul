#ifndef TARGET2_H
#define TARGET2_H

#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QPaintEvent>
#include <QBitmap>

class Target2 : public QWidget
{
    Q_OBJECT
public:
    enum target_type { circle, chest, torso, body };

    explicit Target2(QWidget *parent = nullptr);
    void LoadImage();
    void LoadTexture(target_type target);

private:
    target_type type;
    bool event(QEvent* event);
    void paintEvent(QPaintEvent* event);
    QPixmap img;
    QPixmap texture;
    QBitmap mask;
    QList<QPointF> bullets;

signals:

public slots:
};

#endif // TARGET2_H
