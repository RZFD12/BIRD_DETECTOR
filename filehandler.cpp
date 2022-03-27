#include "filehandler.h"
#include <QDataStream>
#include <QtDebug>
#include <QByteArray>

int count =0;

FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::setFileName(const QString &newFileName)
{
    m_fileName = newFileName;
}

void FileHandler::save(image_saving_protocol &saving_protocol)
{
    m_buff.append(saving_protocol);
    if(m_file.open(m_fileName.toStdString(),FileStorage::APPEND) && m_buff.size()>50)
    {
        m_file<<"structs"<<"[";
        for(const auto &it :qAsConst(m_buff))
        {            
            if(count==5)
            {
                m_file<<"{";
                m_file<<"camid"<<(char*)&it.CAMERA_ID;
                m_file<<"numframes"<<(char*)&it.NUMBER_OF_FRAMES;
                m_file<<"tsec"<<(char*)&it.tsec;
                m_file<<"tusec"<<(char*)&it.tusec;
                m_file<<"myframe"<<it.frame;
                m_file<<"}";
            }
            count++;
        }
        m_file<<"]";
        m_file.release();
        m_buff.clear();
        m_buff.squeeze();
    }
}

void FileHandler::read(image_saving_protocol& read_protocol)
{
    if(m_file.open(m_fileName.toStdString(),FileStorage::READ))
    {
        FileNode fn = m_file["structs"];
        int id=0;
        for (FileNodeIterator it = fn.begin(); it != fn.end(); it++,id++)
            {
                FileNode item = *it;
                item["camid"]>>read_protocol.CAMERA_ID;
                item["numframes"]>>read_protocol.NUMBER_OF_FRAMES;
                item["tsec"]>>read_protocol.tsec;
                item["tusec"]>>read_protocol.tusec;
                item["myframe"]>>read_protocol.frame;
            }
        m_file.release();
    }
    qDebug()<<read_protocol.CAMERA_ID<<" camid";
    qDebug()<<read_protocol.NUMBER_OF_FRAMES<<" numframes";
    qDebug()<<read_protocol.tsec<<" tsec";
    qDebug()<<read_protocol.tusec<<" tusec";
    QImage qimg(read_protocol.frame.data,read_protocol.frame.cols,
                read_protocol.frame.rows,read_protocol.frame.step,QImage::Format_Grayscale8);
    emit read_image(QPixmap::fromImage(qimg.rgbSwapped()));
}
