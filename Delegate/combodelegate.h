#ifndef COMBODELEGATE_H
#define COMBODELEGATE_H

#include <QWidget>
#include<qcombobox.h>

namespace Ui {
class ComboDelegate;
}

class ComboDelegate : public QWidget
{
    Q_OBJECT

public:
    explicit ComboDelegate(QWidget *parent = 0);
    ~ComboDelegate();
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
         const QStyleOptionViewItem &option, const QModelIndex &index) const;


};

#endif // COMBODELEGATE_H
