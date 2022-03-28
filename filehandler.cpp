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

    FrameByteIndex=Data_Indexing();
}

bool FileHandler::Save(image_saving_protocol p)
{
     m_buff.append(p);
    if(m_buff.length()>200)
    {
        ofstream FILE_INPUT(m_fileName.toStdString(),ios::binary | ios::app);
        if(FILE_INPUT.is_open())
        {
            for(const auto &it :qAsConst(m_buff)){matWrite(it,FILE_INPUT);}
        }
        FILE_INPUT.close();
        m_buff.clear();
    }
    return true;
}

void FileHandler::matWrite(const image_saving_protocol& saving_protocol, ofstream &fs)
{
    // INFORMATION
    fs.write((char*)&saving_protocol.CAMERA_ID,sizeof(unsigned int));
    fs.write((char*)&saving_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));
    fs.write((char*)&saving_protocol.tsec,sizeof (unsigned int));
    fs.write((char*)&saving_protocol.tusec,sizeof(unsigned int));

    // IMAGE
    vector<uchar> buff;                                         //buffer for coding
    vector<uint8_t> buff1;
    vector<int> param(2);
    param[0] = IMWRITE_PNG_COMPRESSION;
    param[1] = 3;                                               //default(95) 0-100
    imencode(".png", saving_protocol.frame, buff1, param);
    int a = buff1.size();
    qDebug()<<"size="<<a;
    fs.write((char*)&a,sizeof(int));
    fs.write(reinterpret_cast<const char*>(buff1.data()),buff1.size());

    //PADDING
    //  int padding=850000-buff1.size();
    //vector<uint8_t> padding_buf;
   // for(int i=0;i<padding;i++){padding_buf.push_back(1);}
    //fs.write(reinterpret_cast<const char*>(padding_buf.data()),padding_buf.size());


}

std::vector<uint32_t> FileHandler::Data_Indexing()
{
    std::vector<uint32_t> indexes;

    ifstream fs(m_fileName.toStdString(), ios::binary);

    QFile file;

    file.setFileName(m_fileName);

    if(file.exists()){

        QPoint status;

        status.setX(file.size());


        image_saving_protocol read_protocol;

        uint32_t def_size=0;

        indexes.push_back(def_size);


        while(!fs.eof()){
            fs.read((char*)&read_protocol.CAMERA_ID,sizeof(unsigned int));

            fs.read((char*)&read_protocol.NUMBER_OF_FRAMES,sizeof (unsigned int));

            fs.read((char*)&read_protocol.tsec,sizeof (unsigned int));

            fs.read((char*)&read_protocol.tusec,sizeof(unsigned int));

            int size;

            fs.read((char*)&size,sizeof(int));

            vector<uint8_t> buff1;

            buff1.resize(size);

            fs.read(reinterpret_cast<char*>(&buff1.front()),buff1.size());

            def_size+=size;

            def_size+=20;

            indexes.push_back(def_size);

            status.setY(def_size);

            emit Status(status);

        }
    }

    return indexes;

}

void FileHandler::matRead(image_saving_protocol& read_protocol, frame_state state)
{
    ifstream fs(m_fileName.toStdString(), ios::binary);

    switch (state) {

    case frame_state::next :{position+=1; break;}

    case frame_state ::previos :{position-=1; break;}

    default: {position+=0;}

    }

    fs.seekg(FrameByteIndex[position],ios_base::beg);

    fs.read((char*)&read_protocol.CAMERA_ID,sizeof(unsigned int));

    //qDebug()<<read_protocol.CAMERA_ID;

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
    //qDebug()<<img.channels()<<" chan";
    QImage qimg(img.data,img.cols,
                img.rows,img.step,QImage::Format_Grayscale8);
    emit readImage(QPixmap::fromImage(qimg.rgbSwapped()));
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
