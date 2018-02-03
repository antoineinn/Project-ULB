#-------------------------------------------------
#
# Project created by QtCreator 2017-03-20T14:32:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app
unix:LIBS += -lncurses
CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14

SOURCES +=../client.cpp\
        loginmenuoption.cpp \
    createaccount.cpp \
    loginmenu.cpp \
    ../ennemy.cpp \
    ../case.cpp \
    ../grid.cpp \
    ../friend.cpp \
    ../game.cpp \
    ../lobby.cpp \
    ../matchmaking.cpp \
    ../matchwrapper.cpp \
    ../menu.cpp \
    ../menu_gui.cpp \
    ../tower.cpp \
    ../wave.cpp \
    ../friend_menu_gui.cpp \
    profilview.cpp \
    friendmenu.cpp \
    menuoption.cpp \
    addfriend.cpp \
    deletefriend.cpp \
    friendlist.cpp \
    rankingview.cpp \
    gamedisplaygui.cpp \
    messageingamepanel.cpp \
    showinfogame.cpp \
    towerpanel.cpp



HEADERS  += loginmenuoption.h \
    createaccount.h \
    loginmenu.h \
    ../case.hpp \
    ../coord.hpp \
    ../ennemy.hpp \
    ../friend.hpp \
    ../game.hpp \
    ../grid.hpp \
    ../lobby.hpp \
    ../matchmaking.hpp \
    ../matchwrapper.hpp \
    ../menu.hpp \
    ../menu_gui.hpp \
    ../tower.hpp \
    ../wave.hpp \
    ../friend_menu_gui.hpp \
    profilview.h \
    friendmenu.h \
    menuoption.h \
    addfriend.h \
    deletefriend.h \
    friendlist.h \
    rankingview.h \
    gamedisplaygui.h \
    messageingamepanel.h \
    showinfogame.h \
    towerpanel.h

FORMS    += loginmenuoption.ui \
    loginmenu.ui \
    createaccount.ui \
    profilview.ui \
    friendmenu.ui \
    menuoption.ui \
    addfriend.ui \
    deletefriend.ui \
    friendlist.ui \
    rankingview.ui \
    messageingamepanel.ui \
    showinfogame.ui \
    towerpanel.ui
