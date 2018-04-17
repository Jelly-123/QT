#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QtGui>
#include<QItemDelegate>
#include<QDateTimeEdit>
#include<QDebug>
#include<QModelIndex>

class dateDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    dateDelegate(QObject *parent = 0);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
         const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // DATEDELEGATE_H
