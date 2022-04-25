#ifndef TEMPLATECASE_H
#define TEMPLATECASE_H
#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QGridLayout>

namespace Ui {
class TemplateCase;
}

class myLabel : public QLabel
{
    Q_OBJECT
public:
    myLabel(cv::Mat frame, QWidget * parent = 0 );
    ~myLabel(){}
    QCheckBox *box;
    QVBoxLayout *Vbox;
signals:
    void clicked();
public slots:
    void slotClicked();
    void unclecked();
protected:
    void mousePressEvent (QMouseEvent * event ) ;
};


class TemplateCase : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateCase(QWidget *parent = nullptr);
    ~TemplateCase();
    void set_template(QVector<cv::Mat> &templastes);
    QGridLayout layout;

private:
    Ui::TemplateCase *ui;
};

#endif // TEMPLATECASE_H
