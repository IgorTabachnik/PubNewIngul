#ifndef FORMGROUP_H
#define FORMGROUP_H

#include <QWidget>

namespace Ui {
class FormGroup;
}

class FormGroup : public QWidget
{
    Q_OBJECT

public:
    explicit FormGroup(QWidget *parent = 0);
    ~FormGroup();

private:
    Ui::FormGroup *ui;
};

#endif // FORMGROUP_H
