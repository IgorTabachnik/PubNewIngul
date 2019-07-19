#ifndef TARGET_H
#define TARGET_H

#include <QtGUI>
#include "targetconstants.h"

class Target {
public:

    struct StateHid
    {
        bool hid;
        int score;

        float Xm;
        float Ym;

        float h;
        float Xc;
        float Yc;
    };

    enum target_type {
        circle, chest, torso, body
    };

    QPointF zero;
    QPointF position;
    QPointF size;
    QPolygonF poly_m;
    bool fix;
private:
    target_type type;
    QPixmap img;
    QPixmap texture;

    void load_image () {
        this->img.load(":/media/Target_green.png");
    }

    void load_texture () {
        float x, y, w, h;
        switch (this->type) {
            case circle:
                x = 112;
                y = 89;
                w = 412;
                h = 412;
                break;
            case chest:
                x = 104;
                y = 688;
                w = 426;
                h = 413;
                break;
            case torso:
                x = 878;
                y = 106;
                w = 326;
                h = 985;
                break;
            case body:
                x = 1470;
                y = 142;
                w = 383;
                h = 1383;
                break;
        }
        this->texture = img.copy(x, y, w, h);
    }

public:
    bool visible = true;

    Target (target_type type, QPointF position, QPointF size) {
        this->type = type;
        this->position = position;
        this->size = size;
        this->fix = false;
        if (this->type == circle && this->size.x() != this->size.y()) {
            this->size.setX(this->size.y());
        }
    }

    target_type get_type () {
        return this->type;
    }

    QPointF get_position () {
        return this->position;
    }

    QPointF get_size () {
        return this->size;
    }

    QString printPolygon(){
        QString res;
        for(int i=0;i<poly_m.length();i++)
        {
            res=QString("X%1=").arg(i) + poly_m[i].x() +" "+ QString("Y%1=").arg(i) + poly_m[i].y()+"\n";
        }
        return res;
    }

    void draw (QPainter &painter) {
        if (!this->visible) {
            return;
        }

        if (this->img.isNull()) {
            this->load_image();
        }

        if (this->texture.isNull()) {
            this->load_texture();
        }

        painter.drawPixmap(this->position.x(), this->position.y(), this->size.x(), this->size.y(), this->texture);
    }

    StateHid hid_detected (QPointF point) {
        StateHid state;
        switch (this->type) {
            case circle:
                {                 
                    state.Xc = abs(this->position.x() - this->size.x() / 2);
                    state.Yc = abs(this->position.y() - this->size.y() / 2);

                    float hypotenuse = sqrt(pow(abs(point.x() - this->position.x() - this->size.x() / 2), 2) + pow(abs(point.y() - this->position.y() - this->size.y() / 2), 2));
                    state.hid = hypotenuse <= this->size.x() / 2;
                    state.score = getScore(hypotenuse);

                    state.Xm = point.x();
                    state.Ym = point.y();
                    state.h = hypotenuse;

                    return state;
                }
                break;
            case chest:
                {

                    QPolygonF poly;
                    float rx = this->size.x() / 425;
                    float ry = this->size.y() / 411;

                    poly << QPointF(0, (160* ry))
                         << QPointF((113 * rx), (160 * ry))
                         << QPointF((113 * rx), 2)
                         << QPointF((306 * rx), 2)
                         << QPointF((306 * rx), (156 * ry))
                         << QPointF((420 * rx), (156 * ry))
                         << QPointF((420 * rx), (409 * ry))
                         << QPointF(0, (409 * ry));

                    if(!fix)
                    {
                        fix=true;
                        poly_m = poly;
                    }
                    state.hid = poly.containsPoint(point - this->position, Qt::OddEvenFill);
                    return state;
                }
                break;
            case torso:
                {
                    QPolygonF poly;
                    float rx = this->size.x() / 326;
                    float ry = this->size.y() / 985;

                    poly << QPointF(0, 122 * ry)
                         << QPointF(92 * rx, 122 * ry)
                         << QPointF(92 * rx, 0)
                         << QPointF(234 * rx, 0)
                         << QPointF(234 * rx, 122 * ry)
                         << QPointF(326 * rx, 122 * ry)
                         << QPointF(326 * rx, 693 * ry)
                         << QPointF(248 * rx, 985 * ry)
                         << QPointF(92 * rx, 985 * ry)
                         << QPointF(0, 693 * ry);
                    state.hid = poly.containsPoint(point - this->position, Qt::OddEvenFill);
                    return state;
                }
                break;
            case body:
                {
                    QPolygonF poly;
                    float rx = this->size.x() / 383;
                    float ry = this->size.y() / 1383;

                    poly << QPointF(0, 195 * ry)
                         << QPointF(126 * rx, 195 * ry)
                         << QPointF(126 * rx, 0)
                         << QPointF(256 * rx, 0)
                         << QPointF(256 * rx, 195 * ry)
                         << QPointF(383 * rx, 195 * ry)
                         << QPointF(383 * rx, 792 * ry)
                         << QPointF(262 * rx, 1383 * ry)
                         << QPointF(133 * rx, 1383 * ry)
                         << QPointF(0, 792 * ry);

                    state.hid = poly.containsPoint(point - this->position, Qt::OddEvenFill);
                    return state;
                }
                break;
        }
        state.hid = false;
        return state;
    }

    int getScore(float h){
        int *arr;
        switch (this->type) {
        case circle:
            arr = TargetConstants::rCricle;
            break;
        default:
            break;
        }

        for(int i=0;i<10;i++){
            if(h<=arr[i])
            {
                return 10-i;
            }
        }
        return 0;
    }
};

//int Target::rCricle[10];

#endif // TARGET_H
