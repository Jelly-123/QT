#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPixmap>
#include<QMouseEvent>
#include<QImage>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
public:
    QLabel * label1;
    QLabel * label2;
    QLabel * label3;
    QLabel * labelstate;
    QImage image1;
    QImage image2;
    QImage image3;

private:
    Ui::Dialog *ui;
private slots:
    bool eventFilter(QObject *, QEvent *);
};

#endif // DIALOG_H
