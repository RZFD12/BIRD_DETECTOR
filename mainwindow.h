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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class CamScene :public QGraphicsScene
{
    Q_OBJECT
public:
    CamScene(QWidget*parent=nullptr);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void loadImg();
    void loadImgLeft(QPixmap piximg);
    void loadImgRight(QPixmap piximg);

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
    void imageFilter();
    void on_toolButton_pressed();
    void on_toolButton_2_pressed();

private:
    Ui::MainWindow *ui;
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

signals:
   void thresHold(int bs,double C);
   void imgFilter(state filter);

};
#endif // MAINWINDOW_H
