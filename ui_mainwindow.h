/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QProgressBar *progressBar;
    QGraphicsView *graphicsViewCamRight;
    QLabel *labelProtocolRight;
    QToolButton *toolButtonSave;
    QLineEdit *lineEditRtspLeft;
    QToolButton *toolButtonOpen;
    QLabel *labelProtocolLeft;
    QGraphicsView *graphicsViewCamLeft;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelC;
    QSlider *horizontalSliderC;
    QLabel *labelBlsize;
    QSlider *horizontalSliderBlsize;
    QLineEdit *lineEditRtspRight;
    QLineEdit *lineEditOpen;
    QLineEdit *lineEditSave;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *RGB;
    QRadioButton *GRAY;
    QRadioButton *THRESH;
    QFrame *frame;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QSlider *horizontalSliderPlayer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonPrev;
    QToolButton *toolButtonPlay;
    QToolButton *toolButtonNext;
    QLabel *labelAngle;
    QLabel *labelRange;
    QDoubleSpinBox *doubleSpinBoxRange;
    QDoubleSpinBox *doubleSpinBoxAngle;
    QWidget *tab_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonMove;
    QPushButton *pushButtonApply;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelCamRight;
    QDoubleSpinBox *doubleSpinBoxLatRight;
    QDoubleSpinBox *doubleSpinBoxLonRight;
    QSpinBox *spinBoxRotRight;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelCamLeft;
    QDoubleSpinBox *doubleSpinBoxLatLeft;
    QDoubleSpinBox *doubleSpinBoxLonLeft;
    QSpinBox *spinBoxRotLeft;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelLat;
    QLabel *labelLon;
    QLabel *labelRot;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1920, 1080);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/mainwindow.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1920, 1080));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        progressBar = new QProgressBar(tab);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(1640, 880, 261, 23));
        progressBar->setValue(0);
        graphicsViewCamRight = new QGraphicsView(tab);
        graphicsViewCamRight->setObjectName(QString::fromUtf8("graphicsViewCamRight"));
        graphicsViewCamRight->setGeometry(QRect(970, 10, 941, 791));
        labelProtocolRight = new QLabel(tab);
        labelProtocolRight->setObjectName(QString::fromUtf8("labelProtocolRight"));
        labelProtocolRight->setGeometry(QRect(980, 800, 41, 21));
        toolButtonSave = new QToolButton(tab);
        toolButtonSave->setObjectName(QString::fromUtf8("toolButtonSave"));
        toolButtonSave->setGeometry(QRect(1860, 910, 41, 20));
        lineEditRtspLeft = new QLineEdit(tab);
        lineEditRtspLeft->setObjectName(QString::fromUtf8("lineEditRtspLeft"));
        lineEditRtspLeft->setGeometry(QRect(70, 800, 881, 21));
        toolButtonOpen = new QToolButton(tab);
        toolButtonOpen->setObjectName(QString::fromUtf8("toolButtonOpen"));
        toolButtonOpen->setGeometry(QRect(1860, 940, 41, 20));
        labelProtocolLeft = new QLabel(tab);
        labelProtocolLeft->setObjectName(QString::fromUtf8("labelProtocolLeft"));
        labelProtocolLeft->setGeometry(QRect(20, 800, 47, 21));
        graphicsViewCamLeft = new QGraphicsView(tab);
        graphicsViewCamLeft->setObjectName(QString::fromUtf8("graphicsViewCamLeft"));
        graphicsViewCamLeft->setGeometry(QRect(10, 9, 941, 791));
        graphicsViewCamLeft->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsViewCamLeft->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 830, 291, 121));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(true);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 271, 52));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelC = new QLabel(formLayoutWidget);
        labelC->setObjectName(QString::fromUtf8("labelC"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelC);

        horizontalSliderC = new QSlider(formLayoutWidget);
        horizontalSliderC->setObjectName(QString::fromUtf8("horizontalSliderC"));
        horizontalSliderC->setMinimum(3);
        horizontalSliderC->setValue(15);
        horizontalSliderC->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, horizontalSliderC);

        labelBlsize = new QLabel(formLayoutWidget);
        labelBlsize->setObjectName(QString::fromUtf8("labelBlsize"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelBlsize);

        horizontalSliderBlsize = new QSlider(formLayoutWidget);
        horizontalSliderBlsize->setObjectName(QString::fromUtf8("horizontalSliderBlsize"));
        horizontalSliderBlsize->setMinimum(3);
        horizontalSliderBlsize->setValue(15);
        horizontalSliderBlsize->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, horizontalSliderBlsize);

        lineEditRtspRight = new QLineEdit(tab);
        lineEditRtspRight->setObjectName(QString::fromUtf8("lineEditRtspRight"));
        lineEditRtspRight->setGeometry(QRect(1030, 801, 881, 20));
        lineEditOpen = new QLineEdit(tab);
        lineEditOpen->setObjectName(QString::fromUtf8("lineEditOpen"));
        lineEditOpen->setGeometry(QRect(1640, 940, 211, 21));
        lineEditSave = new QLineEdit(tab);
        lineEditSave->setObjectName(QString::fromUtf8("lineEditSave"));
        lineEditSave->setGeometry(QRect(1640, 910, 211, 21));
        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 910, 271, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        RGB = new QRadioButton(horizontalLayoutWidget_2);
        RGB->setObjectName(QString::fromUtf8("RGB"));

        horizontalLayout_2->addWidget(RGB);

        GRAY = new QRadioButton(horizontalLayoutWidget_2);
        GRAY->setObjectName(QString::fromUtf8("GRAY"));

        horizontalLayout_2->addWidget(GRAY);

        THRESH = new QRadioButton(horizontalLayoutWidget_2);
        THRESH->setObjectName(QString::fromUtf8("THRESH"));

        horizontalLayout_2->addWidget(THRESH);

        frame = new QFrame(tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(450, 830, 1021, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_4 = new QWidget(frame);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 10, 1001, 41));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSliderPlayer = new QSlider(verticalLayoutWidget_4);
        horizontalSliderPlayer->setObjectName(QString::fromUtf8("horizontalSliderPlayer"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSliderPlayer->sizePolicy().hasHeightForWidth());
        horizontalSliderPlayer->setSizePolicy(sizePolicy);
        horizontalSliderPlayer->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(horizontalSliderPlayer, 0, Qt::AlignVCenter);

        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(410, 60, 201, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButtonPrev = new QToolButton(horizontalLayoutWidget);
        toolButtonPrev->setObjectName(QString::fromUtf8("toolButtonPrev"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButtonPrev->sizePolicy().hasHeightForWidth());
        toolButtonPrev->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(toolButtonPrev);

        toolButtonPlay = new QToolButton(horizontalLayoutWidget);
        toolButtonPlay->setObjectName(QString::fromUtf8("toolButtonPlay"));
        sizePolicy1.setHeightForWidth(toolButtonPlay->sizePolicy().hasHeightForWidth());
        toolButtonPlay->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(toolButtonPlay);

        toolButtonNext = new QToolButton(horizontalLayoutWidget);
        toolButtonNext->setObjectName(QString::fromUtf8("toolButtonNext"));
        sizePolicy1.setHeightForWidth(toolButtonNext->sizePolicy().hasHeightForWidth());
        toolButtonNext->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(toolButtonNext);

        labelAngle = new QLabel(tab);
        labelAngle->setObjectName(QString::fromUtf8("labelAngle"));
        labelAngle->setGeometry(QRect(330, 880, 39, 21));
        labelAngle->setAlignment(Qt::AlignCenter);
        labelRange = new QLabel(tab);
        labelRange->setObjectName(QString::fromUtf8("labelRange"));
        labelRange->setGeometry(QRect(330, 850, 39, 23));
        labelRange->setAlignment(Qt::AlignCenter);
        doubleSpinBoxRange = new QDoubleSpinBox(tab);
        doubleSpinBoxRange->setObjectName(QString::fromUtf8("doubleSpinBoxRange"));
        doubleSpinBoxRange->setGeometry(QRect(370, 850, 71, 21));
        doubleSpinBoxRange->setDecimals(4);
        doubleSpinBoxRange->setMaximum(1000.000000000000000);
        doubleSpinBoxAngle = new QDoubleSpinBox(tab);
        doubleSpinBoxAngle->setObjectName(QString::fromUtf8("doubleSpinBoxAngle"));
        doubleSpinBoxAngle->setGeometry(QRect(370, 880, 71, 21));
        doubleSpinBoxAngle->setMaximum(180.000000000000000);
        tabWidget->addTab(tab, QString());
        frame->raise();
        progressBar->raise();
        graphicsViewCamRight->raise();
        labelProtocolRight->raise();
        toolButtonSave->raise();
        lineEditRtspLeft->raise();
        toolButtonOpen->raise();
        labelProtocolLeft->raise();
        graphicsViewCamLeft->raise();
        groupBox->raise();
        lineEditRtspRight->raise();
        lineEditOpen->raise();
        lineEditSave->raise();
        horizontalLayoutWidget_2->raise();
        labelAngle->raise();
        labelRange->raise();
        doubleSpinBoxRange->raise();
        doubleSpinBoxAngle->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayoutWidget = new QWidget(tab_2);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 9, 881, 811));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(920, 10, 981, 811));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButtonDelete = new QPushButton(tab_2);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(250, 880, 61, 21));
        pushButtonMove = new QPushButton(tab_2);
        pushButtonMove->setObjectName(QString::fromUtf8("pushButtonMove"));
        pushButtonMove->setGeometry(QRect(250, 920, 61, 21));
        pushButtonApply = new QPushButton(tab_2);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));
        pushButtonApply->setGeometry(QRect(250, 840, 61, 21));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 820, 231, 161));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 30, 84, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelCamRight = new QLabel(verticalLayoutWidget);
        labelCamRight->setObjectName(QString::fromUtf8("labelCamRight"));
        labelCamRight->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelCamRight);

        doubleSpinBoxLatRight = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBoxLatRight->setObjectName(QString::fromUtf8("doubleSpinBoxLatRight"));
        doubleSpinBoxLatRight->setDecimals(4);
        doubleSpinBoxLatRight->setMinimum(-180.000000000000000);
        doubleSpinBoxLatRight->setMaximum(180.000000000000000);

        verticalLayout->addWidget(doubleSpinBoxLatRight);

        doubleSpinBoxLonRight = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBoxLonRight->setObjectName(QString::fromUtf8("doubleSpinBoxLonRight"));
        doubleSpinBoxLonRight->setDecimals(4);
        doubleSpinBoxLonRight->setMinimum(-180.000000000000000);
        doubleSpinBoxLonRight->setMaximum(180.000000000000000);

        verticalLayout->addWidget(doubleSpinBoxLonRight);

        spinBoxRotRight = new QSpinBox(verticalLayoutWidget);
        spinBoxRotRight->setObjectName(QString::fromUtf8("spinBoxRotRight"));
        spinBoxRotRight->setMaximum(360);

        verticalLayout->addWidget(spinBoxRotRight);

        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(50, 30, 84, 111));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelCamLeft = new QLabel(verticalLayoutWidget_2);
        labelCamLeft->setObjectName(QString::fromUtf8("labelCamLeft"));
        labelCamLeft->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(labelCamLeft);

        doubleSpinBoxLatLeft = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBoxLatLeft->setObjectName(QString::fromUtf8("doubleSpinBoxLatLeft"));
        doubleSpinBoxLatLeft->setDecimals(4);
        doubleSpinBoxLatLeft->setMinimum(-180.000000000000000);
        doubleSpinBoxLatLeft->setMaximum(180.000000000000000);

        verticalLayout_2->addWidget(doubleSpinBoxLatLeft);

        doubleSpinBoxLonLeft = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBoxLonLeft->setObjectName(QString::fromUtf8("doubleSpinBoxLonLeft"));
        doubleSpinBoxLonLeft->setDecimals(4);
        doubleSpinBoxLonLeft->setMinimum(-180.000000000000000);
        doubleSpinBoxLonLeft->setMaximum(180.000000000000000);

        verticalLayout_2->addWidget(doubleSpinBoxLonLeft);

        spinBoxRotLeft = new QSpinBox(verticalLayoutWidget_2);
        spinBoxRotLeft->setObjectName(QString::fromUtf8("spinBoxRotLeft"));
        spinBoxRotLeft->setMaximum(360);

        verticalLayout_2->addWidget(spinBoxRotLeft);

        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 60, 41, 81));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelLat = new QLabel(verticalLayoutWidget_3);
        labelLat->setObjectName(QString::fromUtf8("labelLat"));
        labelLat->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelLat);

        labelLon = new QLabel(verticalLayoutWidget_3);
        labelLon->setObjectName(QString::fromUtf8("labelLon"));
        labelLon->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelLon);

        labelRot = new QLabel(verticalLayoutWidget_3);
        labelRot->setObjectName(QString::fromUtf8("labelRot"));
        labelRot->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(labelRot);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Birds", nullptr));
        labelProtocolRight->setText(QCoreApplication::translate("MainWindow", "RTSP", nullptr));
        toolButtonSave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        toolButtonOpen->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        labelProtocolLeft->setText(QCoreApplication::translate("MainWindow", "RTSP", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "IMAGE", nullptr));
        labelC->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        labelBlsize->setText(QCoreApplication::translate("MainWindow", "Block_size", nullptr));
        RGB->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        GRAY->setText(QCoreApplication::translate("MainWindow", "GRAY", nullptr));
        THRESH->setText(QCoreApplication::translate("MainWindow", "THRESHOLD", nullptr));
        toolButtonPrev->setText(QCoreApplication::translate("MainWindow", "prev", nullptr));
        toolButtonPlay->setText(QCoreApplication::translate("MainWindow", "play", nullptr));
        toolButtonNext->setText(QCoreApplication::translate("MainWindow", "next", nullptr));
        labelAngle->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        labelRange->setText(QCoreApplication::translate("MainWindow", "Range", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButtonMove->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        pushButtonApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Cam position", nullptr));
        labelCamRight->setText(QCoreApplication::translate("MainWindow", "Cam 2", nullptr));
        labelCamLeft->setText(QCoreApplication::translate("MainWindow", "Cam 1", nullptr));
        labelLat->setText(QCoreApplication::translate("MainWindow", "Lat", nullptr));
        labelLon->setText(QCoreApplication::translate("MainWindow", "Lon", nullptr));
        labelRot->setText(QCoreApplication::translate("MainWindow", "Rot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
