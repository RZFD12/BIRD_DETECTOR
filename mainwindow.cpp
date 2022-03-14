#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QMediaPlayer>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    leftCAM=new CamScene(ui->graphicsView);
    rightCAM=new CamScene(ui->graphicsView_2);

    leftCAM->setBackgroundBrush(Qt::black);
    rightCAM->setBackgroundBrush(Qt::black);


    ui->graphicsView->setScene(leftCAM);
    ui->graphicsView_2->setScene(rightCAM);

    leftCAM->setSceneRect(-2000,-2000,4000,4000);
    rightCAM->setSceneRect(-2000,-2000,4000,4000);

    ui->graphicsView->setRenderHint(QPainter::HighQualityAntialiasing);
    ui->graphicsView_2->setRenderHint(QPainter::HighQualityAntialiasing);

    QUrl imageUrl("http://admin:qwerty1234@169.254.111.243/ISAPI/Streaming/channels/101/picture?snapShotImageType=JPEG");
    ImgGetleft = new ImgData(imageUrl, this);
    connect(ImgGetleft,&ImgData::downloaded,this,&MainWindow::loadImg);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImg()
{
    bool a=pixImg.loadFromData(ImgGetleft->downloadedImg());
    if(pix!=nullptr && a){leftCAM->removeItem(pix); leftCAM->clear(); delete pix;}
    if(a){
    pix=leftCAM->addPixmap(pixImg);
    pix->setPos(-960,-540);
    leftCAM->update ();
    }

}


CamScene::CamScene(QWidget *parent)
{

}

void CamScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> itemlist=this->items();
    bool item_under_mouse=true;


   for(const auto it:qAsConst(itemlist)){if(it->isUnderMouse()){item_under_mouse=true; break;}}

    if(event->button()==Qt::LeftButton && item_under_mouse){
    FRAME* F=new FRAME();
    F->setPos(event->scenePos().x(),event->scenePos().y());
    F->setZValue(0.2);
    this->addItem(F);
    }

}


void CamScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void MainWindow::on_nextbtn_clicked()
{

}


void MainWindow::on_playbtn_clicked()
{

}


void MainWindow::on_prevbtn_clicked()
{

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Minus){ui->graphicsView->scale(0.5,0.5);ui->graphicsView_2->scale(0.5,0.5);}
    if(event->key()==Qt::Key_Plus){ui->graphicsView->scale(2,2);ui->graphicsView_2->scale(2,2);}
}
