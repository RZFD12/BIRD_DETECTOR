#ifndef IMGDATA_H
#define IMGDATA_H

#include <QObject>
#include <QByteArray>
#include <QTimer>
#include <QImage>
#include <QPixmap>

#include <filehandler.h>

struct color
{
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
    explicit ImgData(int id, std::string, QObject* parent = 0);
    void SetIncludedNumList(QList<int>* lst);
    void SetTemplatesImages(QVector<cv::Mat>* vec);

public slots:
    void setThresHold(int bs,double C);
    void imgFilter(state filter);
    void Start();
    void setFileHandler(FileHandler* f);
    void Get();
    void img_cut(int pix_pos);

private:
    int cam_id;
    std::string m_video_url;
    cv::VideoCapture m_video;
    int m_block_size = 15;
    double m_C = 15;
    state m_FrameFilter = Gray;
    int m_b=qRegisterMetaType<state>("state");
    FileHandler* filehandler = nullptr;
    image_saving_protocol p;
    int cut_pix;
    QVector<cv::Mat>* ImagesForTempMatch = nullptr;
    QList<int>* includednum = nullptr;
    cv::Mat cropped(cv::Mat& frame);
    QVector<cv::Mat> matchingResult(cv::Mat& frame);
    QVector<cv::Point> ResultPoint(const QVector<cv::Mat>& matchicngResultframes);
    void matchrectangle(QVector<cv::Point>& points,cv::Mat frame);

signals:
    void Downloaded();
    void Image(QPixmap pix);
    void set_image_data(image_saving_protocol p);
};

#endif  //IMGDATA_H
