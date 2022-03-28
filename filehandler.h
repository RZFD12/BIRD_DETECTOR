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
    unsigned int CAMERA_ID;
    unsigned int NUMBER_OF_FRAMES;
    unsigned int tsec;
    unsigned int tusec;
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

    QFile m_file;

    QMap<camera,image_saving_protocol> m_images;

    QVector <image_saving_protocol> m_buff;

    void matwrite(const image_saving_protocol& saving_protocol,std::ofstream &fs);




public:
    bool save(image_saving_protocol &p);
    QMap<camera,image_saving_protocol> read(int numFrames);
    void setFileName(const QString &newFileName);


    void matread(image_saving_protocol &read_protocol);

    void decode(std::vector<uint8_t> buff);


signals:

    void read_image(QPixmap p);

};

#endif // FILEHANDLER_H
