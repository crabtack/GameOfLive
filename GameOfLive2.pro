TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cell.cpp \
    menu.cpp \
    button.cpp

include(deployment.pri)
qtcAddDeployment()


LIBS += -LD:/SFML2.1/SFML-2.1/lib
CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += D:/SFML2.1/SFML-2.1/include
DEPENDPATH += D:/SFML2.1/SFML-2.1/include

HEADERS += \
    cell.h \
    menu.h \
    button.h



