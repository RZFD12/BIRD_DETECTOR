#include "filehandler.h"
#include <QDataStream>
#include <QtDebug>

int count =0;
FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::setFileName(const QString &newFileName)
{
    m_fileName = newFileName;
    m_file.setFileName (newFileName);
}

bool FileHandler::save(image_saving_protocol &p)
{
    m_buff.append(p);
    qDebug()<<m_buff.size();
    if(m_file.open(QIODevice::Append) && m_buff.size()>200)
    {
        QDataStream out(&m_file);
        out.setVersion(QDataStream::Qt_4_2);
        for(const auto &it :qAsConst(m_buff))
        {
            out<<it.CAMERA_ID<<it.NUMBER_OF_FRAMES<<it.tsec<<it.tusec<<it.image;
            qDebug()<<it.image.sizeInBytes();
        }
        m_file.flush();
        m_file.close();
        m_buff.clear();
        m_buff.squeeze();
        qDebug()<<count;
        count ++;
        return true;
    }
    else{m_file.close();return false;}
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
