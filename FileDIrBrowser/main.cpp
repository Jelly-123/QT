#include <QApplication>
#include<QDirModel>
#include<QListView>
#include<QTreeView>
#include<QTableView>
#include<QSplitter>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDirModel model;
    QTreeView tree;
    QTableView tabel;
    QListView list;

    tree.setModel(&model);
    list.setModel(&model);
    tabel.setModel(&model);

    tree.setSelectionMode(QAbstractItemView::MultiSelection);
    list.setSelectionModel(tree.selectionModel());
    tabel.setSelectionModel(tree.selectionModel());
    //setting QTreeView obj choose-mode is mult
    //list and tabel using tha same choice
    QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&list,SLOT(setRootIndex(QModelIndex)));
    QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&tabel,SLOT(setRootIndex(QModelIndex)));
    //connect tree's doubleClicked to list and tabel
    QSplitter * splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&tabel);

    splitter->setWindowTitle(QObject::tr("Model/View"));
    splitter->show();



    return a.exec();
}
