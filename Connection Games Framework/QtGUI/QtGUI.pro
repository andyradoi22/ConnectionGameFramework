QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Board.cpp \
    Cells.cpp \
    ConnectionGames.cpp \
    HavannahBoard.cpp \
    HavannahGameLogic.cpp \
    HexBoard.cpp \
    HexGameLogic.cpp \
    Player.cpp \
    YBoard.cpp \
    YGameLogic.cpp \
    havannahmenu.cpp \
    havannahrules.cpp \
    havannahui.cpp \
    hexmenu.cpp \
    hexrules.cpp \
    hexui.cpp \
    main.cpp \
    mainmenu.cpp \
    ymenu.cpp \
    yrules.cpp \
    yui.cpp

HEADERS += \
    Board.h \
    ConnectionGames.h \
    GameLogic.h \
    HavannahBoard.h \
    HavannahGameLogic.h \
    HexBoard.h \
    HexGameLogic.h \
    Player.h \
    YBoard.h \
    YGameLogic.h \
    havannahmenu.h \
    havannahrules.h \
    havannahui.h \
    hexmenu.h \
    hexrules.h \
    hexui.h \
    mainmenu.h \
    ymenu.h \
    yrules.h \
    yui.h

FORMS += \
    havannahmenu.ui \
    havannahrules.ui \
    havannahui.ui \
    hexmenu.ui \
    hexrules.ui \
    hexui.ui \
    mainmenu.ui \
    ymenu.ui \
    yrules.ui \
    yui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../GUI pictures/ColorMenu.JPG \
    ../GUI pictures/Connection Games Framework GUI.jpg \
    ../GUI pictures/PozaTestBkgd.jpg \
    ../GUI pictures/Start window v0.png
