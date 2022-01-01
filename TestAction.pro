TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        main.cpp

unix: LIBS += -L$$PWD/../MP21-Team-a5/ -lMP21-Team-a5.1.0.0

INCLUDEPATH += $$PWD/../MP21-Team-a5
DEPENDPATH += $$PWD/../MP21-Team-a5
