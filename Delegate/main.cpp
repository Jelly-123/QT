#include <QApplication>
#include<QStandardItemModel>
#include<QTableView>
#include<datedelegate.h>
#include<comboboxdelegate.h>
#include<spinboxdelegate.h>
#include<QFile>
#include<QTextStream>
#include<QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //The QStandardItemModel class provides a generic model for storing custom data
    QStandardItemModel model(4,4);

    QTableView  tableView;
    tableView.setModel(&model);

    dateDelegate datedelegate;
    ComboboxDelegate combbDelegate;
    SpinBoxDelegate spinDelegate;

    tableView.setItemDelegateForColumn(1,&datedelegate);
    tableView.setItemDelegateForColumn(2,&combbDelegate);
    tableView.setItemDelegateForColumn(3,&spinDelegate);
    //View的setItemDelegateForColumn()函数为指定的列应用指定的Delegate
    model.setHeaderData(0,Qt::Horizontal,QObject::tr("Name"));
    model.setHeaderData(1,Qt::Horizontal,QObject::tr("Birthday"));
    model.setHeaderData(2,Qt::Horizontal,QObject::tr("job"));
    model.setHeaderData(3,Qt::Horizontal,QObject::tr("Income"));


    //为表格的表头显示进行设置
    QFile file("/home/qinhuan/QT/QT_test/Delegate/data.txt");

    if(file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        QString line;
        int row = 0;
        do{
                line=stream.readLine();
                if(!line.isEmpty())
                {
                        QStringList pieces = line.split(",",QString::SkipEmptyParts);
                        model.setData(model.index(row,0,QModelIndex()),pieces.value(0));
                        model.setData(model.index(row,1,QModelIndex()),pieces.value(1));
                        model.setData(model.index(row,2,QModelIndex()),pieces.value(2));
                        model.setData(model.index(row,3,QModelIndex()),pieces.value(3));

                        row++;
                }
        }while (!line.isEmpty());
        file.close();
    }
    tableView.setWindowTitle(QObject::tr("Delegate"));
    tableView.show();


    return a.exec();
}
