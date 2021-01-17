QT       += core gui
QT       += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Toolfunction.cpp \
    drawing_dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    progress_dialog.cpp \
    searching_dialog.cpp \
    searchthread.cpp \
    workerthread.cpp

HEADERS += \
    Toolfunction.h \
    drawing_dialog.h \
    mainwindow.h \
    progress_dialog.h \
    searching_dialog.h \
    searchthread.h \
    workerthread.h

FORMS += \
    drawing_dialog.ui \
    mainwindow.ui \
    progress_dialog.ui \
    searching_dialog.ui

TRANSLATIONS += \
    Taxi_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    map.qrc

RC_ICONS = didi.ico
