#pragma once

#ifndef TEMPLATECASE_H
#define TEMPLATECASE_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QGridLayout>
#include <QtDebug>

enum tmp_state{include,exclude};

namespace Ui {
class TemplateCase;
}

class myLabel final : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(cv::Mat frame, int pos, QWidget* parent = Q_NULLPTR);
    ~myLabel();
    QCheckBox* box;
    QVBoxLayout* Vbox;
    int position;

signals:
    void clicked();
    void MyState(int pos, tmp_state st);

public slots:
    void slotClicked();
    void unclicked();

private:
    QPixmap pixmap;
    void mousePressEvent (QMouseEvent* event) override;
};

class TemplateCase final : public QWidget
{
    Q_OBJECT

public:
    explicit TemplateCase(QWidget* parent = Q_NULLPTR);
    ~TemplateCase();
    void set_template(QVector<cv::Mat>& templastes);
    QGridLayout layout;
    void labels_state(int num, tmp_state state);
    inline QList<int>* includedtmp() { return &IncludedTempNum; }

private:
    Ui::TemplateCase* ui;
    QList<int> IncludedTempNum;
};

#endif // TEMPLATECASE_H
