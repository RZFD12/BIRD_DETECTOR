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
    leftCAM = new CamScene(ui->graphicsView);
    rightCAM = new CamScene(ui->graphicsView_2);
    leftCAM->setBackgroundBrush(Qt::black);
    rightCAM->setBackgroundBrush(Qt::black);
    ui->graphicsView->setScene(leftCAM);
    ui->graphicsView_2->setScene(rightCAM);
    leftCAM->setSceneRect(-2000,-2000,4000,4000);
    rightCAM->setSceneRect(-2000,-2000,4000,4000);
    connect(ui->RGB,&QRadioButton::toggled,this,&MainWindow::imageFilter);
    connect(ui->GRAY,&QRadioButton::toggled,this,&MainWindow::imageFilter);
    connect(ui->THRESH,&QRadioButton::toggled,this,&MainWindow::imageFilter);
    map = new QQuickWidget(this);
    map->setSource(QUrl("qrc:/main.qml"));
    map->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->gridLayout->addWidget(map);
    ui->lineEdit->setText("rtsp://admin:qwerty1234@169.254.111.243:554/ISAPI/Streaming/Channels/101");
    ui->lineEdit_2->setText("rtsp://admin:qwerty1234@169.254.111.244:554/ISAPI/Streaming/Channels/101");
    filehandler = new FileHandler();
    QThread *file_handler_thread=new QThread();
    filehandler->moveToThread(file_handler_thread);
    connect(filehandler,&FileHandler::Status,this,&MainWindow::IndexingStatus);
    connect(file_handler_thread,&QThread::started,filehandler,&FileHandler::start);
    file_handler_thread->start();
    connect(filehandler,&FileHandler::readImageleft,this,&MainWindow::loadImgLeft);
    connect(filehandler,&FileHandler::readImageRight,this,&MainWindow::loadImgRight);
    frame_timer=new QTimer();
    frame_timer->setInterval(250);
    video_timer=new QTimer();
    video_timer->setInterval(250);
    connect(video_timer,&QTimer::timeout,this,[this]()
    {
        image_saving_protocol p;
        filehandler->matRead(p,frame_state::next);
    });
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
    if(leftpix != nullptr){leftCAM->removeItem(leftpix); leftCAM->clear(); delete leftpix;}
    leftpix = leftCAM->addPixmap(piximg);
    leftpix->setPos(-960,-540);
    leftCAM->update ();
}

void MainWindow::loadImgRight(QPixmap piximg)
{
    if(rightpix != nullptr){rightCAM->removeItem(rightpix);rightCAM->clear(); delete rightpix;}
    rightpix = rightCAM->addPixmap(piximg);
    rightpix->setPos(-960,-540);
    rightCAM->update();
}

void MainWindow::IndexingStatus(QPoint p)
{
    ui->progressBar->setMaximum(p.x());
    ui->progressBar->setValue(p.y());
}

void MainWindow::on_lineEdit_editingFinished()// left
{
    if(ImgGetLeft == nullptr)
    {
        ImgGetLeft = new ImgData(1,ui->lineEdit->text().toStdString());
        ImgGetLeft->setFileHandler(this->filehandler);
        QThread *lthread = new QThread(this);
        ImgGetLeft->moveToThread(lthread);
        connect(ImgGetLeft,&ImgData::Image,this,&MainWindow::loadImgLeft);
        connect(this,&MainWindow::thresHold,ImgGetLeft,&ImgData::setThresHold);
        connect(this,&MainWindow::imgFilter,ImgGetLeft,&ImgData::imgFilter);
        connect(frame_timer,&QTimer::timeout,ImgGetLeft,&ImgData::Get);
        connect(ImgGetLeft,&ImgData::set_image_data,filehandler,&FileHandler::Save);
        connect(lthread,&QThread::started,ImgGetLeft,&ImgData::Start);
        lthread->start();
        frame_timer->start();
    }
}

void MainWindow::on_lineEdit_2_editingFinished() //right
{
    if(ImgGetRight == nullptr)
    {
        ImgGetRight = new ImgData(2,ui->lineEdit_2->text().toStdString());
        QThread *rthread = new QThread(this);
        ImgGetRight->moveToThread(rthread);
        connect(ImgGetRight,&ImgData::Image,this,&MainWindow::loadImgRight);
        connect(this,&MainWindow::thresHold,ImgGetRight,&ImgData::setThresHold);
        connect(this,&MainWindow::imgFilter,ImgGetRight,&ImgData::imgFilter);
        connect(frame_timer,&QTimer::timeout,ImgGetRight,&ImgData::Get);
        connect(ImgGetRight,&ImgData::set_image_data,filehandler,&FileHandler::Save);
        connect(rthread,&QThread::started,ImgGetRight,&ImgData::Start);
        rthread->start();
    }
}

void MainWindow::on_nextButton_clicked()
{
    image_saving_protocol p;
    filehandler->matRead(p,frame_state::next);
    frame_num++;
}

void MainWindow::on_playButton_clicked()
{
    if(video_play)
    {
        video_timer->start();
        video_play=false;
    }
    else
    {
        video_timer->stop();
        video_play=true;
    }
}

void MainWindow::on_prevButton_clicked()     
{
    image_saving_protocol p;
    filehandler->matRead(p,frame_state::previos);
    frame_num--;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Minus){ui->graphicsView->scale(0.5,0.5);ui->graphicsView_2->scale(0.5,0.5);}
    if(event->key() == Qt::Key_Plus){ui->graphicsView->scale(2,2);ui->graphicsView_2->scale(2,2);}
}

void MainWindow::addMixmap(QByteArray &data)
{
    QByteArray b2 = QByteArray::fromBase64(data);
    QImage m = QImage::fromData(data);
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
    int bs = ui->horizontalSlider->value();
    emit thresHold(bs,static_cast<double>(value));
}

void MainWindow::imageFilter()
{
    QRadioButton *button=qobject_cast<QRadioButton*>(QObject::sender());
    if(button == ui->RGB){emit imgFilter(state::RGB);}
    else if (button == ui->GRAY){emit imgFilter(state::Gray);}
    else if (button == ui->THRESH) {emit imgFilter(state::Threshold);}
    button=nullptr;
    delete button;
}

CamScene::CamScene(QWidget *parent)
{

}

void CamScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> itemlist = this->items();
    bool item_under_mouse = true;
    for(const auto it:qAsConst(itemlist)){if(it->isUnderMouse()){item_under_mouse = true; break;}}
    if(event->button() == Qt::LeftButton && item_under_mouse)
    {
        FRAME* F = new FRAME();
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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                  "./record",
                                                  tr("Vids (*.bin)"));
    ui->lineEdit_3->setText(fileName);
    filehandler->setFileName(fileName);
}

void MainWindow::on_toolButton_2_pressed()// open
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "./record",
                                                      tr("Vids (*.bin)"));
    ui->lineEdit_4->setText(fileName);
    filehandler->setFileName(fileName);
}

void MainWindow::on_pushButton_clicked()
{
    firstLat = ui->doubleSpinBox->value ();
    secondLat = ui->doubleSpinBox_4->value ();
    firstLon = ui->doubleSpinBox_2->value ();
    secondLon = ui->doubleSpinBox_3->value ();
    QMetaObject::invokeMethod (map->rootObject (),"addMarker",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,firstLat),
                               Q_ARG(QVariant,firstLon));
    QMetaObject::invokeMethod (map->rootObject (),"addMarker",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,secondLat),
                               Q_ARG(QVariant,secondLon));
}

void MainWindow::on_pushButton_2_clicked()
{
    QMetaObject::invokeMethod (map->rootObject (),"delMarkers",
                               Qt::DirectConnection);
}

void MainWindow::on_pushButton_3_clicked()
{
    firstLat = ui->doubleSpinBox->value ();
    secondLat = ui->doubleSpinBox_4->value ();
    firstLon = ui->doubleSpinBox_2->value ();
    secondLon = ui->doubleSpinBox_3->value ();
    QMetaObject::invokeMethod (map->rootObject (),"moveMarker",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,0),
                               Q_ARG(QVariant,firstLat),
                               Q_ARG(QVariant,firstLon));
    QMetaObject::invokeMethod (map->rootObject (),"moveMarker",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,1),
                               Q_ARG(QVariant,secondLat),
                               Q_ARG(QVariant,secondLon));
}
