#ifndef TEMPLATE_READER_H
#define TEMPLATE_READER_H

#include <QObject>
#include <QVector>
#include <opencv2/opencv.hpp>
enum template_type {BPLA,BIRD};

class template_reader : public QObject
{
    Q_OBJECT
public:
    explicit template_reader(QObject *parent = nullptr);
    QVector<cv::Mat> templates(template_type type);
signals:

};

#endif // TEMPLATE_READER_H
