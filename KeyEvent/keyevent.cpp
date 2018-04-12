#include "keyevent.h"
#include "ui_keyevent.h"

KeyEvent::KeyEvent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::KeyEvent)
{
    ui->setupUi(this);

    setWindowTitle(tr("移动小猴子"));

    setMinimumSize(1024,800);
    setMaximumSize(1024,800);

    width=size().width();
    height = size().height();

    pix = new QPixmap(width,height);
    step = 32;
    image.load(":/face-monkey.png");

    QMatrix martix;
    martix.scale(0.1,0.1);
    image = image.transformed(martix);
    startX=0;
    startY=0;

    drawPix();

}

KeyEvent::~KeyEvent()
{
    delete ui;
}
/*
    函数名   ：drawPix()
    功能       ：绘制网格
    返回参数 : 无
*/
void KeyEvent::drawPix(){

    pix->fill(Qt::red);
    QPainter * painter = new QPainter(pix);

    QPen pen(Qt::DotLine);
    painter->setPen(pen);


    for(int i=step;i<width;)
    {
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        //Draws a line from (x1, y1) to (x2, y2) and sets the current pen position to (x2, y2).
        i=i+step;
    }//for i
    for(int j=step;j<height;)
    {
        painter->drawLine(QPoint(0,j),QPoint(width,j));
        j=j+step;
    }//for j
    painter->drawImage(QPoint(startX,startY),image);

    delete painter;
    //在这里必须delete painter
}

void KeyEvent::keyPressEvent(QKeyEvent *event)
{
    //如果按下了ctrl键
    if(event->modifiers()==Qt::ControlModifier)
    {
        if(event->key() == Qt::Key_Left)
        {
            startX = (startX-1<0)?startX:startX-1;
        }
        if(event->key()==Qt::Key_Right)
        {
            startX = (startX+1+image.width()>width)?startX:startX+1;
        }
        if(event->key()==Qt::Key_Up)
        {
             startY = (startY-1<0)?startY:startY-1;
        }
        if(event->key()==Qt::Key_Down)
        {
              startY = ((startY+1+image.height())>height)?startY:startY+1;
        }
    }else
    {

            if(event->key() == Qt::Key_Left)
            {
                startX = (startX-step<0)?startX:startX-step;
            }
            if(event->key()==Qt::Key_Right)
            {
                startX = (startX+step+image.width()>width)?startX:startX+step;
            }
            if(event->key()==Qt::Key_Up)
            {
                 startY = (startY-step<0)?startY:startY-step;
            }
            if(event->key()==Qt::Key_Down)
            {
                  startY = ((startY+step+image.height())>height)?startY:startY+step;
            }
            if(event->key()==Qt::Key_Home)
            {
                startX=0;
                startY=0;
            }
            if(event->key()==Qt::Key_End)   //如果按下End键将图标位置置为界面的右下顶点，也要考虑图标自身的大小
            {
                startX=width-image.width();
                startY=height-image.height();
            }
    }
    drawPix();
    update();
}
//界面的重画函数，将pix绘制在界面上
void KeyEvent::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
//    drawPix(); //这里没有必要调用draw函数，因为在main一进来，先调用构造函数，已经把布局绘制好了
    painter.drawPixmap(QPoint(0,0),*pix);
}
