#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      leftCAM(new CamScene(camera::left)),
      rightCAM(new CamScene(camera::right)),
      leftsock(Q_NULLPTR),
      p(),
      pixImg(),
      ImgGetLeft(Q_NULLPTR),
      ImgGetRight(Q_NULLPTR),
      leftpix(Q_NULLPTR),
      rightpix(Q_NULLPTR),
      filehandler(new FileHandler()),
      frame_timer(new QTimer()),
      video_timer(new QTimer()),
      lthread(Q_NULLPTR),
      rthread(Q_NULLPTR),
      file_handler_thread(new QThread()),
      map(new QQuickWidget(this)),
      modifier(Q_NULLPTR),
      video_play(true),
      firstLat(),
      firstLon(),
      secondLat(),
      secondLon(),
      canAddMarker(true),
      leftframe(),
      rightframe(),
      converter(),
      tmpcase(new TemplateCase()),
      reader(new template_reader()),
      opacityPrev(new QGraphicsOpacityEffect(this)),
      opacityPlay(new QGraphicsOpacityEffect(this)),
      opacityNext(new QGraphicsOpacityEffect(this)),
      opacityPlayer(new QGraphicsOpacityEffect(this)),
      hiddenOpacity(0.2),
      defaultOpacity(1.0),
      frameMap()
{
    ui->setupUi(this);
    leftCAM->setBackgroundBrush(Qt::black);
    rightCAM->setBackgroundBrush(Qt::black);
    ui->graphicsViewCamRight->setLayoutDirection(Qt::RightToLeft);
    ui->graphicsViewCamLeft->setScene(leftCAM);
    ui->graphicsViewCamRight->setScene(rightCAM);
    leftCAM->setSceneRect(-2000,-2000,4000,4000);
    rightCAM->setSceneRect(-2000,-2000,4000,4000);
    opacityPrev->setOpacity(this->hiddenOpacity);
    ui->toolButtonPrev->setDisabled(true);
    ui->toolButtonPrev->setGraphicsEffect(opacityPrev);
    ui->toolButtonPrev->setAutoFillBackground(true);
    opacityPlay->setOpacity(this->hiddenOpacity);
    ui->toolButtonPlay->setDisabled(true);
    ui->toolButtonPlay->setGraphicsEffect(opacityPlay);
    ui->toolButtonPlay->setAutoFillBackground(true);
    opacityNext->setOpacity(this->hiddenOpacity);
    ui->toolButtonNext->setDisabled(true);
    ui->toolButtonNext->setGraphicsEffect(opacityNext);
    ui->toolButtonNext->setAutoFillBackground(true);
    opacityPlayer->setOpacity(this->hiddenOpacity);
    ui->horizontalSliderPlayer->setDisabled(true);
    ui->horizontalSliderPlayer->setGraphicsEffect(opacityPlayer);
    ui->horizontalSliderPlayer->setMinimum (0);
    connect(ui->RGB,&QRadioButton::toggled,this,&MainWindow::imageFilter);
    connect(ui->GRAY,&QRadioButton::toggled,this,&MainWindow::imageFilter);
    connect(ui->THRESH,&QRadioButton::toggled,this,&MainWindow::imageFilter);
    map->setSource(QUrl("qrc:/main.qml"));
    map->setResizeMode(QQuickWidget::SizeRootObjectToView);
    ui->gridLayout->addWidget(map);
    ui->tabWidget->setTabText(0, "Cams");
    ui->tabWidget->setTabText(1, "Map|Graph");
    ui->lineEditRtspLeft->setText("rtsp://admin:qwerty1234@192.168.0.102:554/ISAPI/Streaming/Channels/101");
    ui->lineEditRtspRight->setText("rtsp://admin:qwerty1234@192.168.0.103:554/ISAPI/Streaming/Channels/101");
    filehandler->moveToThread(file_handler_thread);
    connect(filehandler,&FileHandler::Status,this,&MainWindow::IndexingStatus);
    connect(file_handler_thread,&QThread::started,filehandler,&FileHandler::start);
    file_handler_thread->start();
    connect(filehandler,&FileHandler::readImageleft,this,&MainWindow::loadImgLeft);
    connect(filehandler,&FileHandler::readImageRight,this,&MainWindow::loadImgRight);
    frame_timer->setInterval(100);
    video_timer->setInterval(100);
    connect(video_timer,&QTimer::timeout,this,[this]()
    {
        image_saving_protocol p;
        filehandler->matRead(p,frame_state::next);
        ui->horizontalSliderPlayer->setValue(ui->horizontalSliderPlayer->value()+1);
    });
    init3DGraph();
    leftCAM->setItemIndexMethod(QGraphicsScene::NoIndex);
    auto TMP = reader->templates(template_type::BIRD);
    tmpcase->set_template(TMP);
    ui->gridLayoutTemplates->addWidget(tmpcase);
    if(ImgGetLeft == Q_NULLPTR)
    {
        ImgGetLeft = new ImgData(1,ui->lineEditRtspLeft->text());
        ImgGetLeft->SetIncludedNumList(tmpcase->includedtmp());
        ImgGetLeft->SetTemplatesImages(reader->tmp());
        //ImgGetLeft->setFileHandler(this->filehandler);
        lthread = new QThread(this);
        ImgGetLeft->moveToThread(lthread);
        connect(ImgGetLeft,&ImgData::Image,this,&MainWindow::loadImgLeft);
        connect(this,&MainWindow::thresHold,ImgGetLeft,&ImgData::setThresHold);
        connect(this,&MainWindow::imgFilter,ImgGetLeft,&ImgData::imgFilter);
        connect(frame_timer,&QTimer::timeout,ImgGetLeft,&ImgData::Get);
        connect(ImgGetLeft,&ImgData::set_image_data,filehandler,&FileHandler::Save);
        connect(this,&MainWindow::image_cut,ImgGetLeft,&ImgData::img_cut);
        connect(lthread,&QThread::started,ImgGetLeft,&ImgData::Start);
        lthread->start();
        frame_timer->start();
    }
    if(ImgGetRight == Q_NULLPTR)
    {
        ImgGetRight = new ImgData(2,ui->lineEditRtspRight->text());
        ImgGetRight->SetIncludedNumList(tmpcase->includedtmp());
        ImgGetRight->SetTemplatesImages(reader->tmp());
        rthread = new QThread(this);
        ImgGetRight->moveToThread(rthread);
        connect(ImgGetRight,&ImgData::Image,this,&MainWindow::loadImgRight);
        connect(this,&MainWindow::thresHold,ImgGetRight,&ImgData::setThresHold);
        connect(this,&MainWindow::imgFilter,ImgGetRight,&ImgData::imgFilter);
        connect(frame_timer,&QTimer::timeout,ImgGetRight,&ImgData::Get);
        connect(ImgGetRight,&ImgData::set_image_data,filehandler,&FileHandler::Save);
        connect(this,&MainWindow::image_cut,ImgGetRight,&ImgData::img_cut);
        connect(rthread,&QThread::started,ImgGetRight,&ImgData::Start);
        rthread->start();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadImgLeft(QPixmap piximg)
{
    if(leftpix != Q_NULLPTR){leftCAM->removeItem(leftpix); /*leftCAM->clear(); */delete leftpix;}
    leftpix = leftCAM->addPixmap(piximg);    
    leftpix->setData(1,1);
    leftpix->setPos(-960,-540);
    leftCAM->setCurrentPixMap(piximg);
    leftCAM->update ();
    //piximg.save("saving_img.png","PNG");
}

void MainWindow::loadImgRight(QPixmap piximg)
{
    if(rightpix != Q_NULLPTR){rightCAM->removeItem(rightpix);/*rightCAM->clear();*/ delete rightpix;}
    rightpix = rightCAM->addPixmap(piximg);
    rightpix->setData(1,1);
    rightpix->setPos(-960,-540);
    rightCAM->setCurrentPixMap(piximg);
    rightCAM->update();
}

void MainWindow::IndexingStatus(QPoint p)
{
    ui->progressBar->setMaximum(p.x());
    ui->progressBar->setValue(p.y());
}

void MainWindow::PixMapCut()
{
    auto leftPix = leftCAM->getCurrentPixMap();
    auto rightPix = rightCAM->getCurrentPixMap();
    auto it = leftframe.find(MainWindow::frame_counter);
    if(it != leftframe.end())
    {       
        for(auto itFrame : qAsConst(it.value()))
        {
            auto templ = leftPix.copy(
                       960+itFrame->pos().x()-itFrame->boundingRect().width()/2,
                       540+itFrame->pos().y()-itFrame->boundingRect().height()/2,
                        itFrame->boundingRect().width(),
                        itFrame->boundingRect().height());
            auto name = QUuid::createUuid();
            templ.save("./template_images/"+name.toString()+".jpg","JPG");
        }
    }
    it = rightframe.find(MainWindow::frame_counter);
    if(it != rightframe.end())
    {
        for(auto itFrame : qAsConst(it.value()))
        {
            auto templ = rightPix.copy(
                        960+itFrame->pos().x()-itFrame->boundingRect().width()/2,
                        540+itFrame->pos().y()-itFrame->boundingRect().height()/2,
                        itFrame->boundingRect().width(),
                        itFrame->boundingRect().height());
            auto name = QUuid::createUuid();
            templ.save("./template_images/"+name.toString()+".jpg","JPG");
        }
    }
}

void MainWindow::setTheme(QString themeName)
{
    QFile file("./themes/" + themeName + ".qss");
    file.open(QFile::ReadOnly);
    qApp->setStyleSheet(QString::fromLatin1(file.readAll()));
}

void MainWindow::on_toolButtonNext_clicked()
{
    if(leftCAM->getFrame().length() > 0)
    {
        leftframe.insert(MainWindow::frame_counter,leftCAM->getFrame());
        rightframe.insert(MainWindow::frame_counter,rightCAM->getFrame());
        To3D();
        PixMapCut();
    }
    MainWindow::frame_counter++;
    image_saving_protocol p;
    filehandler->matRead(p,frame_state::next);
    ui->horizontalSliderPlayer->setValue(ui->horizontalSliderPlayer->value()+1);
    MainWindow::frame_num++;
}

void MainWindow::on_toolButtonPlay_clicked()
{
    if(video_play)
    {
        video_timer->start();
        video_play = false;
    }
    else
    {
        video_timer->stop();
        video_play = true;
    }
}

void MainWindow::on_toolButtonPrev_clicked()
{
    image_saving_protocol p;
    filehandler->matRead(p,frame_state::previos);
    ui->horizontalSliderPlayer->setValue(ui->horizontalSliderPlayer->value()-1);
    MainWindow::frame_num--;
    MainWindow::frame_counter--;
    for(int i = 0; i < leftframe[MainWindow::frame_counter].length(); ++i)
    {
        leftCAM->addItem(leftframe[MainWindow::frame_counter][i]);
        rightCAM->addItem(rightframe[MainWindow::frame_counter][i]);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Minus){ui->graphicsViewCamLeft->scale(0.5,0.5);ui->graphicsViewCamRight->scale(0.5,0.5);}
    if(event->key() == Qt::Key_Plus){ui->graphicsViewCamLeft->scale(2,2);ui->graphicsViewCamRight->scale(2,2);}
}

void MainWindow::addMixmap(QByteArray &data)
{
    auto m = QImage::fromData(data);
    p.fromImage(m);
    leftCAM->addPixmap(p);
    leftCAM->update();
}

void MainWindow::on_horizontalSliderBlsize_valueChanged(int value)// bs
{
    emit thresHold(value,static_cast<double>(ui->horizontalSliderC->value()));
}

void MainWindow::on_horizontalSliderC_valueChanged(int value) //c
{ 
    emit thresHold(ui->horizontalSliderBlsize->value(),static_cast<double>(value));
}

void MainWindow::imageFilter()
{
    auto button = qobject_cast<QRadioButton*>(QObject::sender());
    if(button == ui->RGB) emit imgFilter(state::RGB);
    else if (button == ui->GRAY) emit imgFilter(state::Gray);
    else if (button == ui->THRESH) emit imgFilter(state::Threshold);
    button = nullptr;
    delete button;
}

CamScene::CamScene(camera cam, QWidget* parent)
    : QGraphicsScene(parent),
      current_camera(cam),
      frames(),
      currentPixMap(),
      grabToggled(false),
      item_under_mouse(true)
{}

void CamScene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    auto itemlist = this->items();
    item_under_mouse = true;
    for(auto it : itemlist)
    {
        if(it->isUnderMouse() && it->data(1).toInt() == 2)
        {
            item_under_mouse = false;
            break;
        }
    }
    if(event->button() == Qt::LeftButton && item_under_mouse)
    {
        auto F = new FRAME(frames.length()+1);
        F->setData(1,2);
        F->setPos(event->scenePos().x(),event->scenePos().y());
        F->setZValue(0.2);
        this->addItem(F);
        this->frames.push_back(F);
    }
    else if(event->button() == Qt::LeftButton && !item_under_mouse)
    {
        for(auto it : itemlist)
        {
            if(it->isUnderMouse())
            {
                it->setCursor(QCursor(Qt::ClosedHandCursor));
                it->grabMouse();
                grabToggled = true;
            }
        }
    }
    else if(event->button() == Qt::RightButton)
    {
        for(auto it : frames)
        {
            if(it->isUnderMouse())
            {
                frames.removeOne(it);
                it->deleteLater();
                break;
            }
            else continue;
        }
    }
}

void CamScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    auto itemlist = this->items();
    if(event->button() == Qt::LeftButton && grabToggled)
    {
        for(auto it : itemlist)
        {
            if(it->isUnderMouse())
            {
                it->setCursor(QCursor(Qt::ArrowCursor));
                it->ungrabMouse();
            }
        }
        grabToggled = false;
    }
}

void MainWindow::on_toolButtonSave_pressed()// save
{
    auto fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                  "./record",
                                                  tr("Vids (*.bin)"));
    if(!fileName.isEmpty())
    {
        ui->lineEditSave->setText(fileName);
        filehandler->setNameOfFile(fileName);
        ui->toolButtonPrev->setDisabled(true);
        opacityPrev->setOpacity(this->hiddenOpacity);
        ui->toolButtonPlay->setDisabled(true);
        opacityPlay->setOpacity(this->hiddenOpacity);
        ui->toolButtonNext->setDisabled(true);
        opacityNext->setOpacity(this->hiddenOpacity);
        ui->horizontalSliderPlayer->setDisabled(true);
        opacityPlayer->setOpacity(this->hiddenOpacity);
    }
}

void MainWindow::on_toolButtonOpen_pressed()// open
{
    auto fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      "./record",
                                                      tr("Vids (*.bin)"));
    if(!fileName.isEmpty())
    {
        ui->lineEditOpen->setText(fileName);
        filehandler->setNameOfFile(fileName);
        ui->horizontalSliderPlayer->setMaximum((int)(filehandler->getFrameByteIndex().size()/2));
        ui->toolButtonPrev->setDisabled(false);
        opacityPrev->setOpacity(this->defaultOpacity);
        ui->toolButtonPlay->setDisabled(false);
        opacityPlay->setOpacity(this->defaultOpacity);
        ui->toolButtonNext->setDisabled(false);
        opacityNext->setOpacity(this->defaultOpacity);
        ui->horizontalSliderPlayer->setDisabled(false);
        opacityPlayer->setOpacity(this->defaultOpacity);
    }
}

void MainWindow::on_pushButtonApply_clicked()
{
    if(this->canAddMarker)
    {
        firstLat = ui->doubleSpinBoxLatLeft->value ();
        secondLat = ui->doubleSpinBoxLatRight->value ();
        firstLon = ui->doubleSpinBoxLonLeft->value ();
        secondLon = ui->doubleSpinBoxLonRight->value ();
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

void MainWindow::on_pushButtonDelete_clicked()
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

void MainWindow::on_pushButtonMove_clicked()
{
    firstLat = ui->doubleSpinBoxLatLeft->value ();
    secondLat = ui->doubleSpinBoxLatRight->value ();
    firstLon = ui->doubleSpinBoxLonLeft->value ();
    secondLon = ui->doubleSpinBoxLonRight->value ();
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

void MainWindow::on_spinBoxRotLeft_valueChanged(int arg1)// cam left
{
    QMetaObject::invokeMethod (map->rootObject (),"rotate",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,0),
                               Q_ARG(QVariant,arg1));

}

void MainWindow::on_spinBoxRotRight_valueChanged(int arg1) //cam right
{
    QMetaObject::invokeMethod (map->rootObject (),"rotate",
                               Qt::DirectConnection,
                               Q_ARG(QVariant,1),
                               Q_ARG(QVariant,arg1));

}

void MainWindow::init3DGraph()
{
    auto graph = new Q3DScatter();
    auto container = QWidget::createWindowContainer(graph);
    if (!graph->hasContext())
    {
        QMessageBox::information(this, "Error", "Couldn't initialize the OpenGL context.");
    }
    auto widget = new QWidget();
    auto hLayout = new QHBoxLayout(widget);
    auto vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    widget->setWindowTitle(QStringLiteral("A Cosine Wave"));
    auto labelButton = new QPushButton(widget);
    labelButton->setText(QStringLiteral("Change label style"));
    auto cameraButton = new QPushButton(widget);
    cameraButton->setText(QStringLiteral("Change camera preset"));
    auto clearButton = new QPushButton(widget);
    clearButton->setText(QStringLiteral("Clear"));
    auto backgroundCheckBox = new QCheckBox(widget);
    backgroundCheckBox->setText(QStringLiteral("Show background"));
    backgroundCheckBox->setChecked(true);
    auto gridCheckBox = new QCheckBox(widget);
    gridCheckBox->setText(QStringLiteral("Show grid"));
    gridCheckBox->setChecked(true);
    vLayout->addWidget(labelButton, 0, Qt::AlignTop);
    vLayout->addWidget(cameraButton, 0, Qt::AlignTop);
    vLayout->addWidget(clearButton, 0, Qt::AlignTop);
    vLayout->addWidget(backgroundCheckBox);
    vLayout->addWidget(gridCheckBox);
    modifier = new ScatterDataModifier(graph);
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
    QObject::connect(modifier, &ScatterDataModifier::backgroundEnabledChanged,
                     backgroundCheckBox, &QCheckBox::setChecked);
    QObject::connect(modifier, &ScatterDataModifier::gridEnabledChanged,
                     gridCheckBox, &QCheckBox::setChecked);
    QObject::connect(graph, &Q3DScatter::shadowQualityChanged, modifier,
                     &ScatterDataModifier::shadowQualityUpdatedByVisual);
    ui->verticalLayout_9->addWidget(widget);
    vLayout->setAlignment(Qt::AlignTop);
    widget->show();  
}

void MainWindow::To3D()
{
    QVector<QPoint> R;
    QVector<QPoint> L;
    for(int i = 0; i < leftframe[frame_counter].length(); i++)
    {
        R.push_back(QPoint());
        L.push_back(QPoint());
        R[i].setX(rightframe[frame_counter][i]->pos().x());
        R[i].setY(0-rightframe[frame_counter][i]->pos().y());
        L[i].setX(leftframe[frame_counter][i]->pos().x());
        L[i].setY(0-leftframe[frame_counter][i]->pos().y());
    }
    converter.Start(R, L);
    modifier->AddData(converter.getVec3D());
    converter.Clear();
}

void MainWindow::on_doubleSpinBoxRange_valueChanged(double arg1)
{
    converter.setRangeCam(arg1);
}

void MainWindow::on_doubleSpinBoxAngle_valueChanged(double arg1)
{
    converter.setAngle(arg1);
}

void MainWindow::on_comboBoxTheme_textActivated(const QString &arg1)
{
    if (arg1 == "Default")
    {
        qApp->setStyleSheet("");
    }
    else setTheme(arg1);
}

void MainWindow::on_comboBoxStyle_textActivated(const QString &arg1)
{
    qApp->setStyle(arg1);
}

void MainWindow::on_doubleSpinBoxBAngle_valueChanged(double arg1)
{
    converter.setBtwangle(arg1);
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    emit image_cut(1080-value);
}

void MainWindow::on_dial_valueChanged(int value)
{
    frame_timer->setInterval(1000/value);
    video_timer->setInterval(1000/value);
    ui->label_4->setText(QString::number(value));
}

