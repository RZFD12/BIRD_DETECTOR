#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsPixmapItem>


#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

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


    connect(ui->RGB,&QRadioButton::toggled,this,&MainWindow::image_filter);

    connect(ui->GRAY,&QRadioButton::toggled,this,&MainWindow::image_filter);

    connect(ui->THRESH,&QRadioButton::toggled,this,&MainWindow::image_filter);


    //std::string url="rtsp://admin:qwerty1234@169.254.38.115:554/ISAPI/Streaming/Channels/101";



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImg()
{

}

void MainWindow::loadimgleft(QImage *img) //left
{
    if(leftpix!=nullptr){leftCAM->removeItem(leftpix); leftCAM->clear(); delete leftpix;}
    leftpix=leftCAM->addPixmap(QPixmap::fromImage(img->rgbSwapped()));
    leftpix->setPos(-960,-540);
    leftCAM->update ();
}

void MainWindow::loadimgrigt(QImage *img)
{
    if(rightpix!=nullptr){rightCAM->removeItem(rightpix);rightCAM->clear(); delete rightpix;}
    rightpix=rightCAM->addPixmap(QPixmap::fromImage(img->rgbSwapped()));
    rightpix->setPos(-960,-540);
    rightCAM->update();
}



void MainWindow::on_lineEdit_editingFinished()// left
{
    if(ImgGetleft==nullptr){
    ImgGetleft = new ImgData(ui->lineEdit->text().toStdString(), this);
    connect(ImgGetleft,&ImgData::image,this,&MainWindow::loadimgleft);
    connect(this,&MainWindow::tresh_param,ImgGetleft,&ImgData::treshhold_param);
    connect(this,&MainWindow::img_filter,ImgGetleft,&ImgData::img_filter);
    }
}


void MainWindow::on_lineEdit_2_editingFinished() //right
{
    if(ImgGetright==nullptr){
     ImgGetright = new ImgData(ui->lineEdit_2->text().toStdString(), this);
     connect(ImgGetright,&ImgData::image,this,&MainWindow::loadimgrigt);
     connect(this,&MainWindow::tresh_param,ImgGetright,&ImgData::treshhold_param);
     connect(this,&MainWindow::img_filter,ImgGetright,&ImgData::img_filter);
    }
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
}






void MainWindow::on_horizontalSlider_valueChanged(int value)// bs
{
    emit tresh_param(value,static_cast<double>(ui->horizontalSlider_2->value()));

}


void MainWindow::on_horizontalSlider_2_valueChanged(int value) //c
{
    int bs=ui->horizontalSlider->value();
    emit tresh_param(bs,static_cast<double>(value));

}




void MainWindow::image_filter()
{
    QRadioButton *btn=qobject_cast<QRadioButton*>(QObject::sender());

    if(btn==ui->RGB){emit img_filter(state::RGB);}
    else if (btn==ui->GRAY){emit img_filter(state::Gray);}
    else if (btn==ui->THRESH) {emit img_filter(state::Threshold);}
    else {}

    btn=nullptr;
    delete btn;
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



