#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>
#include <QImage>
#include <QFile>
#include <QMap>
#include <QPixmap>
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

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
    bool Save(image_saving_protocol &p);
    QMap<camera,image_saving_protocol> Read(int numFrames);
    void setFileName(const QString &newFileName);
    void matRead(image_saving_protocol &read_protocol);
    void Decode(vector<uint8_t> buff);

private:
    QString m_fileName;
    QFile m_file;
    QMap<camera,image_saving_protocol> m_images;
    QVector <image_saving_protocol> m_buff;
    void matWrite(const image_saving_protocol& saving_protocol,ofstream &fs);

signals:
    void readImage(QPixmap p);

};

#endif // FILEHANDLER_H
