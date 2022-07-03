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

#include <frame.h>
#include <imgdata.h>
#include <scatterdatamodifier.h>
#include <flatto3d.h>
#include <templatecase.h>
#include <template_reader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CamScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CamScene(camera cam, QWidget* parent = nullptr);
    QVector<FRAME*> getFrame();
    void clearFrames();    
    const QPixmap &getCurrentPixMap();
    void setCurrentPixMap(const QPixmap& newCurrentPixMap);

private:
    camera current_camera;
    QVector<FRAME*> frames;
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    QPixmap currentPixMap;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    friend CamScene;

public slots:
    void loadImg();
    void loadImgLeft(QPixmap piximg);
    void loadImgRight(QPixmap piximg);
    void IndexingStatus(QPoint p);

private:
    Ui::MainWindow *ui;
    CamScene* leftCAM;
    CamScene* rightCAM;
    QUdpSocket* leftsock = nullptr;
    QPixmap p;
    QPixmap pixImg;
    ImgData* ImgGetLeft = nullptr;
    ImgData* ImgGetRight = nullptr;
    QGraphicsPixmapItem* leftpix = nullptr;
    QGraphicsPixmapItem* rightpix = nullptr;
    FileHandler* filehandler = nullptr;
    QTimer* frame_timer = nullptr;
    QTimer* video_timer = nullptr;
    QThread* lthread;
    QThread* rthread;
    QThread* file_handler_thread;
    QQuickWidget* map;
    ScatterDataModifier* modifier;
    bool video_play=true;    
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
    float hiddenOpacity = 0.2;
    float defaultOpacity = 1.0;
    QMap<int, uint64> frameMap;
    void PixMapCut();
    void setTheme(QString themeName);
    inline static int frame_counter = 0;
    inline static int frame_num = 0;

private slots:
    void on_toolButtonNext_clicked();
    void on_toolButtonPlay_clicked();
    void on_toolButtonPrev_clicked();
    void keyPressEvent(QKeyEvent* event);
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
    void thresHold(int bs,double C);
    void imgFilter(state filter);
    void image_cut(int height_pos);
};
#endif // MAINWINDOW_H
