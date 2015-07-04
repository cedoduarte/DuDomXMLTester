#-------------------------------------------------
#
# Project created by QtCreator 2015-07-04T13:30:54
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuDomXMLTester

TEMPLATE = app

SOURCES += main.cpp\
        MainWindow.cpp \
    AgregarDialog.cpp \
    Empleado.cpp

HEADERS  += MainWindow.h \
    AgregarDialog.h \
    Empleado.h

FORMS    += MainWindow.ui \
    AgregarDialog.ui

QMAKE_CXXFLAGS += -std=gnu++14
