#include "Background.h"
#include "ui_Background.h"
#include "SetupEverything.h"
#include "dpi.h"

#include <xcb/xcb.h>
#include <X11/Xlib.h>

Background::Background(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Background)
{
    ui->setupUi(this);

    {
        Qt::WindowFlags WinFlags = Qt::FramelessWindowHint;
        WinFlags |= Qt::Window;
        setWindowFlags(WinFlags);
        setAttribute(Qt::WA_X11NetWmWindowTypeDesktop);
    }

    {
        auto config = GetConfig();
        auto ScreenList = GetScreenList();
        auto geo = ScreenList[0]->geometry();
        auto width = geo.width();
        auto height = geo.height();
        int BackgroundHeight, TaskBarHeight;
        GetTowPartsScale(height, config->TaskBarHeight, TaskBarHeight, BackgroundHeight);
        move(0, 0);
        resize(width, BackgroundHeight);
    }

}

Background::~Background()
{
    delete ui;
}


bool Background::event(QEvent *event) {
    switch(event->type()){
    case QEvent::WinIdChange: {
        if(effectiveWinId() == 0){
            break;
        }
        {
            if(QGuiApplication::platformName() == QStringLiteral("xcb")) {
                if(auto x11NativeInterfce = qApp->nativeInterface<QNativeInterface::QX11Application>()) {
                    xcb_connection_t* con = x11NativeInterfce->connection();
                    const char* atom_name = "_NET_WM_WINDOW_TYPE_DESKTOP";
                    xcb_atom_t atom = xcb_intern_atom_reply(con, xcb_intern_atom(con, 0, strlen(atom_name), atom_name), nullptr)->atom;
                    const char* prop_atom_name = "_NET_WM_WINDOW_TYPE";
                    xcb_atom_t prop_atom = xcb_intern_atom_reply(con, xcb_intern_atom(con, 0, strlen(prop_atom_name), prop_atom_name), nullptr)->atom;
                    xcb_atom_t XA_ATOM = 4;
                    xcb_change_property(con, XCB_PROP_MODE_REPLACE, effectiveWinId(), prop_atom, XA_ATOM, 32, 1, &atom);
                }
            }
        }
    }
    }
    return QWidget::event(event);

}

void Background::on_pushButton_clicked()
{
    OpenStartMenu();
}

