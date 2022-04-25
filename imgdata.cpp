#include "imgdata.h"
#include <QtDebug>
#include <QTime>

ImgData::ImgData(int id, std::string url, QObject *parent) : QObject(parent)
{
    m_video_url = url;
    cam_id=id;
}

ImgData::~ImgData() { }

void CreateCenterMark(cv::Mat &frame)
{
    cv::Point vertical1(960,0);
    cv::Point vertical2(960,1080);
    cv::Point horizontal1(0,540);
    cv::Point horizontal2(1920,540);
    cv::line(frame,vertical1,vertical2,cv::Scalar(255,0,0)); // vertical
    cv::line(frame,horizontal1,horizontal2,cv::Scalar(0,0,255)); // horizontal
}

cv::Mat ImgData::cropped(cv::Mat &frame)
{
    cv::Rect cutRect(0,0,1920,this->cut_pix);
    cv::Mat CFFTM=frame(cutRect);
    cv::line(frame,cv::Point(0,this->cut_pix), cv::Point(1920,this->cut_pix),cv::Scalar(0,255,0),2);
    return CFFTM;
}

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
                    p.frame = frame;
                    CreateCenterMark(frame);
                    cv::Mat ff=cropped(frame);
                   // cut_line(frame);
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}

                case Gray:{
                    cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    bitwise_not(frame,frame);
                    CreateCenterMark(frame);
                   // cut_line(frame);
                    cv::Mat ff=cropped(frame);
                    p.frame = frame;
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}

                case Threshold:{
                    cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    adaptiveThreshold(frame,frame,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,m_block_size,m_C);
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    bitwise_not(frame,frame);
                    CreateCenterMark(frame);
                    cv::Mat ff=cropped(frame);
                    //cut_line(frame);
                    p.frame = frame;
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}
            }
            p.CAMERA_ID = cam_id;
            p.NUMBER_OF_FRAMES = 1;
            p.tmsec = std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::system_clock::now().time_since_epoch()).count();
            emit set_image_data(p);
        }
        else{qDebug()<<"empty";}
    }
}

void ImgData::img_cut(int pix_pos)
{
    this->cut_pix=pix_pos;
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
//    this->filehandler = f;
//    this->filehandler->moveToThread(this->thread());
    Q_UNUSED(f);
}
