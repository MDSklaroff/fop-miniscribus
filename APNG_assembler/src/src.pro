######################################################################
# Automatically generated by qmake (2.01a) mer 21. mag 16:45:29 2008
######################################################################

TEMPLATE = app
TARGET = apng
DEPENDPATH += . ui ../moz_png ../zlib
INCLUDEPATH += ui ../moz_png ../zlib

message(Qt version: $$[QT_VERSION])
message("Alert usage from Mozilla dev PNG LIBs")

QT += qt3support


###############  include zu C:\Qt\4.4.4_src\src\3rdparty

DESTDIR	+= ../


LIBS   += -L../lib/ -lmozpng


CONFIG   += qt warn_off release console

# Input
HEADERS +=   ../moz_png/png.h
#########FORMS += ui/gmain.ui
SOURCES +=  main.cpp  















