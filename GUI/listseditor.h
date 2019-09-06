#ifndef LISTSEDITOR_H
#define LISTSEDITOR_H

#include <QWidget>

namespace Ui {
class ListsEditor;
}

class ListsEditor : public QWidget
{
    Q_OBJECT

public:
    explicit ListsEditor(QWidget *parent = nullptr);
    ~ListsEditor();

private:
    Ui::ListsEditor *ui;
};

#endif // LISTSEDITOR_H
