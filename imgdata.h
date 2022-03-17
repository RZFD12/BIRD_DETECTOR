#ifndef IMGDATA_H
#define IMGDATA_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

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
  void image(QImage *img);

 private slots:


  void get();


private:

  cv::VideoCapture video;
  int block_size=15;
  double C=15;
  state FrameFilter=Gray;



public slots:
void treshhold_param(int bs,double C);

void img_filter(state filter);

};

#endif  //IMGDATA_H
