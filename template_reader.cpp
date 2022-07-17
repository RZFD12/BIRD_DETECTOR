#include <QDir>
#include <QDebug>

#include "template_reader.h"

template_reader::template_reader(QObject* parent)
    : QObject(parent),
      tmp_images()
{}

QVector<cv::Mat> template_reader::templates(template_type type)
{
    QString path = "./templates";
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*jpg";
    auto lst = dir.entryInfoList(nameFilters,QDir::Files);
    QVector<cv::Mat> vec;
    if(type == template_type::BIRD)
    {
        for(const auto& it : qAsConst(lst))
        {
            vec.push_back(cv::imread(it.absoluteFilePath().toStdString(),cv::IMREAD_GRAYSCALE));
        }
    }
    else if(type == template_type::BPLA)
    {

    }
    else
    {

    }
    this->tmp_images = vec;
    return tmp_images;
}
