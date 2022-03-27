#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>
#include <QImage>
#include <QFile>
#include <QMap>
#include <QPixmap>

#include <opencv2\opencv.hpp>
#include <iostream>
#include <fstream>

using namespace cv;

struct image_saving_protocol{
    int CAMERA_ID;
    int NUMBER_OF_FRAMES;
    int tsec;
    int tusec;
    Mat frame;
};
enum camera {left,right};
Q_DECLARE_METATYPE(image_saving_protocol)

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);

private:
    QString m_fileName;
    FileStorage m_file;
    QMap<camera,image_saving_protocol> m_images;
    QVector <image_saving_protocol> m_buff;

public:    
    void setFileName(const QString &newFileName);
    void save(image_saving_protocol &saving_protocol);
    void read(image_saving_protocol &read_protocol);

signals:
    void read_image(QPixmap p);

};

#endif // FILEHANDLER_H
