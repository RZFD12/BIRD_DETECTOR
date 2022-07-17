#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <frame.h>
#include "imgdata.h"
#include <QMainWindow>
#include <QGraphicsSceneEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMap>
#include <QUdpSocket>
#include <QPixmap>
#include <QtQuickWidgets/QQuickWidget>
#include <QQuickItem>
#include <QQmlContext>
#include <QtPositioning>

#include <QPair>
<<<<<<< Updated upstream
=======
#include <QGraphicsEffect>
#include <QImage>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QThread>
#include <QFileDialog>
#include <QVector3D>
#include <QUuid>
>>>>>>> Stashed changes

#include <scatterdatamodifier.h>

#include <flatto3d.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CamScene :public QGraphicsScene
{
    Q_OBJECT
public:
<<<<<<< Updated upstream

    CamScene(camera cam,QWidget*parent=nullptr);

    QVector<FRAME*> get_frame();

    void clear_frames();

private:
    camera current_camera;

    QVector<FRAME*> frames;


private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
=======
    CamScene(camera cam, QWidget* parent = Q_NULLPTR);
    inline const QVector<FRAME*> getFrame() const { return frames; }
    inline const QPixmap &getCurrentPixMap() const { return currentPixMap; }
    inline void setCurrentPixMap(const QPixmap& newCurrentPixMap) { currentPixMap = newCurrentPixMap; }
    inline bool isGrabToggled(){ return grabToggled; }
    inline void clearFrames() { frames.clear(); }

private:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    camera current_camera;
    QVector<FRAME*> frames;
    QPixmap currentPixMap;
    bool grabToggled;
    bool item_under_mouse;
>>>>>>> Stashed changes
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< Updated upstream
    MainWindow(QWidget *parent = nullptr);
=======
    MainWindow(QWidget* parent = Q_NULLPTR);
>>>>>>> Stashed changes
    ~MainWindow();
    friend CamScene;


public slots:
    void loadImg();
    void loadImgLeft(QPixmap piximg);
    void loadImgRight(QPixmap piximg);
    void IndexingStatus(QPoint p);

private:
    Ui::MainWindow *ui;
<<<<<<< Updated upstream
    CamScene *leftCAM;
    CamScene *rightCAM;
    QUdpSocket *leftsock=nullptr;
    QPixmap p;
    QPixmap pixImg;
    ImgData * ImgGetLeft=nullptr;
    ImgData *ImgGetRight=nullptr;
    QGraphicsPixmapItem *leftpix=nullptr;
    QGraphicsPixmapItem *rightpix=nullptr;
    FileHandler*filehandler=nullptr;
    QTimer* frame_timer=nullptr;
    QTimer* video_timer=nullptr;
    QQuickWidget * map;
    ScatterDataModifier *modifier;
    bool video_play=true;
    int frame_num=0;
=======
    CamScene* leftCAM;
    CamScene* rightCAM;
    QUdpSocket* leftsock;
    QPixmap p;
    QPixmap pixImg;
    ImgData* ImgGetLeft;
    ImgData* ImgGetRight;
    QGraphicsPixmapItem* leftpix;
    QGraphicsPixmapItem* rightpix;
    FileHandler* filehandler;
    QTimer* frame_timer;
    QTimer* video_timer;
    QThread* lthread;
    QThread* rthread;
    QThread* file_handler_thread;
    QQuickWidget* map;
    ScatterDataModifier* modifier;
    bool video_play;
>>>>>>> Stashed changes
    double firstLat;
    double firstLon;
    double secondLat;
    double secondLon;
    bool canAddMarker;
    QMap<int,QVector<FRAME*>> leftframe;
    QMap<int,QVector<FRAME*>> rigtframe;
    flatto3d converter;
<<<<<<< Updated upstream

private slots:
    void on_nextButton_clicked();
    void on_playButton_clicked();
    void on_prevButton_clicked();
    void keyPressEvent(QKeyEvent *event);
    void addMixmap(QByteArray &data);
    void on_lineEdit_editingFinished();
    void on_lineEdit_2_editingFinished();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
=======
    TemplateCase* tmpcase;
    template_reader* reader;
    QGraphicsOpacityEffect* opacityPrev;
    QGraphicsOpacityEffect* opacityPlay;
    QGraphicsOpacityEffect* opacityNext;
    QGraphicsOpacityEffect* opacityPlayer;
    float hiddenOpacity;
    float defaultOpacity;
    QMap<int, uint64> frameMap;
    void PixMapCut();
    void setTheme(QString themeName);
    inline static int frame_counter{};
    inline static int frame_num{};

private slots:
    void on_toolButtonNext_clicked();
    void on_toolButtonPlay_clicked();
    void on_toolButtonPrev_clicked();
    void keyPressEvent(QKeyEvent* event) override;
    void addMixmap(QByteArray& data);
    void on_horizontalSliderBlsize_valueChanged(int value);
    void on_horizontalSliderC_valueChanged(int value);
>>>>>>> Stashed changes
    void imageFilter();
    void on_toolButton_pressed();
    void on_toolButton_2_pressed();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
    void initialize_3d_graph();
    void to_3d();

signals:
    void thresHold(int bs,double C);
    void imgFilter(state filter);
};
#endif // MAINWINDOW_H
