#ifndef IMAGE_INFORMATION_H
#define IMAGE_INFORMATION_H

#include <QWidget>

namespace Ui {
class IMAGE_INFORMATION;
}

class IMAGE_INFORMATION : public QWidget
{
    Q_OBJECT

public:
    explicit IMAGE_INFORMATION(QWidget *parent = nullptr);
    ~IMAGE_INFORMATION();

private:
    Ui::IMAGE_INFORMATION *ui;
};

#endif // IMAGE_INFORMATION_H
