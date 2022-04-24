#include "template_reader.h"
#include <QDir>

template_reader::template_reader(QObject *parent) : QObject(parent)
{

}



QVector<cv::Mat> template_reader::templates(template_type type)
{
    QString path="./templates";
    QDir dir(path);
    QStringList nameFilters;
        nameFilters<<"*jpg";
        QFileInfoList lst=dir.entryInfoList(nameFilters,QDir::Files);
        QFileInfoList::Iterator it;
    QVector<cv::Mat> vec;
    if(type==template_type::BIRD){



    }
    else if(type==template_type::BPLA){




    }
    else
    {  }

    return vec;

}
