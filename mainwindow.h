#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QGraphicsEffect>
#include <QImage>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QThread>
#include <QFileDialog>
#include <QVector3D>
#include <QUuid>

#include <frame.h>
#include <imgdata.h>
#include <scatterdatamodifier.h>
#include <flatto3d.h>
#include <templatecase.h>
#include <template_reader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CamScene final : public QGraphicsScene
{
    Q_OBJECT
public:
    CamScene(camera cam, QWidget* parent = Q_NULLPTR);
    inline const QVector<FRAME*>& getFrame() const { return frames; }
    inline void clearFrames() { frames.clear(); }
    inline const QPixmap &getCurrentPixMap() { return currentPixMap; }
    inline void setCurrentPixMap(const QPixmap& newCurrentPixMap) { currentPixMap = newCurrentPixMap; }
    inline bool isGrabToggled(){ return grabToggled; }

private:
    camera current_camera;
    QVector<FRAME*> frames;
    QPixmap currentPixMap;
    bool grabToggled;
    bool item_under_mouse;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
};

class MainWindow final : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = Q_NULLPTR);
    ~MainWindow();
    friend CamScene;

public slots:
    void loadImgLeft(QPixmap piximg);
    void loadImgRight(QPixmap piximg);
    void IndexingStatus(QPoint p);

private:
    Ui::MainWindow *ui;
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
    double firstLat;
    double firstLon;
    double secondLat;
    double secondLon;
    bool canAddMarker;
    QMap<int,QVector<FRAME*>> leftframe;
    QMap<int,QVector<FRAME*>> rightframe;
    flatto3d converter;
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
    void imageFilter();
    void on_toolButtonSave_pressed();
    void on_toolButtonOpen_pressed();
    void on_pushButtonApply_clicked();
    void on_pushButtonDelete_clicked();
    void on_pushButtonMove_clicked();
    void on_spinBoxRotLeft_valueChanged(int arg1);
    void on_spinBoxRotRight_valueChanged(int arg1);
    void init3DGraph();
    void To3D();
    void on_doubleSpinBoxRange_valueChanged(double arg1);
    void on_doubleSpinBoxAngle_valueChanged(double arg1);
    void on_comboBoxTheme_textActivated(const QString& arg1);
    void on_doubleSpinBoxBAngle_valueChanged(double arg1);
    void on_verticalSlider_valueChanged(int value);
    void on_comboBoxStyle_textActivated(const QString& arg1);
    void on_dial_valueChanged(int value);

signals:
    void thresHold(int bs, double C);
    void imgFilter(state filter);
    void image_cut(int height_pos);
};
#endif // MAINWINDOW_H
