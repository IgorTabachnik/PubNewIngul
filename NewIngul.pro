#-------------------------------------------------
#
# Project created by QtCreator 2019-06-26T19:52:10
#
#-------------------------------------------------

QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NewIngul
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    GUI/choiceexercises.cpp \
    GUI/choicewindow.cpp \
    GUI/listseditor.cpp \
    GUI/mainmenu.cpp \
    GUI/mainwindow.cpp \
    GUI/movingexercises.cpp \
    GUI/settingmenu.cpp \
        main.cpp \
    target2.cpp \
    target_info.cpp \
    tir.cpp \
    formgroup.cpp

HEADERS += \
    GUI/choiceexercises.h \
    GUI/choicewindow.h \
    GUI/listseditor.h \
    GUI/mainmenu.h \
    GUI/mainwindow.h \
    GUI/movingexercises.h \
    GUI/settingmenu.h \
    target2.h \
    target_info.h \
    tir.h \
    target.h \
    bullet_info.h \
    formgroup.h

FORMS += \
    GUI/choiceexercises.ui \
    GUI/choicewindow.ui \
    GUI/listseditor.ui \
    GUI/mainmenu.ui \
    GUI/mainwindow.ui \
    GUI/movingexercises.ui \
    GUI/settingmenu.ui \
    tir.ui \
    formgroup.ui \
    originalTirUI/Film.ui \
    originalTirUI/Game1.ui \
    originalTirUI/Game2.ui \
    originalTirUI/Game3.ui \
    originalTirUI/Game4.ui \
    originalTirUI/Game5.ui \
    originalTirUI/Game6.ui \
    originalTirUI/Game7.ui \
    originalTirUI/Games.ui \
    originalTirUI/Liss.ui \
    originalTirUI/Param.ui \
    originalTirUI/Stand.ui \
    originalTirUI/Start.ui \
    originalTirUI/T3dat.ui \
    originalTirUI/T6dat.ui \
    originalTirUI/Uprav.ui \
    originalTirUI/Vrez.ui \
    originalTirUI/Calnd.ui \
    originalTirUI/EdTarg.ui \
    originalTirUI/EdUpr.ui

RESOURCES += \
    docs.qrc \
    images.qrc

DISTFILES +=
