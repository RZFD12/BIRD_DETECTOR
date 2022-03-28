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
#include <QPoint>

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
enum frame_state {next,previos};
Q_DECLARE_METATYPE(image_saving_protocol)

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);

    bool Save(image_saving_protocol p);

    QMap<camera,image_saving_protocol> Read(int numFrames);

    void setFileName(const QString &newFileName);

    void matRead(image_saving_protocol &read_protocol, frame_state state);

    void Decode(vector<uint8_t> buff);

    void start();

private:
    QString m_fileName;

    QFile m_file;

    QMap<camera,image_saving_protocol> m_images;

    QVector <image_saving_protocol> m_buff;

    int m_b=qRegisterMetaType<image_saving_protocol>("image_saving_protocol");

    int frameState=qRegisterMetaType<frame_state>("frame_state");

    int position=0;

    int current_size=0;

    std::vector<uint32_t> FrameByteIndex;

private:
    void matWrite(const image_saving_protocol& saving_protocol,ofstream &fs);

    std::vector<uint32_t> Data_Indexing();

signals:
    void readImage(QPixmap p);

    void Status(QPoint p);



};

#endif // FILEHANDLER_H
