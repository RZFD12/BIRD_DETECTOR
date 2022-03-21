#include "imgdata.h"
#include <QtDebug>
#include "opencv2/opencv.hpp"
using namespace cv;
ImgData::ImgData(std::string url, QObject *parent) :
 QObject(parent)
{
    video_url=url;
}

ImgData::~ImgData() { }


//cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
//adaptiveThreshold(frame,tresh,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,block_size,C);

void ImgData::get()
{

    Mat frame;

   // Mat tresh;
    if(video.isOpened()){video>>frame;
        if(!frame.empty()){


            switch(FrameFilter){

                    case RGB:{
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
                    cv::bitwise_not(frame,frame);
                    emit image(QPixmap::fromImage(qimg.rgbSwapped()));
                    break;}

                    case Gray:{
                    cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    p.image=qimg;
                    cv::bitwise_not(frame,frame);
                    emit image(QPixmap::fromImage(qimg.rgbSwapped()));

                    break;}

                    case Threshold:{
                    cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    adaptiveThreshold(frame,frame,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,block_size,C);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    cv::bitwise_not(frame,frame);
                    emit image(QPixmap::fromImage(qimg.rgbSwapped()));

                    break;}
                                    }
            p.CAMERA_ID=1;
            p.NUMUBER_OF_FRAMES=1;
            p.tsec=0;
            p.tusec=0;
            filehandler->save(p);
            // формирование пакета для записи в файл
                        }
                }
}

void ImgData::treshhold_param(int bs, double C)
{
    if(bs%2==1){this->block_size=bs;}
    else{this->block_size=bs+1;}
    this->C=C;
}

void ImgData::img_filter(state filter)
{
    this->FrameFilter=filter;
}

void ImgData::start()
{
    QTimer * timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&ImgData::get);
    timer->setInterval(10);
    timer->start();
    video.open(video_url);
}

void ImgData::set_filehandler(FileHandler *f)
{
    this->filehandler=f;
    this->filehandler->moveToThread(this->thread());
}


