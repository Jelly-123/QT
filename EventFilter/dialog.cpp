#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    label1 = new QLabel;
    label2 = new QLabel;
    label3 = new QLabel;
    labelstate = new QLabel;
    labelstate->setAlignment(Qt::AlignHCenter);

    image1.load(":/BABY.jpg");
    image2.load(":/baby.jpg");
    image3.load(":/huanhuan.jpg");

    QMatrix matrix;
    matrix.scale(0.3,0.3);
    image1 = image1.transformed(matrix);
    image2 = image2.transformed(matrix);
    image3 = image3.transformed(matrix);

    label1->setPixmap(QPixmap::fromImage(image1));
    label2->setPixmap(QPixmap::fromImage(image2));
    label3->setPixmap(QPixmap::fromImage(image3));

    QHBoxLayout * hor = new QHBoxLayout;
    hor->addWidget(label1);
    hor->addWidget(label2);
    hor->addWidget(label3);

    QVBoxLayout * ver = new QVBoxLayout;
    ver->addLayout(hor);
    ver->addWidget(labelstate);
    setLayout(ver);

    label1->installEventFilter(this);
    label2->installEventFilter(this);
    label3->installEventFilter(this);
    //void QObject::installEventFilter(QObject * filterObj)
    //filterObj 是监视事件的对象


}
bool Dialog::eventFilter(QObject *watched, QEvent *event)
{
    //判断当前发生事件的对象
    if(watched==label1)
    {
        if(event->type()==QEvent::MouseButtonPress) //判断发生的事件类型
        {
            //将事件event转化为鼠标事件
            QMouseEvent * mouseEvent = (QMouseEvent *)event;
            if(mouseEvent->button()&Qt::LeftButton)
            {
                labelstate->setText(tr("Left mouse button pressed on left image"));
            }
            if(mouseEvent->button()&Qt::RightButton)
            {
                labelstate->setText(tr("middle mouse button pressed on left image"));
            }
            if(mouseEvent->button()&Qt::MidButton)
            {
                labelstate->setText(tr("right mouse button pressed on left image"));
            }
            QMatrix matrix;
            matrix.scale(2,2);
            QImage tmp1 = image1.transformed(matrix);
            label1->setPixmap(QPixmap::fromImage(tmp1));
        }
        if(event->type()==QEvent::MouseButtonRelease)
        {
            labelstate->setText(tr("Mouse button released from left image"));
            label1->setPixmap(QPixmap::fromImage(image1));

        }
    }
    if(watched==label2)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent * mouseEvent = (QMouseEvent *)event;
            if(mouseEvent->button()&Qt::LeftButton)
            {
                labelstate->setText(tr("Left mouse button pressed on middle image"));
            }
            if(mouseEvent->button()&Qt::RightButton)
            {
                labelstate->setText(tr("middle mouse button pressed on middle image"));
            }
            if(mouseEvent->button()&Qt::MidButton)
            {
                labelstate->setText(tr("right mouse button pressed on middle image"));
            }
            QMatrix matrix;
            matrix.scale(2,2);
            QImage  tmp2 = image2.transformed(matrix);
            label2->setPixmap(QPixmap::fromImage(tmp2));
        }
        if(event->type()==QEvent::MouseButtonRelease)
        {
            labelstate->setText(tr("Mouse button released from middle image"));
            label2->setPixmap(QPixmap::fromImage(image2));
        }

     }
    if(watched==label3)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent * mouseEvent = (QMouseEvent *)event;
            if(mouseEvent->button()&Qt::LeftButton)
            {
                labelstate->setText(tr("Left mouse button pressed on right image"));
            }
            if(mouseEvent->button()&Qt::RightButton)
            {
                labelstate->setText(tr("middle mouse button pressed on right image"));
            }
            if(mouseEvent->button()&Qt::MidButton)
            {
                labelstate->setText(tr("right mouse button pressed on right image"));
            }
            QMatrix matrix;
            matrix.scale(2,2);
            QImage  tmp3 = image3.transformed(matrix);
            label3->setPixmap(QPixmap::fromImage(tmp3));
        }
        if(event->type()==QEvent::MouseButtonRelease)
        {
            labelstate->setText(tr("Mouse button released from right image"));
            label3->setPixmap(QPixmap::fromImage(image3));
        }
      }
      //调用QDialog::eventFilter将事件交给上层对话框
      return QDialog::eventFilter(watched,event);

}


Dialog::~Dialog()
{
    delete ui;
}
