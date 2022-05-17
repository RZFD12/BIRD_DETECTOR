#include "imgdata.h"
#include <QtDebug>
#include <QTime>

ImgData::ImgData(int id, std::string url, QObject* parent) : QObject(parent)
{
    m_video_url = url;
    cam_id = id;
}

void CreateCenterMark(cv::Mat& frame)
{
    cv::Point vertical1(960,0);
    cv::Point vertical2(960,1080);
    cv::Point horizontal1(0,540);
    cv::Point horizontal2(1920,540);
    cv::line(frame,vertical1,vertical2,cv::Scalar(255,0,0));
    cv::line(frame,horizontal1,horizontal2,cv::Scalar(0,0,255));
}

cv::Mat ImgData::cropped(cv::Mat& frame)
{
    cv::Rect cutRect(0,0,1920,this->cut_pix);
    auto CFFTM = frame(cutRect);
    cv::line(frame,cv::Point(0,this->cut_pix), cv::Point(1920,this->cut_pix),cv::Scalar(0,255,0),2);
    return CFFTM;
}

QVector<cv::Mat> ImgData::matchingResult(cv::Mat& frame)
{
    QVector<cv::Mat> resultVector;
    for(auto i = 0; i < includednum->length(); i++)
    {
        int NumTmp=(*includednum)[i];
        cv:: Mat result(frame.cols-(*ImagesForTempMatch)[NumTmp].cols+1,frame.rows-(*ImagesForTempMatch)[NumTmp].rows+1,0);
        cv::matchTemplate(frame,(*ImagesForTempMatch)[NumTmp],result,cv::TM_CCORR_NORMED);
        resultVector.push_back(result);
    }
    return resultVector;
}

QVector<cv::Point> tresh(double treshold, const cv::Mat& result)
{
    QVector<cv::Point> vec;
    cv::Mat_<uchar> result1 = result;
    for(auto i = 0; i < result1.rows; i++)
    {
        for(auto j = 0; j < result1.cols; j++)
        {
            if(result.at<float>(i,j) > treshold)
            {
                vec.push_back(cv::Point(j,i));
            }
        }
    }
    return vec;
}

QVector<cv::Point> ImgData::ResultPoint(const QVector<cv::Mat>& matchicngResultframes)
{
    QVector<cv::Point> objectpoints;
    double minVal, maxVal;
    cv::Point  minLoc, maxLoc, matchLoc;
    for(auto i = 0; i < matchicngResultframes.length(); i++)
    {
        cv::minMaxLoc(matchicngResultframes[i],&minVal, &maxVal, &minLoc, &maxLoc, cv::Mat());
        if (maxVal > 0)
        {
            qDebug() << maxVal << " " << minVal;
            matchLoc = maxLoc;
            objectpoints.push_back(matchLoc);
        }
    }
    return objectpoints;
}

void ImgData::matchrectangle(QVector<cv::Point>& points, cv::Mat frame)
{
    for(auto i = 0; i < points.length(); i++)
    {
        cv::rectangle(frame, points[i], cv::Point( points[i].x+50 , points[i].y+50 ), CV_RGB(255, 255, 255),3);
    }
}

void ImgData::Get()
{
    cv::Mat frame;
    if(m_video.isOpened())
    {
        m_video >> frame;
        if(!frame.empty())
        {
            switch(m_FrameFilter)
            {
                case RGB:{
                    CreateCenterMark(frame);
                    auto cropp = cropped(frame);
                    auto points = ResultPoint(matchingResult(cropp));
                    matchrectangle(points,frame);
                    p.frame = frame;
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}

                case Gray:{
                    cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    bitwise_not(frame,frame);
                    CreateCenterMark(frame);
                    auto cropp = cropped(frame); // cutting
                    auto points = ResultPoint(matchingResult(cropp));
                    matchrectangle(points,frame);
                    p.frame = frame;
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}

                case Threshold:{
                    cvtColor(frame,frame,cv::COLOR_BGR2GRAY);
                    adaptiveThreshold(frame,frame,255,cv::ADAPTIVE_THRESH_MEAN_C,cv::THRESH_BINARY,m_block_size,m_C);
                    bitwise_not(frame,frame);
                    CreateCenterMark(frame);
                    auto cropp = cropped(frame); //cutting
                    auto points = ResultPoint(matchingResult(cropp));
                    matchrectangle(points,frame);
                    p.frame = frame;
                    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
                    emit Image(QPixmap::fromImage(qimg.rgbSwapped()));
                break;}
            }
            p.CAMERA_ID = cam_id;
            p.NUMBER_OF_FRAMES = 1;
            p.tmsec = std::chrono::duration_cast<std::chrono::milliseconds>
            (std::chrono::system_clock::now().time_since_epoch()).count();
            emit set_image_data(p);
        }
        else{qDebug() << "empty";}
    }
}

void ImgData::img_cut(int pix_pos)
{
    this->cut_pix = pix_pos;
}

void ImgData::SetIncludedNumList(QList<int>* lst)
{
    includednum = lst;
}

void ImgData::SetTemplatesImages(QVector<cv::Mat>* vec)
{
    ImagesForTempMatch = vec;
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
    m_video.open(m_video_url);
}

void ImgData::setFileHandler(FileHandler* f)
{
    Q_UNUSED(f);
}
