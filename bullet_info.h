#ifndef BULLET_INFO_H
#define BULLET_INFO_H

#include "target.h"
#include <QDebug>

class BulletInfo {

private:
    Target * target;
    QPointF size_was;
    QPointF relative_position;

public:

    BulletInfo (Target &_target, QPointF position) {
        this->target = &_target;
        this->size_was = this->target->size;
        this->relative_position = position - this->target->position;
    }

    QPointF get_position () {
        int rx = 1;
        int ry = 1;

        try {
            rx = this->target->size.x() / this->size_was.x();
            ry = this->target->size.y() / this->size_was.y();
        } catch (std::exception e) {};

        QPointF result (
            (this->target->position.x() + this->relative_position.x()) * rx,
            (this->target->position.y() + this->relative_position.y()) * ry
        );

        return result;
    }

    Target * get_target_info () {
        return this->target;
    }

};

#endif // BULLET_INFO_H
