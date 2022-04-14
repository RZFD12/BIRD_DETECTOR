#include "filehandler.h"
#include <QDataStream>
#include <QtDebug>
#include <QByteArray>
#include <QThread>
#include <QDateTime>

FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::setFileName(const QString &newFileName)
{
    m_fileName = newFileName;
    m_file.setFileName (newFileName);
    FrameByteIndex=Data_Indexing();
}

bool FileHandler::Save(image_saving_protocol p)
{
    if(current_stream_buffer.size()==0)
    {
        current_stream_buffer.push_back(p);
    }
    if(current_stream_buffer.size()==1 && current_stream_buffer[0].CAMERA_ID==p.CAMERA_ID)
    {
        current_stream_buffer[0]=p;
    }
    else if (current_stream_buffer.size()==1 && current_stream_buffer[0].CAMERA_ID!=p.CAMERA_ID)
    {
       current_stream_buffer.push_back(p);
       image_writing_buffer.push_back(current_stream_buffer);
       current_stream_buffer.clear();
       current_stream_buffer.shrink_to_fit();
    }
    if (image_writing_buffer.size()>199)
    {
        std::ofstream FILE_INPUT(m_fileName.toStdString(),std::ios::binary | std::ios::app);
        if(FILE_INPUT.is_open())
        {
            for(ulong i=0;i<image_writing_buffer.size();++i)
            {
                 ++frames_counter;
                qDebug()<<frames_counter;

                image_writing_buffer[i][0].NUMBER_OF_FRAMES=frames_counter;

                image_writing_buffer[i][1].NUMBER_OF_FRAMES=frames_counter;

                if(image_writing_buffer[i][0].CAMERA_ID==1)
                {
                    matWrite(image_writing_buffer[i][0],FILE_INPUT);
                    matWrite(image_writing_buffer[i][1],FILE_INPUT);
                }
                else
                {
                    matWrite(image_writing_buffer[i][1],FILE_INPUT);
                    matWrite(image_writing_buffer[i][0],FILE_INPUT);
                }


            }
            FILE_INPUT.close();
            image_writing_buffer.clear();
            image_writing_buffer.shrink_to_fit();
        }
    }
    return true;
}

void FileHandler::matWrite(const image_saving_protocol& saving_protocol, std::ofstream &fs)
{
    // INFORMATION
    fs.write((char*)&saving_protocol.CAMERA_ID,sizeof(unsigned int));
    fs.write((char*)&saving_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
    fs.write((char*)&saving_protocol.tsec,sizeof (unsigned int));
    fs.write((char*)&saving_protocol.tusec,sizeof(unsigned int));

    // IMAGE
    std::vector<uchar> buff;                                         //buffer for coding
    std::vector<uint8_t> buff1;
    std::vector<int> param(2);
    param[0] = cv::IMWRITE_PNG_COMPRESSION;
    param[1] = 2;                                               //default(95) 0-100
    imencode(".png", saving_protocol.frame, buff1, param);
    int a = buff1.size();
    fs.write((char*)&a,sizeof(int));
    fs.write(reinterpret_cast<const char*>(buff1.data()),buff1.size());

    //PADDING
    //int padding=850000-buff1.size();
    //vector<uint8_t> padding_buf;
    //for(int i=0;i<padding;i++){padding_buf.push_back(1);}
    //fs.write(reinterpret_cast<const char*>(padding_buf.data()),padding_buf.size());
}

std::vector<uint64> FileHandler::Data_Indexing()
{

    std::vector<uint64> indexes;
    std::ifstream fs(m_fileName.toStdString(), std::ios::binary);
    QFile file;
    file.setFileName(m_fileName);
    if(file.exists())
    {
        QPoint status;
        status.setX(static_cast<quint32>(file.size()/1000));
        image_saving_protocol read_protocol;
        uint64 def_size=0;
        indexes.push_back(def_size);
        while(!fs.eof())
        {
            fs.read((char*)&read_protocol.CAMERA_ID,sizeof(unsigned int));
            fs.read((char*)&read_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
            fs.read((char*)&read_protocol.tsec,sizeof (unsigned int));
            fs.read((char*)&read_protocol.tusec,sizeof(unsigned int));
            int size;
            fs.read((char*)&size,sizeof(int));
            std::vector<uint8_t> buff1;
            buff1.resize(size);
            fs.read(reinterpret_cast<char*>(&buff1.front()),buff1.size());
            def_size+=size;
            def_size+=20;
            indexes.push_back(def_size);
            //status=qMakePair<uint64,uint64>(static_cast<int>(file_size/1000),static_cast<int>(def_size/1000));
            status.setY(static_cast<quint32>(def_size/1000));
            emit Status(status);

            //QThread::msleep(50);
            //qDebug()<<status.second;
            //qDebug()<<status.y();
        }
    }
    return indexes;
}

void FileHandler::matRead(image_saving_protocol& read_protocol, frame_state state)
{
    std::ifstream fs(m_fileName.toStdString(), std::ios::binary);
    switch(state)
    {
        case frame_state::next :{position+=2; break;}
        case frame_state ::previos :{position-=2; break;}
        default: {position+=0;}
    }
    int f=0;
    fs.seekg(FrameByteIndex[position],std::ios_base::beg);
    while (f<2)
    {
        int fff=0;
        fs.read((char*)&fff,sizeof(unsigned int));
        //qDebug()<<read_protocol.CAMERA_ID;
        fs.read((char*)&read_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
        fs.read((char*)&read_protocol.tsec,sizeof (unsigned int));
        fs.read((char*)&read_protocol.tusec,sizeof(unsigned int));
        int size;
        fs.read((char*)&size,sizeof(int));
        std::vector<uint8_t> buff1;
        buff1.resize(size);
        fs.read(reinterpret_cast<char*>(&buff1.front()),buff1.size());
        Decode(buff1,fff);
        f++;
        //qDebug()<<read_protocol.CAMERA_ID;
    }
}

void FileHandler::Decode(std::vector<uint8_t> buff, int camera_id)
{
    cv::Mat img;
   // QDateTime::
    img = imdecode(cv::Mat(buff),cv::IMREAD_UNCHANGED);

    //cv::putText(img,"PROVERKA",cv::Point(10,300),cv::FONT_HERSHEY_SIMPLEX,2,cv::Scalar(200,30,30),2); Camera id
    // time
    // frame_number
    // percent from all data

    //qDebug()<<img.channels()<<" chan";
    QImage qimg(img.data,img.cols,
                img.rows,img.step,QImage::Format_Grayscale8);

    if(camera_id==1)
    {
        emit readImageleft(QPixmap::fromImage(qimg.rgbSwapped()));
    }
    else
    {
        emit readImageRight(QPixmap::fromImage(qimg.rgbSwapped()));
    }
}

void FileHandler::start()
{

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
