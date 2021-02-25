TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        deflate.cpp \
        fixedhuffman.cpp \
        huffman.cpp \
        lz77.cpp \
        main.cpp

HEADERS += \
    deflate.h \
    fixedhuffman.h \
    huffman.h \
    lz77.h
