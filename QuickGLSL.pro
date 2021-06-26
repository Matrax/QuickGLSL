QT += core gui
QT += widgets
QT += openglwidgets

CONFIG += c++17 qt shared no_batch

SOURCES += \
    AppConsole.cpp \
    AppContext.cpp \
    AppEditor.cpp \
    AppLayout.cpp \
    AppMenuBar.cpp \
    AppWindow.cpp \
    Main.cpp \
    SmoothRandomGenerator.cpp

HEADERS += \
    AppConsole.h \
    AppContext.h \
    AppEditor.h \
    AppLayout.h \
    AppMenuBar.h \
    AppWindow.h \
    SmoothRandomGenerator.h

CONFIG += debug_and_release \
          debug_and_release_target \
          warn_on

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
