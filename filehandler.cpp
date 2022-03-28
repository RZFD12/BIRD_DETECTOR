#include "filehandler.h"
#include <QDataStream>
#include <QtDebug>
#include <QByteArray>
#include <opencv2/imgcodecs.hpp>
using namespace std;
using namespace cv;

int count =0;
FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::setFileName(const QString &newFileName)
{
    m_fileName = newFileName;
    m_file.setFileName (newFileName);
}

void APP(QByteArray &buf,QByteArray &img){

    for(int i=0;i<img.length();i++){buf.push_back(img[i]);}


}
int c=0;

bool FileHandler::save(image_saving_protocol &p)
{
    m_buff.append(p);

    if(m_buff.length()>5){

        std::ofstream FILE_INPUT(m_fileName.toStdString(),std::ios::binary | std::ios::app);

        if(FILE_INPUT.is_open()){

        for(const auto &it :qAsConst(m_buff)){matwrite(it,FILE_INPUT); qDebug()<<it.frame.cols; qDebug()<<it.frame.rows;}

        }
        FILE_INPUT.close();
        m_buff.clear();

    }


    return true;




}







void FileHandler::matwrite(const image_saving_protocol& saving_protocol, ofstream &fs)
{


     //infromation
     fs.write((char*)&saving_protocol.CAMERA_ID,sizeof(unsigned int));
     fs.write((char*)&saving_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
     fs.write((char*)&saving_protocol.tsec,sizeof (unsigned int));
     fs.write((char*)&saving_protocol.tusec,sizeof(unsigned int));


     std::vector<uchar> buff;//buffer for coding
     std::vector<uint8_t> buff1;

     std::vector<int> param(2);
     param[0] = cv::IMWRITE_PNG_COMPRESSION;
     param[1] = 5;//default(95) 0-100
     cv::imencode(".png", saving_protocol.frame, buff, param);

     for(ulong i=0;i<buff.size();i++){buff1.push_back(static_cast<uint8_t>(buff[i]));}






     int a = buff1.size();
     fs.write((char*)&a,sizeof(int));


     fs.write(reinterpret_cast<const char*>(buff1.data()),buff1.size());



     decode(buff1);

}

void FileHandler::matread(image_saving_protocol& read_protocol)
{
    ifstream fs(m_fileName.toStdString(), std::ios::binary);



    int step=301011;
    fs.seekg(0,ios_base::beg);

    fs.read((char*)&read_protocol.CAMERA_ID,sizeof(unsigned int));
    qDebug()<<read_protocol.CAMERA_ID;
    fs.read((char*)&read_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
    fs.read((char*)&read_protocol.tsec,sizeof (unsigned int));
    fs.read((char*)&read_protocol.tusec,sizeof(unsigned int));



    int size;
    fs.read((char*)&size,sizeof(int));

    std::vector<uint8_t> buff1;

    buff1.resize(size);

    fs.read(reinterpret_cast<char*>(&buff1.front()),buff1.size());






   // QImage qimg(read_protocol.frame.data,read_protocol.frame.cols,
                //read_protocol.frame.rows,read_protocol.frame.step,QImage::Format_Grayscale8);

    decode(buff1);

   // emit read_image(QPixmap::fromImage(qimg.rgbSwapped()));


}

void FileHandler::decode(std::vector<uint8_t> buff)
{

    Mat img;

    img=cv::imdecode(Mat(buff),cv::IMREAD_UNCHANGED);
    qDebug()<<img.channels()<<" chan";

    QImage qimg(img.data,img.cols,
                img.rows,img.step,QImage::Format_Grayscale8);

    emit read_image(QPixmap::fromImage(qimg.rgbSwapped()));


}


QMap<camera,image_saving_protocol> FileHandler::read(int numFrames)
{
    image_saving_protocol protocol;

    if(m_file.open(QIODevice::ReadOnly))
    {
        m_file.seek(numFrames);
        m_file.read(10);
    }
    return m_images;
}
