QT       += core gui
QT       += serialport
QT       +=sql
INCLUDEPATH+=D:\Eigen
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    databasecontroller.cpp \
    graph.cpp \
    guangmin.cpp \
    main.cpp \
    mainwindow.cpp \
    model.cpp \
    roomcontrol.cpp \
    serialport.cpp \
    shidu_0.cpp \
    simulator.cpp \
    switchbutton.cpp \
    windu.cpp

HEADERS += \
    databasecontroller.h \
    graph.h \
    guangmin.h \
    mainwindow.h \
    model.h \
    roomcontrol.h \
    serialport.h \
    shidu_0.h \
    simulator.h \
    switchbutton.h \
    windu.h

FORMS += \
    graph.ui \
    mainwindow.ui \
    model.ui \
    roomcontrol.ui

TRANSLATIONS += \
    untitled2_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    pictrue.qrc
