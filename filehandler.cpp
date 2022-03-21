#include "filehandler.h"
#include <QDataStream>
#include <QtDebug>

int count =0;
FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

bool FileHandler::save(image_saving_protocol &p)
{
    buff.append(p);
    qDebug()<<buff.size();
    if(file.open(QIODevice::Append) && buff.size()>200)
    {
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_2);
        for(const auto &it :qAsConst(buff)){
        out<<it.CAMERA_ID<<it.NUMUBER_OF_FRAMES<<it.tsec<<it.tusec<<it.image;
        qDebug()<<it.image.sizeInBytes();
        }
        file.flush();
        file.close();
        buff.clear();
        buff.squeeze();

        qDebug()<<count;
        count ++;
        return true;

    }
    else{file.close();return false;}
}

QMap<camera,image_saving_protocol> FileHandler::read(int num_frames)
{
    image_saving_protocol protocol;


    if(file.open(QIODevice::ReadOnly)){
    file.seek(num_frames);
    file.read(10);

    }
    return images;
}

void FileHandler::set_file_name(QString file_name)
{
    this->file_name=file_name;
    file.setFileName(this->file_name);
}
