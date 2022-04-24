QT += core gui multimedia network multimediawidgets widgets quickwidgets positioning
QT += datavisualization
QT += charts

SOURCES += \
    filehandler.cpp \
    flatto3d.cpp \
    frame.cpp \
    imgdata.cpp \
    main.cpp \
    mainwindow.cpp \
    scatterdatamodifier.cpp \
    template_reader.cpp

HEADERS += \
    filehandler.h \
    flatto3d.h \
    frame.h \
    imgdata.h \
    mainwindow.h \
    scatterdatamodifier.h \
    template_reader.h

FORMS += \
    mainwindow.ui

win32{
    INCLUDEPATH += $$(OPENCV_SDK_DIR)\include
    LIBS += $$(OPENCV_SDK_DIR)\x64\mingw\bin\libopencv_*
}
unix{
    INCLUDEPATH += /usr/local/include
    LIBS += /usr/local/lib/libopencv_*
}

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc
