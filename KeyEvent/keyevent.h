#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QMainWindow>
#include<QPainter>
#include<QKeyEvent>
#include<QPalette>
#include<QMatrix>
#include<QDebug>
namespace Ui {
class KeyEvent;
}

class KeyEvent : public QMainWindow
{
    Q_OBJECT

public:
    explicit KeyEvent(QWidget *parent = 0);
    ~KeyEvent();
    void drawPix();         //QPixmap对象上绘制图像
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);

private:
    Ui::KeyEvent *ui;
    QPixmap * pix;  //绘图设备，使用双缓冲机制
    QImage image;   //小人
    int startX; //图标的左上顶位置
    int startY;
    int width;
    int height;
    int step;       //移动步长
};

#endif // KEYEVENT_H
