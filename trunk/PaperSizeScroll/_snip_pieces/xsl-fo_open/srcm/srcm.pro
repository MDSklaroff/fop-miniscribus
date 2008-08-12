######################################################################
# Automatically generated by qmake (2.01a) dom 6. lug 10:23:17 2008
######################################################################

TEMPLATE = app
TARGET = xx
DEPENDPATH += . instance qwwrichtextedit  session struct ui
INCLUDEPATH += . instance qwwrichtextedit session struct ui


MOC_DIR	= build/.moc
RCC_DIR	= build/.rcc
OBJECTS_DIR = build/.obj



win32 {
    ########## window no qt 4.5 pwd  #############
    BUILD_TREE_PATH = $$PWD 
    message(Window path  $$BUILD_TREE_PATH)
} 




DESTDIR	+= ./
QT += xml network svg 
CONFIG   +=  qt debug warn_off console
contains(QT_CONFIG, opengl):QT += opengl

!include( ../config.pri ) {
message( "../config.pri not found" )
error(An error has occurred in the configuration process.) 
}


LIBS   += -L../lib/ -leditor


# Input
HEADERS += instance/singleapplication.h \
           instance/singleapplication_p.h \
           qwwrichtextedit/qwwcolorbutton.h \
           qwwrichtextedit/qwwrichtextedit.h \
           qwwrichtextedit/wwglobal.h \
           qwwrichtextedit/colormodel.h \
           qwwrichtextedit/wwglobal_p.h \
           session/SessionManager.h \
           struct/Basic_Config.h \
           struct/Fop_Leader_Element.h \
           struct/Fo_Format.h \
           struct/Fo_Reader.h \
           struct/Fo_Writter.h \
           struct/GSInterlace.h \
           struct/pics_structure.h \
           struct/richdoc_structure.h
FORMS += ui/gmain.ui
SOURCES += main.cpp \
           instance/singleapplication.cpp \
           qwwrichtextedit/qwwcolorbutton.cpp \
           qwwrichtextedit/qwwrichtextedit.cpp \
           qwwrichtextedit/wwglobal_p.cpp \
           qwwrichtextedit/colormodel.cpp \
           session/SessionManager.cpp \
           struct/Fo_Format.cpp \
           struct/Fo_Reader.cpp \
           struct/Fop_Leader_Element.cpp \
           struct/Fo_Writter.cpp \
           struct/GSInterlace.cpp \
           struct/pics_structure.cpp \
           struct/richdoc_structure.cpp
           
           
           
RESOURCES += resources.qrc
