#pragma once

#ifndef IMGDATA_H
#define IMGDATA_H

#include <filehandler.h>
#include <QObject>
#include <QByteArray>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QtDebug>
#include <QTime>

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
<<<<<<< Updated upstream
  explicit ImgData(int id,std::string, QObject *parent = 0);
  virtual ~ImgData();
=======
    explicit ImgData(int id, QString url, QObject* parent = Q_NULLPTR);
    inline void SetIncludedNumList(QList<int>* lst) { includednum = lst; }
    inline void SetTemplatesImages(QVector<cv::Mat>* vec) { ImagesForTempMatch = vec; }
>>>>>>> Stashed changes

public slots:
    void setThresHold(int bs,double C);
    void imgFilter(state filter);
    void Start();
    void setFileHandler(FileHandler *f);
    void Get();

private:
<<<<<<< Updated upstream
  int cam_id;
  std::string m_video_url;
  cv::VideoCapture m_video;
  int m_block_size=15;
  double m_C=15;
  state m_FrameFilter=Gray;
  int m_b=qRegisterMetaType<state>("state");
  FileHandler *filehandler=nullptr;
  image_saving_protocol p;
=======
    int cam_id;
    QString m_video_url;
    cv::VideoCapture m_video;
    int m_block_size;
    double m_C;
    state m_FrameFilter;
    int m_b;
    FileHandler* filehandler;
    image_saving_protocol p;
    int cut_pix;
    QVector<cv::Mat>* ImagesForTempMatch;
    QList<int>* includednum;
    cv::Mat cropped(cv::Mat& frame);
    QVector<cv::Mat> matchingResult(cv::Mat& frame);
    QVector<cv::Point> ResultPoint(const QVector<cv::Mat>& matchicngResultframes);
    void matchrectangle(QVector<cv::Point>& points,cv::Mat frame);
>>>>>>> Stashed changes

signals:
  void Downloaded();
  void Image(QPixmap pix);
  void set_image_data(image_saving_protocol p);
};

#endif  //IMGDATA_H
