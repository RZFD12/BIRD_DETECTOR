#include "templatecase.h"
#include "ui_templatecase.h"
#include <QtDebug>

myLabel::myLabel(cv::Mat frame,int pos, QWidget *parent)
:QLabel(parent)
{
    box=new QCheckBox(this);
    box->setFixedSize(10,10);
    Vbox= new QVBoxLayout(this);
    Vbox->addWidget(box,Qt::AlignTop);
    this->setLayout(Vbox);
    this->setLineWidth(2);
    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    box->setChecked(false);
    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
    QPixmap pixmap(QPixmap::fromImage(qimg.rgbSwapped()));
    this->setAlignment(Qt::AlignCenter);
    this->setPixmap(pixmap);
    this->position=pos;
}

void myLabel::slotClicked()
{
    this->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    box->setChecked(true);
    emit MyState(this->position,tmp_state::include);
}
void myLabel::mousePressEvent ( QMouseEvent * event )
{
    emit clicked();
    if(box->isChecked()){unclecked();}
    else{slotClicked();}
    Q_UNUSED(event);
}
void myLabel::unclecked(){
    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    box->setChecked(false);
    emit MyState(this->position,tmp_state::exclude);
}

TemplateCase::TemplateCase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TemplateCase)
{
    ui->setupUi(this);
    QWidget *w=new QWidget(this);
    w->setLayout(&layout);
    ui->scrollArea->setWidget(w);
}

TemplateCase::~TemplateCase()
{
    delete ui;
}

void TemplateCase::set_template(QVector<cv::Mat> &templastes)

{
    QVector<cv::Mat>::iterator it;
    int posx=0;
    int posy=0;
    int count=this->width()/55;
    int iter=0;
    for(it=templastes.begin();it!=templastes.end();it++)
    {
        if(posx>count){posx=0;posy++;}
        myLabel* label=new myLabel((*it),iter,this);
        connect(label,&myLabel::MyState,this,&TemplateCase::labels_state);
        label->setFixedSize(55,55);
        layout.addWidget(label,posy,posx);
        posx++;
        iter++;
    }
}

int element_position(QList<int> & lst,int num){

    int position=0;

    for(int i=0;i<lst.length();++i){

        if(lst[i]==num){
            position=i;
            break;
        }
        else {

            continue;
        }
    }

    return position;

}

void TemplateCase::labels_state(int num, tmp_state state)
{
    qDebug()<<num;

    if(state==tmp_state::include){
        this->IncludedTempNum.push_back(num);
    }

    if(state==tmp_state::exclude){

        int position=element_position(IncludedTempNum,num);
        IncludedTempNum.removeOne(position);
    }

    // надо законектить эту штуку с имгдата шобы шаблон значит убираешь и корреляция хоба говорит досвидули
    // отправка указателя на шото там


}

QList<int> *TemplateCase::includedtmp()
{
    return &IncludedTempNum;
}
