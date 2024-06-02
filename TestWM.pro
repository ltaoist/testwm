QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += /usr/include/KF5/KWindowSystem /usr/include/KF5/KScreen

LIBS += -lX11 -lxcb -lKF5WindowSystem -lKF5Screen

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Background.cpp \
    MonitorConfig.cpp \
    SettingPanel.cpp \
    StartMenu.cpp \
    TaskBar.cpp \
    dpi.cpp \
    main.cpp

HEADERS += \
    Background.h \
    GetConfig.h \
    MonitorConfig.h \
    SettingPanel.h \
    StartMenu.h \
    TaskBar.h \
    dpi.h

FORMS += \
    Background.ui \
    SettingPanel.ui \
    StartMenu.ui \
    TaskBar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Wallpaper.qrc
