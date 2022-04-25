#include "templatecase.h"
#include "ui_templatecase.h"



myLabel::myLabel(cv::Mat frame, QWidget * parent )
:QLabel(parent)
{
    //connect( this, SIGNAL( clicked()), this, SLOT( slotClicked() ) );

    //connect(this,&myLabel::clicked,this,);

    box=new QCheckBox(this);
    box->setFixedSize(10,10);
    Vbox= new QVBoxLayout(this);
    Vbox->addWidget(box,Qt::AlignTop);
    //Vbox->setAlignment(Qt::AlignHCenter);
    this->setLayout(Vbox);
    this->setLineWidth(2);
    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    box->setChecked(false);
    QImage qimg(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_Grayscale8);
    QPixmap pixmap(QPixmap::fromImage(qimg.rgbSwapped()));


    //pixmap=pixmap.scaled(this->width(),this->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->setAlignment(Qt::AlignCenter);
    this->setPixmap(pixmap);
    //this->setText(QString::number(pos));
}


void myLabel::slotClicked()
{
    this->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    box->setChecked(true);
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

    for(it=templastes.begin();it!=templastes.end();it++){


        if(posx>count){posx=0;posy++;}


        myLabel* label=new myLabel((*it),this);
        label->setFixedSize(55,55);
        layout.addWidget(label,posy,posx);
        posx++;

    }

}
