#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include<QGraphicsSceneEvent>
#include <QGraphicsScene>
#include <frame.h>
#include <QKeyEvent>
#include <QMap>
#include <QUdpSocket>
#include "imgdata.h"
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

    void loadimgleft(QImage *img);
    void loadimgrigt(QImage *img);

private slots:
    void on_nextbtn_clicked();

    void on_playbtn_clicked();

    void on_prevbtn_clicked();

    void keyPressEvent(QKeyEvent *event);

    void read_data();

    void add_mixmap(QByteArray &data);


    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);



    void image_filter();

private:
    Ui::MainWindow *ui;
    CamScene *leftCAM;
    CamScene *rightCAM;
    QUdpSocket *leftsock=nullptr;
    QPixmap p;
    QPixmap pixImg;

    ImgData * ImgGetleft=nullptr;
    ImgData *ImgGetright=nullptr;

    QGraphicsPixmapItem *leftpix=nullptr;
    QGraphicsPixmapItem *rightpix=nullptr;


signals:
   void tresh_param(int bs,double C);
   void img_filter(state filter);
};
#endif // MAINWINDOW_H
