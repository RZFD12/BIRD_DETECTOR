#include "imgdata.h"
#include <QTimer>
#include <QImage>

#include "opencv2/opencv.hpp"
using namespace cv;
ImgData::ImgData(std::string url, QObject *parent) :
 QObject(parent)
{
 QTimer * timer=new QTimer(this);
 connect(timer,&QTimer::timeout,this,&ImgData::get);
 timer->setInterval(5);
 timer->start();
 video.open(url);

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
                    emit image(&qimg);
                    break;}

                    case Gray:{
                    cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    emit image(&qimg);
                    break;}

                    case Threshold:{
                    cv::cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    adaptiveThreshold(frame,frame,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,block_size,C);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    emit image(&qimg);
                    break;}



                                    }
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


