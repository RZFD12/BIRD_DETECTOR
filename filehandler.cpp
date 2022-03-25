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
    if(m_file.open(QIODevice::Append) && m_buff.size()>50)
    {
        QByteArray baout;

        QDataStream out(&baout, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_15);


        for(const auto &it :qAsConst(m_buff))
        {            
            //out<<it.CAMERA_ID<<it.NUMBER_OF_FRAMES<<it.tsec<<it.tusec;
            if(c==5){
            matwrite(it);
            qDebug()<<it.frame.cols;
            qDebug()<<it.frame.rows;

            }
            c++;

        }

        m_file.flush();
        m_file.close();
        m_buff.clear();
        m_buff.squeeze();
        return true;
    }
    else{m_file.close();return false;}
}




void FileHandler::matwrite(const image_saving_protocol& saving_protocol)
{
    ofstream fs(m_fileName.toStdString(), fstream::app);

     //infromation
     fs.write((char*)&saving_protocol.CAMERA_ID,sizeof(unsigned int));
     fs.write((char*)&saving_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
     fs.write((char*)&saving_protocol.tsec,sizeof (unsigned int));
     fs.write((char*)&saving_protocol.tusec,sizeof(unsigned int));


     std::vector<uchar> buff;//buffer for coding
     std::vector<int> param(2);
     param[0] = cv::IMWRITE_PAM_FORMAT_GRAYSCALE;
     param[1] = 80;//default(95) 0-100


     cv::imencode(".jpg", saving_protocol.frame, buff, param);
     int a = buff.size();
     fs.write((char*)&a,sizeof(int));
     //buff.resize(300000);
     qDebug()<<buff.size();



     for(ulong i=0; i<buff.size(); ++i){
         fs.write((char*)&buff[i],sizeof (uchar));
     }


//    // Header
//    int type = saving_protocol.frame.type();
//    int channels = saving_protocol.frame.channels();
//    fs.write((char*)&saving_protocol.frame.rows, sizeof(int));    // rows
//    fs.write((char*)&saving_protocol.frame.cols, sizeof(int));    // cols
//    fs.write((char*)&type, sizeof(int));        // type
//    fs.write((char*)&channels, sizeof(int));    // channels

//    // Data
//    if (saving_protocol.frame.isContinuous())
//    {
//        fs.write(saving_protocol.frame.ptr<char>(0), (saving_protocol.frame.dataend - saving_protocol.frame.datastart));
//    }
//    else
//    {
//        int rowsz = CV_ELEM_SIZE(type) * saving_protocol.frame.cols;
//        for (int r = 0; r < saving_protocol.frame.rows; ++r)
//        {
//            fs.write(saving_protocol.frame.ptr<char>(r), rowsz);
//        }
//    }
}

void FileHandler::matread(image_saving_protocol& read_protocol)
{
    ifstream fs(m_fileName.toStdString(), fstream::binary);

    int step=301011;
    fs.seekg(0,ios_base::beg);

    fs.read((char*)&read_protocol.CAMERA_ID,sizeof(unsigned int));
    qDebug()<<read_protocol.CAMERA_ID;
    fs.read((char*)&read_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
    fs.read((char*)&read_protocol.tsec,sizeof (unsigned int));
    fs.read((char*)&read_protocol.tusec,sizeof(unsigned int));

    std::vector<uchar> buff;//buffer for coding

    int size;
    fs.read((char*)&size,sizeof(int));
    qDebug()<<size;

    char *buffer = new char[size];
    fs.read(buffer, size);



   //std::vector<char> data(buff, buff + size);

    //fs.read((char*)mat.data, CV_ELEM_SIZE(type) * rows * cols);
    read_protocol.frame = cv::imdecode(cv::Mat(1,size,CV_8UC1, buffer),0);


    QImage qimg(read_protocol.frame.data,read_protocol.frame.cols,
                read_protocol.frame.rows,read_protocol.frame.step,QImage::Format_Grayscale8);

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
