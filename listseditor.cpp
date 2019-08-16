#include "listseditor.h"
#include "ui_listseditor.h"

ListsEditor::ListsEditor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListsEditor)
{
    ui->setupUi(this);
}

ListsEditor::~ListsEditor()
{
    delete ui;
}
