#include "comboboxdelegate.h"

ComboboxDelegate::ComboboxDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}
//返回一个编辑控件，用来编辑指定项的数据
QWidget *ComboboxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const{
    QComboBox * combobox = new QComboBox(parent);
    combobox->addItem(QObject::tr("工人"));
    combobox->addItem(QObject::tr("军人"));
    combobox->addItem(QObject::tr("医生"));
    combobox->addItem(QObject::tr("律师"));
    combobox->installEventFilter(const_cast<ComboboxDelegate *>(this));
    return combobox;
}
//更新Delegate控件的数据显示
 void ComboboxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const{
     //获取指定index数据项的数据，调用model()可获得提供此index的model对象，data()返回QVariant对象
     QString jobstr = index.model()->data(index).toString();
     qDebug()<<"delegat:jobstr"<<jobstr;
    QComboBox * box = static_cast<QComboBox *>(editor);
    int i = box->findText(jobstr);
    box->setCurrentIndex(i);
 }
 //更新model中的数据
 void ComboboxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const{
        QComboBox * box = static_cast
                <QComboBox *>(editor);
        QString str = box->currentText();
        qDebug()<<"model:jobstr"<<str;
        model->setData(index,str);
 }
 void ComboboxDelegate::updateEditorGeometry(QWidget *editor,
      const QStyleOptionViewItem &option, const QModelIndex &index) const{
     editor->setGeometry(option.rect);
 }
