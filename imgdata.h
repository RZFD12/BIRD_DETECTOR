#ifndef IMGDATA_H
#define IMGDATA_H

#include <QObject>
#include <QByteArray>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <filehandler.h>

#include "opencv2/opencv.hpp"

struct color{
    quint8 H;
    quint8 S;
    quint8 V;
    quint8 H1;
    quint8 S1;
    quint8 V1;
};

enum state {Threshold,Gray,RGB};

class ImgData : public QObject
{
 Q_OBJECT
 public:
  explicit ImgData(std::string, QObject *parent = 0);
  virtual ~ImgData();


 signals:
  void downloaded();
  void image(QPixmap pix);

 private slots:


  void get();


private:

  std::string video_url;

  cv::VideoCapture video;

  int block_size=15;

  double C=15;

  state FrameFilter=Gray;

  int b=qRegisterMetaType<state>("state");

  FileHandler *filehandler=nullptr;

  image_saving_protocol p;


public slots:
void treshhold_param(int bs,double C);

void img_filter(state filter);

void start();

void set_filehandler(FileHandler *f);
};

#endif  //IMGDATA_H
