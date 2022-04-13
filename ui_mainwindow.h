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
#include <QtWidgets/QApplication>
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
    QGraphicsView *graphicsView_2;
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *prevButton;
    QToolButton *playButton;
    QToolButton *nextButton;
    QToolButton *toolButton;
    QLineEdit *lineEdit;
    QToolButton *toolButton_2;
    QLabel *label_2;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *RGB;
    QRadioButton *GRAY;
    QRadioButton *THRESH;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_3;
    QWidget *tab_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QSpinBox *spinBox_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QSpinBox *spinBox;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1080);
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
        graphicsView_2 = new QGraphicsView(tab);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(970, 10, 941, 791));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(980, 800, 41, 21));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(860, 840, 201, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        prevButton = new QToolButton(horizontalLayoutWidget);
        prevButton->setObjectName(QString::fromUtf8("prevButton"));

        horizontalLayout->addWidget(prevButton);

        playButton = new QToolButton(horizontalLayoutWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));

        horizontalLayout->addWidget(playButton);

        nextButton = new QToolButton(horizontalLayoutWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout->addWidget(nextButton);

        toolButton = new QToolButton(tab);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(1860, 910, 41, 20));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(70, 800, 881, 21));
        toolButton_2 = new QToolButton(tab);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(1860, 940, 41, 20));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 800, 47, 21));
        graphicsView = new QGraphicsView(tab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 9, 941, 791));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 830, 291, 101));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(true);
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 271, 42));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        horizontalSlider_2 = new QSlider(formLayoutWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(3);
        horizontalSlider_2->setValue(15);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, horizontalSlider_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        horizontalSlider = new QSlider(formLayoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(3);
        horizontalSlider->setValue(15);
        horizontalSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, horizontalSlider);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 70, 271, 31));
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

        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(1030, 800, 881, 21));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(1640, 940, 211, 21));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(1640, 910, 211, 21));
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
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 880, 61, 21));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(250, 920, 61, 21));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 840, 61, 21));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 820, 231, 161));
        verticalLayoutWidget = new QWidget(groupBox_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 30, 84, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_6);

        doubleSpinBox_4 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(4);

        verticalLayout->addWidget(doubleSpinBox_4);

        doubleSpinBox_3 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(4);

        verticalLayout->addWidget(doubleSpinBox_3);

        spinBox_2 = new QSpinBox(verticalLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(360);

        verticalLayout->addWidget(spinBox_2);

        verticalLayoutWidget_2 = new QWidget(groupBox_2);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(50, 30, 84, 111));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        doubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(4);

        verticalLayout_2->addWidget(doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(4);

        verticalLayout_2->addWidget(doubleSpinBox_2);

        spinBox = new QSpinBox(verticalLayoutWidget_2);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximum(360);

        verticalLayout_2->addWidget(spinBox);

        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 60, 31, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_9);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "RTSP", nullptr));
        prevButton->setText(QCoreApplication::translate("MainWindow", "prev", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "play", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "next", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "RTSP", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "IMAGE", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Block_size", nullptr));
        RGB->setText(QCoreApplication::translate("MainWindow", "RGB", nullptr));
        GRAY->setText(QCoreApplication::translate("MainWindow", "GRAY", nullptr));
        THRESH->setText(QCoreApplication::translate("MainWindow", "THRESHOLD", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Cam position", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Cam 2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Cam 1", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Lat", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Lon", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Rot", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
