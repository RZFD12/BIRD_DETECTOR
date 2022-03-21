#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QObject>
#include <QImage>
#include <QFile>
#include <QMap>
struct image_saving_protocol{
    quint8 CAMERA_ID;
    unsigned int NUMUBER_OF_FRAMES;
    unsigned int tsec;
    unsigned int tusec;
    QImage image;
};
enum camera {left,right};
Q_DECLARE_METATYPE(image_saving_protocol)

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);
private:
    QString file_name;
    QFile file;
    QMap<camera,image_saving_protocol> images;
    QVector <image_saving_protocol> buff;

    //quint16 protocol_size=1920*108
public:
    bool save(image_saving_protocol &p);
    QMap<camera,image_saving_protocol> read(int num_frames);
    void set_file_name(QString file_name);



signals:

};

#endif // FILEHANDLER_H
