/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonPrev;
    QToolButton *toolButtonPlay;
    QToolButton *toolButtonNext;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QSlider *horizontalSliderPlayer;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelRange;
    QLabel *labelAngle;
    QLabel *label;
    QVBoxLayout *verticalLayout_6;
    QDoubleSpinBox *doubleSpinBoxRange;
    QDoubleSpinBox *doubleSpinBoxAngle;
    QDoubleSpinBox *doubleSpinBoxBAngle;
    QSlider *verticalSlider;
    QWidget *tab_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
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
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_8;
    QPushButton *pushButtonApply;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonMove;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelTheme;
    QComboBox *comboBoxTheme;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1920, 1080);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/mainwindow.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        groupBox->setFlat(false);
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

        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(860, 890, 201, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButtonPrev = new QToolButton(horizontalLayoutWidget);
        toolButtonPrev->setObjectName(QString::fromUtf8("toolButtonPrev"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonPrev->sizePolicy().hasHeightForWidth());
        toolButtonPrev->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/go-previous-symbolic.symbolic.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonPrev->setIcon(icon1);

        horizontalLayout->addWidget(toolButtonPrev);

        toolButtonPlay = new QToolButton(horizontalLayoutWidget);
        toolButtonPlay->setObjectName(QString::fromUtf8("toolButtonPlay"));
        sizePolicy.setHeightForWidth(toolButtonPlay->sizePolicy().hasHeightForWidth());
        toolButtonPlay->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/pp.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonPlay->setIcon(icon2);

        horizontalLayout->addWidget(toolButtonPlay);

        toolButtonNext = new QToolButton(horizontalLayoutWidget);
        toolButtonNext->setObjectName(QString::fromUtf8("toolButtonNext"));
        sizePolicy.setHeightForWidth(toolButtonNext->sizePolicy().hasHeightForWidth());
        toolButtonNext->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/go-next-symbolic.symbolic.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonNext->setIcon(icon3);

        horizontalLayout->addWidget(toolButtonNext);

        verticalLayoutWidget_4 = new QWidget(tab);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(590, 840, 741, 41));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSliderPlayer = new QSlider(verticalLayoutWidget_4);
        horizontalSliderPlayer->setObjectName(QString::fromUtf8("horizontalSliderPlayer"));
        sizePolicy.setHeightForWidth(horizontalSliderPlayer->sizePolicy().hasHeightForWidth());
        horizontalSliderPlayer->setSizePolicy(sizePolicy);
        horizontalSliderPlayer->setFocusPolicy(Qt::StrongFocus);
        horizontalSliderPlayer->setOrientation(Qt::Horizontal);
        horizontalSliderPlayer->setTickPosition(QSlider::TicksAbove);

        verticalLayout_4->addWidget(horizontalSliderPlayer, 0, Qt::AlignVCenter);

        horizontalLayoutWidget_3 = new QWidget(tab);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(320, 840, 131, 91));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelRange = new QLabel(horizontalLayoutWidget_3);
        labelRange->setObjectName(QString::fromUtf8("labelRange"));
        labelRange->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(labelRange);

        labelAngle = new QLabel(horizontalLayoutWidget_3);
        labelAngle->setObjectName(QString::fromUtf8("labelAngle"));
        labelAngle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(labelAngle);

        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_5->addWidget(label);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        doubleSpinBoxRange = new QDoubleSpinBox(horizontalLayoutWidget_3);
        doubleSpinBoxRange->setObjectName(QString::fromUtf8("doubleSpinBoxRange"));
        doubleSpinBoxRange->setDecimals(4);
        doubleSpinBoxRange->setMaximum(1000.000000000000000);
        doubleSpinBoxRange->setValue(2.640000000000000);

        verticalLayout_6->addWidget(doubleSpinBoxRange);

        doubleSpinBoxAngle = new QDoubleSpinBox(horizontalLayoutWidget_3);
        doubleSpinBoxAngle->setObjectName(QString::fromUtf8("doubleSpinBoxAngle"));
        doubleSpinBoxAngle->setMaximum(180.000000000000000);

        verticalLayout_6->addWidget(doubleSpinBoxAngle);

        doubleSpinBoxBAngle = new QDoubleSpinBox(horizontalLayoutWidget_3);
        doubleSpinBoxBAngle->setObjectName(QString::fromUtf8("doubleSpinBoxBAngle"));
        doubleSpinBoxBAngle->setMaximum(180.000000000000000);

        verticalLayout_6->addWidget(doubleSpinBoxBAngle);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalSlider = new QSlider(tab);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setGeometry(QRect(950, 10, 21, 791));
        verticalSlider->setMaximum(1080);
        verticalSlider->setValue(0);
        verticalSlider->setOrientation(Qt::Vertical);
        tabWidget->addTab(tab, QString());
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

        verticalLayoutWidget_7 = new QWidget(tab_2);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(250, 850, 82, 86));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        pushButtonApply = new QPushButton(verticalLayoutWidget_7);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));

        verticalLayout_8->addWidget(pushButtonApply);

        pushButtonDelete = new QPushButton(verticalLayoutWidget_7);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));

        verticalLayout_8->addWidget(pushButtonDelete);

        pushButtonMove = new QPushButton(verticalLayoutWidget_7);
        pushButtonMove->setObjectName(QString::fromUtf8("pushButtonMove"));

        verticalLayout_8->addWidget(pushButtonMove);

        horizontalLayoutWidget_4 = new QWidget(tab_2);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(1760, 840, 141, 80));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        labelTheme = new QLabel(horizontalLayoutWidget_4);
        labelTheme->setObjectName(QString::fromUtf8("labelTheme"));
        labelTheme->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(labelTheme);

        comboBoxTheme = new QComboBox(horizontalLayoutWidget_4);
        comboBoxTheme->addItem(QString());
        comboBoxTheme->addItem(QString());
        comboBoxTheme->setObjectName(QString::fromUtf8("comboBoxTheme"));

        horizontalLayout_4->addWidget(comboBoxTheme);

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
        labelRange->setText(QCoreApplication::translate("MainWindow", "Range", nullptr));
        labelAngle->setText(QCoreApplication::translate("MainWindow", "Angle", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "BAngle", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Cam position", nullptr));
        labelCamRight->setText(QCoreApplication::translate("MainWindow", "Cam Right", nullptr));
        labelCamLeft->setText(QCoreApplication::translate("MainWindow", "Cam Left", nullptr));
        labelLat->setText(QCoreApplication::translate("MainWindow", "Lat", nullptr));
        labelLon->setText(QCoreApplication::translate("MainWindow", "Lon", nullptr));
        labelRot->setText(QCoreApplication::translate("MainWindow", "Rot", nullptr));
        pushButtonApply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButtonMove->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        labelTheme->setText(QCoreApplication::translate("MainWindow", "Theme", nullptr));
        comboBoxTheme->setItemText(0, QCoreApplication::translate("MainWindow", "Ubuntu", nullptr));
        comboBoxTheme->setItemText(1, QCoreApplication::translate("MainWindow", "MaterialDark", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
