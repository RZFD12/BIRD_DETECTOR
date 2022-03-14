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

private slots:
    void on_nextbtn_clicked();

    void on_playbtn_clicked();

    void on_prevbtn_clicked();

    void keyPressEvent(QKeyEvent *event);

    void read_data();

    void add_mixmap(QByteArray &data);


private:
    Ui::MainWindow *ui;
    CamScene *leftCAM;
    CamScene *rightCAM;
    QUdpSocket *leftsock=nullptr;
    QPixmap p;
    QPixmap pixImg;
    ImgData * ImgGetleft=nullptr;
     QGraphicsPixmapItem *pix=nullptr;

};
#endif // MAINWINDOW_H
