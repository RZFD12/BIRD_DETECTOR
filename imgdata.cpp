#include "imgdata.h"
#include <QTimer>

ImgData::ImgData(QUrl imageUrl, QObject *parent) :
 QObject(parent)
{
 connect(&m_WebCtrl, &QNetworkAccessManager::finished,this,&ImgData::ImgDownloaded);
 data_url=imageUrl;
 QTimer * timer=new QTimer(this);
 connect(timer,&QTimer::timeout,this,&ImgData::get);
 timer->setInterval(250);
 timer->start();
}

ImgData::~ImgData() { }

void ImgData::ImgDownloaded(QNetworkReply* pReply) {
 m_DownloadedData = pReply->readAll();
 pReply->deleteLater();
 emit downloaded();
}

void ImgData::get()
{
    QNetworkRequest request(data_url);
    m_WebCtrl.get(request);
}

QByteArray ImgData::downloadedImg() const {
 return m_DownloadedData;
}
