#ifndef IMGDATA_H
#define IMGDATA_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


class ImgData : public QObject
{
 Q_OBJECT
 public:
  explicit ImgData(QUrl imageUrl, QObject *parent = 0);
  virtual ~ImgData();
  QByteArray downloadedImg() const;

 signals:
  void downloaded();

 private slots:
  void ImgDownloaded(QNetworkReply* pReply);
  void get();
  private:
  QNetworkAccessManager m_WebCtrl;
  QByteArray m_DownloadedData;
  QUrl data_url;
};

#endif  //IMGDATA_H
