#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QThread>
#include <QFileDialog>

int frame_counter=0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    leftCAM = new CamScene(camera::left,ui->graphicsView);

    rightCAM = new CamScene(camera::right,ui->graphicsView_2);

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
    this->canAddMarker = true;
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
    initialize_3d_graph();
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
    leftpix->setData(1,1);
    leftpix->setPos(-960,-540);
    leftCAM->update ();
}

void MainWindow::loadImgRight(QPixmap piximg)
{
    if(rightpix != nullptr){rightCAM->removeItem(rightpix);rightCAM->clear(); delete rightpix;}
    rightpix = rightCAM->addPixmap(piximg);
    rightpix->setData(1,1);
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

    leftframe[frame_counter].append(leftCAM->get_frame());

    rigtframe[frame_counter].append(rightCAM->get_frame());

    qDebug()<<rigtframe[frame_counter].last()->pos();

    qDebug()<<rigtframe[frame_counter].length()<<" skoka framov";

    to_3d();

    leftCAM->clear_frames();

    rightCAM->clear_frames();


    //converter.

    frame_counter++;
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
    frame_counter--;
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

CamScene::CamScene(camera cam, QWidget *parent)
{
    this->current_camera=cam;

}

QVector<FRAME *> CamScene::get_frame()
{
    return frames;
}

void CamScene::clear_frames()
{
    this->frames.clear();
}

void CamScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QList<QGraphicsItem*> itemlist = this->items();
    bool item_under_mouse = true;
    for(const auto it:qAsConst(itemlist)){if(it->isUnderMouse() && it->data(1).toInt()==2){item_under_mouse = false; break;}}
    if(event->button() == Qt::LeftButton && item_under_mouse)
    {
        FRAME* F = new FRAME();
        F->setData(1,2);
        F->setPos(event->scenePos().x(),event->scenePos().y());
        F->setZValue(0.2);
        this->addItem(F);
        this->frames.push_back(F);
    }

    if(event->button()==Qt::RightButton){

        for(int i=0;i<frames.length();i++){if(frames[i]->isUnderMouse()){frames[i]->deleteLater(); frames.remove(i);break;}else{continue;}}


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
    if(this->canAddMarker)
    {
        firstLat = ui->doubleSpinBox->value ();
        secondLat = ui->doubleSpinBox_4->value ();
        firstLon = ui->doubleSpinBox_2->value ();
        secondLon = ui->doubleSpinBox_3->value ();
        QMetaObject::invokeMethod (map->rootObject (),"addMarker",
                                   Qt::DirectConnection,
                                   Q_ARG(QVariant,firstLat),
                                   Q_ARG(QVariant,firstLon),
                                   Q_ARG(QVariant,0));
        QMetaObject::invokeMethod (map->rootObject (),"addMarker",
                                   Qt::DirectConnection,
                                   Q_ARG(QVariant,secondLat),
                                   Q_ARG(QVariant,secondLon),
                                   Q_ARG(QVariant,0));
    }
    this->canAddMarker = false;
}

void MainWindow::on_pushButton_2_clicked()
{
    QMetaObject::invokeMethod (map->rootObject (),"delMarker",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,firstLat),
                               Q_ARG(QVariant,firstLon));
    QMetaObject::invokeMethod (map->rootObject (),"delMarker",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,secondLat),
                               Q_ARG(QVariant,secondLon));
    this->canAddMarker = true;
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

void MainWindow::on_spinBox_valueChanged(int arg1)// cam 1
{
    QMetaObject::invokeMethod (map->rootObject (),"rotate",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,0),
                               Q_ARG(QVariant,arg1));

}


void MainWindow::on_spinBox_2_valueChanged(int arg1) //cam 2
{
    QMetaObject::invokeMethod (map->rootObject (),"rotate",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,1),
                               Q_ARG(QVariant,arg1));

}

void MainWindow::initialize_3d_graph()
{

    Q3DScatter *graph = new Q3DScatter();
    QWidget *container = QWidget::createWindowContainer(graph);
    //! [0]

    if (!graph->hasContext()) {
        QMessageBox msgBox;
        msgBox.setText("Couldn't initialize the OpenGL context.");
        msgBox.exec();

    }


    //! [1]
    QWidget *widget = new QWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    //! [1]

    widget->setWindowTitle(QStringLiteral("A Cosine Wave"));

    //! [4]
    QComboBox *themeList = new QComboBox(widget);
    themeList->addItem(QStringLiteral("Qt"));
    themeList->addItem(QStringLiteral("Primary Colors"));
    themeList->addItem(QStringLiteral("Digia"));
    themeList->addItem(QStringLiteral("Stone Moss"));
    themeList->addItem(QStringLiteral("Army Blue"));
    themeList->addItem(QStringLiteral("Retro"));
    themeList->addItem(QStringLiteral("Ebony"));
    themeList->addItem(QStringLiteral("Isabelle"));
    themeList->setCurrentIndex(6);

    QPushButton *labelButton = new QPushButton(widget);
    labelButton->setText(QStringLiteral("Change label style"));


    QPushButton *cameraButton = new QPushButton(widget);
    cameraButton->setText(QStringLiteral("Change camera preset"));

    QPushButton *clearButton = new QPushButton(widget);
    clearButton->setText(QStringLiteral("Clear"));

    QPushButton *viewButton=new QPushButton(widget);
    viewButton->setText("View in 3D");

    QCheckBox *backgroundCheckBox = new QCheckBox(widget);
    backgroundCheckBox->setText(QStringLiteral("Show background"));
    backgroundCheckBox->setChecked(true);

    QCheckBox *gridCheckBox = new QCheckBox(widget);
    gridCheckBox->setText(QStringLiteral("Show grid"));
    gridCheckBox->setChecked(true);




    //! [4]

    //! [5]
    vLayout->addWidget(labelButton, 0, Qt::AlignTop);
    vLayout->addWidget(cameraButton, 0, Qt::AlignTop);
    vLayout->addWidget(viewButton,0,Qt::AlignTop);
    vLayout->addWidget(clearButton, 0, Qt::AlignTop);
    vLayout->addWidget(backgroundCheckBox);
    vLayout->addWidget(gridCheckBox);



    vLayout->addWidget(new QLabel(QStringLiteral("Change theme")));
    vLayout->addWidget(themeList);




    //! [5]

    //! [2]
    modifier = new ScatterDataModifier(graph);
    //! [2]

    //! [6]
    QObject::connect(cameraButton, &QPushButton::clicked, modifier,
                     &ScatterDataModifier::changePresetCamera);
    QObject::connect(labelButton, &QPushButton::clicked, modifier,
                     &ScatterDataModifier::changeLabelStyle);
    QObject::connect(clearButton, &QPushButton::clicked, modifier,
                     &ScatterDataModifier::clear);

    QObject::connect(backgroundCheckBox, &QCheckBox::stateChanged, modifier,
                     &ScatterDataModifier::setBackgroundEnabled);
    QObject::connect(gridCheckBox, &QCheckBox::stateChanged, modifier,
                     &ScatterDataModifier::setGridEnabled);
   // QObject::connect(smoothCheckBox, &QCheckBox::stateChanged, modifier,
     //                &ScatterDataModifier::setSmoothDots);

    QObject::connect(modifier, &ScatterDataModifier::backgroundEnabledChanged,
                     backgroundCheckBox, &QCheckBox::setChecked);
    QObject::connect(modifier, &ScatterDataModifier::gridEnabledChanged,
                     gridCheckBox, &QCheckBox::setChecked);
   // QObject::connect(itemStyleList, SIGNAL(currentIndexChanged(int)), modifier,
       //              SLOT(changeStyle(int)));

    QObject::connect(themeList, SIGNAL(currentIndexChanged(int)), modifier,
                     SLOT(changeTheme(int)));


    QObject::connect(graph, &Q3DScatter::shadowQualityChanged, modifier,
                     &ScatterDataModifier::shadowQualityUpdatedByVisual);




    //! [6]

    //! [3]

    //ui->verticalLayout->addWidget(widget);

    ui->gridLayout_2->addWidget(widget);
    //widget->resize(800,500);
    widget->show();

    vLayout->setAlignment(Qt::AlignTop);

}

void MainWindow::to_3d()
{
    QVector<int> px;
    QVector<int> py;
    QVector<int> lx;
    QVector<int> ly;
    for(int i=0;i<leftframe[frame_counter].length();i++){
        px.append(rigtframe[frame_counter][i]->pos().x());
        qDebug()<<px.last()<<"lst";
        py.append(rigtframe[frame_counter][i]->pos().y());
        lx.append(leftframe[frame_counter][i]->pos().x());
        ly.append(leftframe[frame_counter][i]->pos().y());
    }
    converter.Start(px,py,lx,ly);
    modifier->add_data(converter.getX(),converter.getY(),converter.getH3());
    converter.Clear();

}

