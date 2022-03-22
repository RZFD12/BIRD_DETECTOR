#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QObject>
#include <QImage>
#include <QFile>
#include <QMap>
struct image_saving_protocol{
    quint8 CAMERA_ID;
    unsigned int NUMBER_OF_FRAMES;
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
    QString m_fileName;
    QFile m_file;
    QMap<camera,image_saving_protocol> m_images;
    QVector <image_saving_protocol> m_buff;
public:
    bool save(image_saving_protocol &p);
    QMap<camera,image_saving_protocol> read(int numFrames);
    void setFileName(const QString &newFileName);

signals:

};

#endif // FILEHANDLER_H
