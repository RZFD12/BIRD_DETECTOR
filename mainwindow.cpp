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

    QUrl imageUrl("https://blog.mystart.com/wp-content/uploads/MyDogs_5ffddc6904abd18a7e5ddec5.jpeg");
    ImgGet = new ImgData(imageUrl, this);
    connect(ImgGet,&ImgData::downloaded,this,&MainWindow::loadImg);


//    leftsock=new QUdpSocket(this);

//    leftsock->bind(QHostAddress("169.254.150.186"),20018);

//    connect(leftsock,&QUdpSocket::readyRead,this,&MainWindow::read_data);
//    leftCAM->addPixmap(p);
    //QTimer *tmr=new QTimer(this);
   // connect(tmr,&QTimer::timeout,this,&MainWindow::add_mixmap);
   // tmr->setInterval(200);
    //tmr->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImg()
{
    pixImg.loadFromData (ImgGet->downloadedImg());
    leftCAM->addPixmap (pixImg);
    leftCAM->update ();
}


CamScene::CamScene(QWidget *parent)
{

}

void CamScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> itemlist=this->items();
    bool item_under_mouse=true;


   for(const auto it:qAsConst(itemlist)){if(it->isUnderMouse()){item_under_mouse=false; break;}}

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

void MainWindow::read_data()
{
    QByteArray data;
    QHostAddress addr;
    quint16 port;
    data.resize(leftsock->pendingDatagramSize());
    leftsock->readDatagram(data.data(),data.size(),&addr,&port);
    add_mixmap(data);

}

void MainWindow::add_mixmap(QByteArray &data)
{
    QByteArray b2=QByteArray::fromBase64(data);
    QImage m=QImage::fromData(data);


    p.fromImage(m);
    leftCAM->addPixmap(p);

    leftCAM->update();
    qDebug()<<12;

}


