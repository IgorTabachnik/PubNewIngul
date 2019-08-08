#ifndef MOVINGEXERCISES_H
#define MOVINGEXERCISES_H

#include <QWidget>

namespace Ui {
class MovingExercises;
}

class MovingExercises : public QWidget
{
    Q_OBJECT

public:
    explicit MovingExercises(QWidget *parent = nullptr);
    ~MovingExercises();

private:
    Ui::MovingExercises *ui;
};

#endif // MOVINGEXERCISES_H
