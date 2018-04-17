#include "spinboxdelegate.h"

SpinBoxDelegate::SpinBoxDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}
QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const{
    QSpinBox * spinbox = new QSpinBox(parent);
    spinbox->setRange(1000,10000);
    spinbox->installEventFilter(const_cast<SpinBoxDelegate*>(this));
    return spinbox;
}
//将model中的数据赋值到控件上去
void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
        int value = index.model()->data(index).toInt();
        QSpinBox * spin = static_cast<QSpinBox *>(editor);
        spin->setValue(value);
 }
 //更新model中的数据
void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                   const QModelIndex &index) const{
        QSpinBox * spin = static_cast<QSpinBox *>(editor);
        int value = spin->value();
        model->setData(index,value);
}
void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &index) const{
    editor->setGeometry(option.rect);
}
