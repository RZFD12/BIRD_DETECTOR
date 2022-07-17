#pragma once

#ifndef TEMPLATE_READER_H
#define TEMPLATE_READER_H

#include <QObject>
#include <QVector>
#include <opencv2/opencv.hpp>
#include <QDir>
#include <QDebug>

enum template_type {BPLA,BIRD};

class template_reader final : public QObject
{
    Q_OBJECT
public:
    explicit template_reader(QObject* parent = nullptr);
    QVector<cv::Mat> templates(template_type type);
    inline QVector<cv::Mat>* tmp() { return &tmp_images; }

public:
    QVector<cv::Mat> tmp_images;
};

#endif // TEMPLATE_READER_H
