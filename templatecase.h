#ifndef TEMPLATECASE_H
#define TEMPLATECASE_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QGridLayout>

enum tmp_state{include,exclude};

namespace Ui {
class TemplateCase;
}

class myLabel : public QLabel
{
    Q_OBJECT
public:
    myLabel(cv::Mat frame, int pos, QWidget *parent = nullptr);
    ~myLabel(){}
    QCheckBox *box;
    QVBoxLayout *Vbox;
    int position;
signals:
    void clicked();
    void MyState(int pos,tmp_state st);
public slots:
    void slotClicked();
    void unclecked();
protected:
    void mousePressEvent (QMouseEvent *event) ;
};


class TemplateCase : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateCase(QWidget *parent = nullptr);
    ~TemplateCase();
    void set_template(QVector<cv::Mat> &templastes);
    QGridLayout layout;
public:
    void labels_state(int num, tmp_state state);
    QList<int> *includedtmp ();

private:
    Ui::TemplateCase *ui;
    QList<int> IncludedTempNum;
};

#endif // TEMPLATECASE_H
