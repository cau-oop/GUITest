#-------------------------------------------------
#
# Project created by QtCreator 2018-12-06T15:14:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    memberinfo.cpp \
    password.cpp \
    addpackage.cpp \
    searchpackage.cpp \
    searchresult.cpp \
    login.cpp \
    guestmain.cpp \
    guestmypage.cpp \
    passwordcheck.cpp \
    newphone.cpp \
    newspam.cpp \
    packrank.cpp \
    guiderank.cpp \
    makenew.cpp \
    saveinfo.cpp \
    agencymain.cpp \
    agencyinfo.cpp \
    agencymember.cpp \
    generalmember.cpp \
    guidemember.cpp \
    memberfail.cpp \
    memberfail2.cpp \
    guidemain.cpp \
    guideinfo.cpp \
    loginfail.cpp \
    loginfail2.cpp \
    chat.cpp \
    pay.cpp \
    adtopay.cpp \
    packagereview.cpp

HEADERS += \
        mainwindow.h \
    password.h \
    memberinfo.h \
    addpackage.h \
    searchpackage.h \
    searchresult.h \
    login.h \
    guestmain.h \
    guestmypage.h \
    passwordcheck.h \
    newphone.h \
    newspam.h \
    packrank.h \
    guiderank.h \
    makenew.h \
    objectclassfile.h \
    saveinfo.h \
    agencymain.h \
    agencyinfo.h \
    agencymember.h \
    generalmember.h \
    guidemember.h \
    memberfail.h \
    memberfail2.h \
    guidemain.h \
    guideinfo.h \
    loginfail.h \
    loginfail2.h \
    chat.h \
    pay.h \
    adtopay.h \
    packagereview.h

FORMS += \
        mainwindow.ui \
    memberinfo.ui \
    password.ui \
    addpackage.ui \
    searchpackage.ui \
    searchresult.ui \
    login.ui \
    guestmain.ui \
    guestmypage.ui \
    passwordcheck.ui \
    newphone.ui \
    newspam.ui \
    packrank.ui \
    guiderank.ui \
    makenew.ui \
    saveinfo.ui \
    searchpackage.ui \
    agencymain.ui \
    agencyinfo.ui \
    agencymember.ui \
    generalmember.ui \
    guidemember.ui \
    memberfail.ui \
    memberfail2.ui \
    guidemain.ui \
    guideinfo.ui \
    loginfail.ui \
    loginfail2.ui \
    chat.ui \
    pay.ui \
    adtopay.ui \
    packagereview.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
