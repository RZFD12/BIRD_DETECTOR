#include "image_information.h"
#include "ui_image_information.h"

IMAGE_INFORMATION::IMAGE_INFORMATION(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IMAGE_INFORMATION)
{
    ui->setupUi(this);
}

IMAGE_INFORMATION::~IMAGE_INFORMATION()
{
    delete ui;
}
