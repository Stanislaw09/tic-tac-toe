#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "minmax.h"
#include <QPainter>
#include <QtMath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MinMax=new minmax;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            tab[i][j]=0;


    QSize size;
    size.setWidth(this->width());
    size.setHeight(this->height());

    QImage newimage(size, QImage::Format_RGB32);
    image=newimage;
    image.fill(qRgb(35, 15, 25));
}

MainWindow::~MainWindow()
{
    delete ui;
}

 void MainWindow::paintEvent(QPaintEvent *event)
 {
     //Q_UNUSED(event)

     QPainter painter(this);
     painter.setPen(QPen(QBrush("#dd99ba"), 7));
     painter.setRenderHint(QPainter::Antialiasing);

     QRect Rect=event->rect();
     painter.drawImage(Rect, image, Rect);

     painter.drawLine(100, 200, 400, 200);
     painter.drawLine(100, 300, 400, 300);
     painter.drawLine(200, 100, 200, 400);
     painter.drawLine(300, 100, 300, 400);
 }

 void MainWindow::mousePressEvent(QMouseEvent *e)
 {
     QPoint point;
     point=e->pos();

     if(point.x()>100   &&  point.x()<400   &&  point.y()>100   &&   point.y()<400)
         if(tab[(point.x()/100)-1][(point.y()/100)-1]==0)
         {
             paintX((qFloor(point.x()/100)*100)+50, (qFloor(point.y()/100)*100)+50);


             tab[(point.x()-100)/100][(point.y()-100)/100]=-1;
             paintO(MinMax->GetMove(tab));

             if(MinMax->Win(tab)==1)
             {
                 qDebug()<<"I win";
                 setDisabled(1);
             }

             if(MinMax->Win(tab)==2)
             {
                 qDebug()<<"Draw";
                 setDisabled(1);
             }
         }
 }

 void MainWindow::paintX(int x, int y)
 {
     QPainter painter(&image);

     painter.setPen(QPen(QBrush("#508065"),5 ,Qt::SolidLine , Qt::RoundCap, Qt::RoundJoin));
     painter.setRenderHint(QPainter::Antialiasing);

     painter.drawLine(x-23, y-25, x+23, y+25);
     painter.drawLine(x-23, y+25, x+23, y-25);
     update();
 }

 void MainWindow::paintO(QPair<int, int> pair)
 {
     if(pair.first<3   &&  pair.second<3)
     {
         QPainter painter(&image);
         painter.setPen(QPen(QBrush("#506065"),5 ,Qt::SolidLine , Qt::RoundCap, Qt::RoundJoin));
         painter.setRenderHint(QPainter::Antialiasing);

         painter.drawEllipse(120+(pair.first*100), 120+(pair.second*100), 60, 60);
         tab[pair.first][pair.second]=1;
     }
 }
