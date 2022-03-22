#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QThread>
#include <QFileDialog>

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

    connect(ui->RGB,&QRadioButton::toggled,this,&MainWindow::imageFilter);
    connect(ui->GRAY,&QRadioButton::toggled,this,&MainWindow::imageFilter);
    connect(ui->THRESH,&QRadioButton::toggled,this,&MainWindow::imageFilter);

    ui->lineEdit->setText("rtsp://admin:qwerty1234@169.254.38.115:554/ISAPI/Streaming/Channels/101");
    ui->lineEdit_2->setText("rtsp://admin:qwerty1234@169.254.38.115:554/ISAPI/Streaming/Channels/101");

    filehandler =new FileHandler();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImg()
{

}

void MainWindow::loadImgLeft(QPixmap piximg)
{
    if(leftpix!=nullptr){leftCAM->removeItem(leftpix); leftCAM->clear(); delete leftpix;}
    leftpix=leftCAM->addPixmap(piximg);
    leftpix->setPos(-960,-540);
    leftCAM->update ();
}

void MainWindow::loadImgRight(QPixmap piximg)
{
    if(rightpix!=nullptr){rightCAM->removeItem(rightpix);rightCAM->clear(); delete rightpix;}
    rightpix=rightCAM->addPixmap(piximg);
    rightpix->setPos(-960,-540);
    rightCAM->update();
}

void MainWindow::on_lineEdit_editingFinished()// left
{
    if(ImgGetLeft==nullptr)
    {
        ImgGetLeft = new ImgData(ui->lineEdit->text().toStdString());
        ImgGetLeft->setFileHandler(this->filehandler);
        QThread *lthread=new QThread(this);
        ImgGetLeft->moveToThread(lthread);
        connect(ImgGetLeft,&ImgData::image,this,&MainWindow::loadImgLeft);
        connect(this,&MainWindow::thresHold,ImgGetLeft,&ImgData::setThresHold);
        connect(this,&MainWindow::imgFilter,ImgGetLeft,&ImgData::imgFilter);
        connect(lthread,&QThread::started,ImgGetLeft,&ImgData::start);
        lthread->start();
    }
}


void MainWindow::on_lineEdit_2_editingFinished() //right
{
    if(ImgGetRight==nullptr)
    {
        ImgGetRight = new ImgData(ui->lineEdit_2->text().toStdString());
        QThread *rthread=new QThread(this);
        ImgGetRight->moveToThread(rthread);
        connect(ImgGetRight,&ImgData::image,this,&MainWindow::loadImgRight);
        connect(this,&MainWindow::thresHold,ImgGetRight,&ImgData::setThresHold);
        connect(this,&MainWindow::imgFilter,ImgGetRight,&ImgData::imgFilter);
        connect(rthread,&QThread::started,ImgGetRight,&ImgData::start);
        rthread->start();
    }
}

void MainWindow::on_nextButton_clicked()
{

}

void MainWindow::on_playButton_clicked()
{

}

void MainWindow::on_prevButton_clicked()
{

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Minus){ui->graphicsView->scale(0.5,0.5);ui->graphicsView_2->scale(0.5,0.5);}
    if(event->key()==Qt::Key_Plus){ui->graphicsView->scale(2,2);ui->graphicsView_2->scale(2,2);}
}

void MainWindow::read()
{
    QByteArray data;
    QHostAddress addr;
    quint16 port;
    data.resize(leftsock->pendingDatagramSize());
    leftsock->readDatagram(data.data(),data.size(),&addr,&port);
    addMixmap(data);
}

void MainWindow::addMixmap(QByteArray &data)
{
    QByteArray b2=QByteArray::fromBase64(data);
    QImage m=QImage::fromData(data);
    p.fromImage(m);
    leftCAM->addPixmap(p);
    leftCAM->update();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)// bs
{
    emit thresHold(value,static_cast<double>(ui->horizontalSlider_2->value()));

}

void MainWindow::on_horizontalSlider_2_valueChanged(int value) //c
{
    int bs=ui->horizontalSlider->value();
    emit thresHold(bs,static_cast<double>(value));
}

void MainWindow::imageFilter()
{
    QRadioButton *button=qobject_cast<QRadioButton*>(QObject::sender());
    if(button==ui->RGB){emit imgFilter(state::RGB);}
    else if (button==ui->GRAY){emit imgFilter(state::Gray);}
    else if (button==ui->THRESH) {emit imgFilter(state::Threshold);}
    button=nullptr;
    delete button;
}

CamScene::CamScene(QWidget *parent)
{

}

void CamScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> itemlist=this->items();
    bool item_under_mouse=true;
    for(const auto it:qAsConst(itemlist)){if(it->isUnderMouse()){item_under_mouse=true; break;}}
    if(event->button()==Qt::LeftButton && item_under_mouse)
    {
        FRAME* F=new FRAME();
        F->setPos(event->scenePos().x(),event->scenePos().y());
        F->setZValue(0.2);
        this->addItem(F);
    }
}

void CamScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

void MainWindow::on_toolButton_pressed()// save
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("Save File"),
                                                  "./scripts",
                                                  tr("Traces (*.bin)"));
    ui->lineEdit_3->setText(fileName);
    filehandler->setFileName(fileName);
}

void MainWindow::on_toolButton_2_pressed()// open
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "./scripts",
                                                      tr("Traces (*.bin)"));
    ui->lineEdit_4->setText(fileName);
}

