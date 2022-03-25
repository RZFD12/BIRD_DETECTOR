#include "imgdata.h"
#include <QtDebug>
#include <QTime>
using namespace cv;
ImgData::ImgData(std::string url, QObject *parent) : QObject(parent)
{
    m_video_url=url;
}

ImgData::~ImgData() { }

//cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
//adaptiveThreshold(frame,tresh,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,block_size,C);

void ImgData::get()
{



    Mat frame;
    if(m_video.isOpened())
    {
        m_video>>frame;
        if(!frame.empty())
        {
            switch(m_FrameFilter)
            {
                case RGB:{
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
                    cv::bitwise_not(frame,frame);
                    emit image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}

                case Gray:{
                    cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    p.frame=frame;
                    cv::bitwise_not(frame,frame);
                    emit image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}

                case Threshold:{
                    cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    adaptiveThreshold(frame,frame,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,m_block_size,m_C);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    cv::bitwise_not(frame,frame);
                    emit image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}
            }
            p.CAMERA_ID=135;
            p.NUMBER_OF_FRAMES=1;
            p.tsec=0;
            p.tusec=0;
            QDateTime dt = QDateTime::currentDateTime();

           // p.image.convertToFormat(QImage::)
              filehandler->save(p);
        }
        else{qDebug()<<"empty";}

    }


}

void ImgData::setThresHold(int bs, double C)
{
    if(bs%2==1){this->m_block_size=bs;}
    else{this->m_block_size=bs+1;}
    this->m_C=C;
}

void ImgData::imgFilter(state filter)
{
    this->m_FrameFilter=filter;
}

void ImgData::start()
{
    QTimer * timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&ImgData::get);
    timer->setInterval(100);
    timer->start();
    m_video.open(m_video_url);
}

void ImgData::setFileHandler(FileHandler *f)
{
    this->filehandler=f;
    this->filehandler->moveToThread(this->thread());
}


