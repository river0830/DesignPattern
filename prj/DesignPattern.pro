TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -fpermissive

INCLUDEPATH =           \
    ../app/             \
    ../decorator        \

SOURCES += ../app/main.cpp                  \
           ../decorator/decorator.cpp       \
    ../decorator/discount.cpp

HEADERS += ../decorator/decorator.h         \

