#include "filehandler.h"
#include <QDataStream>
#include <QtDebug>
#include <QByteArray>

FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::setFileName(const QString &newFileName)
{
    m_fileName = newFileName;
    m_file.setFileName (newFileName);
}

bool FileHandler::Save(image_saving_protocol &p)
{
    m_buff.append(p);
    if(m_buff.length()>5)
    {
        ofstream FILE_INPUT(m_fileName.toStdString(),ios::binary | ios::app);
        if(FILE_INPUT.is_open())
        {
            for(const auto &it :qAsConst(m_buff)){matWrite(it,FILE_INPUT); qDebug()<<it.frame.cols; qDebug()<<it.frame.rows;}
        }
        FILE_INPUT.close();
        m_buff.clear();
    }
    return true;
}

void FileHandler::matWrite(const image_saving_protocol& saving_protocol, ofstream &fs)
{
    fs.write((char*)&saving_protocol.CAMERA_ID,sizeof(unsigned int));
    fs.write((char*)&saving_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
    fs.write((char*)&saving_protocol.tsec,sizeof (unsigned int));
    fs.write((char*)&saving_protocol.tusec,sizeof(unsigned int));
    vector<uchar> buff;                                         //buffer for coding
    vector<uint8_t> buff1;
    vector<int> param(2);
    param[0] = IMWRITE_PNG_COMPRESSION;
    param[1] = 5;                                               //default(95) 0-100
    imencode(".png", saving_protocol.frame, buff, param);
    for(ulong i=0;i<buff.size();i++) {buff1.push_back(static_cast<uint8_t>(buff[i]));}
    int a = buff1.size();
    fs.write((char*)&a,sizeof(int));
    fs.write(reinterpret_cast<const char*>(buff1.data()),buff1.size());
    Decode(buff1);
}

void FileHandler::matRead(image_saving_protocol& read_protocol)
{
    ifstream fs(m_fileName.toStdString(), ios::binary);
    int step = 301011;
    fs.seekg(0,ios_base::beg);
    fs.read((char*)&read_protocol.CAMERA_ID,sizeof(unsigned int));
    qDebug()<<read_protocol.CAMERA_ID;
    fs.read((char*)&read_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
    fs.read((char*)&read_protocol.tsec,sizeof (unsigned int));
    fs.read((char*)&read_protocol.tusec,sizeof(unsigned int));
    int size;
    fs.read((char*)&size,sizeof(int));
    vector<uint8_t> buff1;
    buff1.resize(size);
    fs.read(reinterpret_cast<char*>(&buff1.front()),buff1.size());
    Decode(buff1);
}

void FileHandler::Decode(vector<uint8_t> buff)
{

    Mat img;
    img = imdecode(Mat(buff),IMREAD_UNCHANGED);
    qDebug()<<img.channels()<<" chan";
    QImage qimg(img.data,img.cols,
                img.rows,img.step,QImage::Format_Grayscale8);
    emit readImage(QPixmap::fromImage(qimg.rgbSwapped()));
}

QMap<camera,image_saving_protocol> FileHandler::Read(int numFrames)
{
    image_saving_protocol protocol;
    if(m_file.open(QIODevice::ReadOnly))
    {
        m_file.seek(numFrames);
        m_file.read(10);
    }
    return m_images;
}
