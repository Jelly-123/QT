#include "combodelegate.h"


ComboDelegate::ComboDelegate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComboDelegate)
{
    ui->setupUi(this);
}
//返回一个编辑控件，用来编辑指定项的数据
QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const{
    QComboBox * combobox = new QComboBox(parent);
    combobox->addItem(tr("工人"));
    combobox->addItem(tr("军人"));
    combobox->addItem(tr("医生"));
    combobox->addItem(tr("律师"));
    combobox->installEventFilter(const_cast<QComboBox *>(this));
    return combobox;
}
//更新Delegate控件的数据显示
 void setEditorData(QWidget *editor, const QModelIndex &index) const{
     //获取指定index数据项的数据，调用model()可获得提供此index的model对象，data()返回QVariant对象

     QString jobstr = index.model()->data(index).toString();
     qDebug()<<"jobstr"<<jobstr;
    QComboBox * box = const_cast<QComboBox *>(editor);
    int i = box->findText(jobstr);
    box->setCurrentIndex(i);
 }
 //更新model中的数据
 void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const{
        QComboBox * box = const_cast<QComboBox *>(editor);
        QString str = box->currentText();
        model->setData(index,str);
 }
 void updateEditorGeometry(QWidget *editor,
      const QStyleOptionViewItem &option, const QModelIndex &index) const{
     editor->setGeometry(option.rect);
 }
ComboDelegate::~ComboDelegate()
{
    delete ui;
}
