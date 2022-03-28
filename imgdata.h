#ifndef IMGDATA_H
#define IMGDATA_H

#include <filehandler.h>
#include <QObject>
#include <QByteArray>
#include <QTimer>
#include <QImage>
#include <QPixmap>

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
  explicit ImgData(string, QObject *parent = 0);
  virtual ~ImgData();

signals:
  void Downloaded();
  void Image(QPixmap pix);

private slots:
  void Get();

private:
  std::string m_video_url;
  cv::VideoCapture m_video;
  int m_block_size=15;
  double m_C=15;
  state m_FrameFilter=Gray;
  int m_b=qRegisterMetaType<state>("state");
  FileHandler *filehandler=nullptr;
  image_saving_protocol p;

public slots:
    void setThresHold(int bs,double C);
    void imgFilter(state filter);
    void Start();
    void setFileHandler(FileHandler *f);
};

#endif  //IMGDATA_H
