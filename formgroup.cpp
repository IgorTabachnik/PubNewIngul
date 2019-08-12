#include "formgroup.h"
#include "ui_formgroup.h"

FormGroup::FormGroup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormGroup)
{
    ui->setupUi(this);
}

FormGroup::~FormGroup()
{
    delete ui;
}
