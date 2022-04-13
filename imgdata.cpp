#include "imgdata.h"
#include <QtDebug>
#include <QTime>

ImgData::ImgData(int id, std::string url, QObject *parent) : QObject(parent)
{
    m_video_url = url;
    cam_id=id;
}

ImgData::~ImgData() { }

void ImgData::Get()
{
    cv::Mat frame;
    if(m_video.isOpened())
    {
        m_video>>frame;
        if(!frame.empty())
        {
            switch(m_FrameFilter)
            {
                case RGB:{
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
                    //bitwise_not(frame,frame);
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}

                case Gray:{
                    cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    p.frame = frame;
                    bitwise_not(frame,frame);
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}

                case Threshold:{
                    cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    adaptiveThreshold(frame,frame,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,m_block_size,m_C);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    bitwise_not(frame,frame);
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}
            }
            p.CAMERA_ID = cam_id;
            p.NUMBER_OF_FRAMES = 1;
            //p.tmsec = std::chrono::duration_cast<std::chrono::milliseconds>
            //        (std::chrono::system_clock::now().time_since_epoch()).count();

            p.tsec=0;

            p.tusec = 0;

            emit set_image_data(p);
        }
        else{qDebug()<<"empty";}
    }
}

void ImgData::setThresHold(int bs, double C)
{
    if(bs%2 == 1){this->m_block_size = bs;}
    else{this->m_block_size = bs+1;}
    this->m_C = C;
}

void ImgData::imgFilter(state filter)
{
    this->m_FrameFilter = filter;
}

void ImgData::Start()
{
   // QTimer * timer = new QTimer(this);
   // connect(timer,&QTimer::timeout,this,&ImgData::Get);
   // timer->setInterval(100);
   // timer->start();
    m_video.open(m_video_url);
}

void ImgData::setFileHandler(FileHandler *f)
{
    //this->filehandler = f;
    //this->filehandler->moveToThread(this->thread());
}
