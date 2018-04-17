#include "datedelegate.h"

dateDelegate::dateDelegate(QObject *parent) :
    QItemDelegate(parent)
{
}
//返回一个编辑控件，用来编辑指定项的数据
QWidget *dateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const
{
        QDateTimeEdit * editor = new QDateTimeEdit(parent);
        //新建一个QDateTimeEdit对象作为编辑时的输入控件
        editor->setDisplayFormat("yyyy-MM-dd");
        editor->setCalendarPopup(true);
        //设置日历选择的显示以popup的方式，即下拉显示的方式
        editor->installEventFilter(const_cast<dateDelegate*>(this));
        //使DateDelegate能捕获QDateTimeEdit对象的事件
        return editor;
}
//将model中的数据赋值到控件上去
void dateDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
        //获取指定index数据项的数据，调用model()可获得提供此index的model对象，data()返回QVariant对象
        QString dateStr =index.model()->data(index).toString();
        qDebug()<<dateStr;
        QDate date = QDate::fromString(dateStr,Qt::ISODate);

        QDateTimeEdit * edit = static_cast<QDateTimeEdit*>(editor);
        edit->setDate(date);
}
//设定模型数据，根据指定项中对应编辑控件的数据
void dateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                   const QModelIndex &index) const
{
        //通过紧缩转换获得编辑控件的对象指针
        QDateTimeEdit * edit = static_cast<QDateTimeEdit*>(editor);
        //获得编辑控件中的数据更新
        QDate date = edit->date();
        //调用setDate()把数据修改更新到Model
        model->setData(index,QVariant(date.toString(Qt::ISODate)));

}
void dateDelegate::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
