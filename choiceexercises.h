#ifndef CHOICEEXERCISES_H
#define CHOICEEXERCISES_H

#include <QWidget>

namespace Ui {
class ChoiceExercises;
}

class ChoiceExercises : public QWidget
{
    Q_OBJECT

public:
    explicit ChoiceExercises(QWidget *parent = nullptr);
    ~ChoiceExercises();
signals :
    void clickedBtnGo();
    void clickedBtnStatic();
    void clickedBtnMoving();

private:
    Ui::ChoiceExercises *ui;
};

#endif // CHOICEEXERCISES_H
