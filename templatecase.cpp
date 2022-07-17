#include "templatecase.h"
#include "ui_templatecase.h"
#include <QtDebug>

myLabel::myLabel(cv::Mat frame,int pos, QWidget *parent)
    : QLabel(parent),
      box(new QCheckBox(this)),
      Vbox(new QVBoxLayout(this)),
      position(pos),
      pixmap(QPixmap::fromImage(QImage(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8).rgbSwapped()))
{
    box->setFixedSize(5,5);
    Vbox->addWidget(box);
    this->setLayout(Vbox);
    this->setLineWidth(2);
    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    box->setChecked(false);
    this->setPixmap(pixmap);
}

void myLabel::slotClicked()
{
    this->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    box->setChecked(true);
    emit MyState(this->position, tmp_state::include);
}

void myLabel::mousePressEvent ( QMouseEvent* event )
{
    emit clicked();
    if(box->isChecked()){unclicked();}
    else{slotClicked();}
    Q_UNUSED(event);
}

void myLabel::unclicked()
{
    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    box->setChecked(false);
    emit MyState(this->position, tmp_state::exclude);
}

TemplateCase::TemplateCase(QWidget* parent) :
    QWidget(parent),
    layout(),
    ui(new Ui::TemplateCase),
    IncludedTempNum()
{
    ui->setupUi(this);
    auto w = new QWidget(this);
    w->setLayout(&layout);
    layout.setSpacing(0);
    ui->scrollArea->setWidget(w);
}

TemplateCase::~TemplateCase()
{
    delete ui;
}

void TemplateCase::set_template(QVector<cv::Mat> &templastes)
{
    int posx {};
    int posy {};
    int iter {};
    auto count = static_cast<int>(this->width()/55);
    for(const auto& it : templastes)
    {
        if(posx > count){posx = 0; posy++;}
        auto label = new myLabel(it,iter,this);
        connect(label,&myLabel::MyState,this,&TemplateCase::labels_state);
        label->setFixedSize(55,55);
        layout.addWidget(label,posy,posx);
        posx++;
        iter++;
    }
}

int element_position(QList<int>& lst, int num)
{
    int position {};
    for(int i = 0; i < lst.length(); ++i)
    {
        if(lst[i] == num)
        {
            position = i;
            break;
        }
        else
        {
            continue;
        }
    }
    return position;
}

void TemplateCase::labels_state(int num, tmp_state state)
{
    if(state == tmp_state::include)
    {
        this->IncludedTempNum.push_back(num);
    }
    else if(state == tmp_state::exclude)
    {
        auto position = element_position(IncludedTempNum,num);
        IncludedTempNum.removeOne(position);
    }
}
