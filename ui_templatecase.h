/********************************************************************************
** Form generated from reading UI file 'templatecase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATECASE_H
#define UI_TEMPLATECASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TemplateCase
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *TemplateCase)
    {
        if (TemplateCase->objectName().isEmpty())
            TemplateCase->setObjectName(QString::fromUtf8("TemplateCase"));
        TemplateCase->resize(600, 200);
        scrollArea = new QScrollArea(TemplateCase);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 600, 200));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setMidLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 598, 198));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(TemplateCase);

        QMetaObject::connectSlotsByName(TemplateCase);
    } // setupUi

    void retranslateUi(QWidget *TemplateCase)
    {
        TemplateCase->setWindowTitle(QCoreApplication::translate("TemplateCase", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TemplateCase: public Ui_TemplateCase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATECASE_H
