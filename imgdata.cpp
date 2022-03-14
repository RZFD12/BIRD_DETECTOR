#include "imgdata.h"

ImgData::ImgData(QUrl imageUrl, QObject *parent) :
 QObject(parent)
{
 connect(&m_WebCtrl, &QNetworkAccessManager::finished,this,&ImgData::ImgDownloaded);
 QNetworkRequest request(imageUrl);
 m_WebCtrl.get(request);
}

ImgData::~ImgData() { }

void ImgData::ImgDownloaded(QNetworkReply* pReply) {
 m_DownloadedData = pReply->readAll();
 pReply->deleteLater();
 emit downloaded();
}

QByteArray ImgData::downloadedImg() const {
 return m_DownloadedData;
}
