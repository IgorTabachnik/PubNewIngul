#ifndef TARGET_H
#define TARGET_H
#include <QPixmap>
#include <QPointF>
#include <cmath>
#include <ctime>

class Target {
 public:
  QPointF position;
  QPointF size;
  enum target_type { circle, chest, torso, body };

 private:
  target_type type;

  QPixmap img;
  QPixmap texture;

  void load_image() { this->img.load(":/media/Target_green.png"); }

  void load_texture() {
    float x, y, w, h;
    switch (this->type) {
      case circle:
        x = 110;
        y = 90;
        w = 415;
        h = 415;
        break;
      case chest:
        x = 100;
        y = 690;
        w = 425;
        h = 415;
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

  Target(target_type type, QPointF position, QPointF size) {
    this->type = type;
    this->position = position;
    this->size = size;

    if (this->type == circle && this->size.x() != this->size.y()) {
      this->size.setX(this->size.y());
    }
  }
  void SetTargetPosition() {
    this->position = QPointF(rand() % 100 + 100, rand() % 100 + 100);
  }

  target_type get_type() { return this->type; }

  QPointF get_position() { return this->position; }

  QPointF get_size() { return this->size; }

  void draw(QPainter &painter) {
    if (!this->visible) {
      return;
    }

    if (this->img.isNull()) {
      this->load_image();
    }

    if (this->texture.isNull()) {
      this->load_texture();
    }

    painter.drawPixmap(this->position.x(), this->position.y(), this->size.x(),
                       this->size.y(), this->texture);
  }

  bool hid_detected(QPointF point) {
    switch (this->type) {
      case circle: {
        float hypotenuse = sqrt(
            pow(abs(point.x() - this->position.x() - this->size.y() / 2), 2) +
            pow(abs(point.y() - this->position.y() - this->size.y() / 2), 2));
        return hypotenuse <= this->size.x() / 2;
      } break;
      case chest: {
        QPolygonF poly;
        float rx = this->size.x() / 427;
        float ry = this->size.y() / 412;

        poly << QPointF(0, 153 * ry) << QPointF(144 * rx, 153 * ry)
             << QPointF(144 * rx, 0) << QPointF(309 * rx, 0)
             << QPointF(309 * rx, 153 * ry) << QPointF(425 * rx, 153 * ry)
             << QPointF(425 * rx, 415 * ry) << QPointF(0, 415 * ry);

        return poly.containsPoint(point - this->position, Qt::OddEvenFill);
      } break;
      case torso: {
        QPolygonF poly;
        float rx = this->size.x() / 326;
        float ry = this->size.y() / 985;

        poly << QPointF(0, 122 * ry) << QPointF(92 * rx, 122 * ry)
             << QPointF(92 * rx, 0) << QPointF(234 * rx, 0)
             << QPointF(234 * rx, 122 * ry) << QPointF(326 * rx, 122 * ry)
             << QPointF(326 * rx, 693 * ry) << QPointF(248 * rx, 985 * ry)
             << QPointF(92 * rx, 985 * ry) << QPointF(0, 693 * ry);

        return poly.containsPoint(point - this->position, Qt::OddEvenFill);
      } break;
      case body: {
        QPolygonF poly;
        float rx = this->size.x() / 383;
        float ry = this->size.y() / 1383;

        poly << QPointF(0, 195 * ry) << QPointF(126 * rx, 195 * ry)
             << QPointF(126 * rx, 0) << QPointF(256 * rx, 0)
             << QPointF(256 * rx, 195 * ry) << QPointF(383 * rx, 195 * ry)
             << QPointF(383 * rx, 792 * ry) << QPointF(262 * rx, 1383 * ry)
             << QPointF(133 * rx, 1383 * ry) << QPointF(0, 792 * ry);

        return poly.containsPoint(point - this->position, Qt::OddEvenFill);
      } break;
    }

    return false;
  }
};

#endif  // TARGET_H
