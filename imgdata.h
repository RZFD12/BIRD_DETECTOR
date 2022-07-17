#pragma once

#ifndef IMGDATA_H
#define IMGDATA_H

#include <QObject>
#include <QByteArray>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QtDebug>
#include <QTime>

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

enum state {Threshold, Gray, RGB};

class ImgData final : public QObject
{
    Q_OBJECT
public:
    explicit ImgData(int id, QString, QObject* parent = Q_NULLPTR);
    inline void SetIncludedNumList(QList<int>* lst) { includednum = lst; }
    inline void SetTemplatesImages(QVector<cv::Mat>* vec) { ImagesForTempMatch = vec; }

public slots:
    void setThresHold(int bs, double C);
    inline void imgFilter(state filter) { m_FrameFilter = filter; }
    inline void Start() { m_video.open(m_video_url.toStdString()); }
    void Get();
    inline void img_cut(int pix_pos) { cut_pix = pix_pos; }

private:
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

signals:
    void Downloaded();
    void Image(QPixmap pix);
    void set_image_data(image_saving_protocol p);
};

#endif  //IMGDATA_H
