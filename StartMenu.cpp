#include "StartMenu.h"
#include "ui_StartMenu.h"

#include "SettingPanel.h"

#include "GetConfig.h"
#include <QProcess>
#include "dpi.h"

StartMenu::StartMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartMenu)
{
    ui->setupUi(this);

    {
        Qt::WindowFlags WinFlags = Qt::Popup;
        setWindowFlags(WinFlags);
    }

    {
        auto config = GetConfig();
        auto ScreenList = GetScreenList();
        auto geo = ScreenList[0]->geometry();
        auto width = geo.width();
        auto height = geo.height();
        int BackgroundHeight, TaskBarHeight;
        int StartMenuHeight = config->StartMenuHeight;
        GetTowPartsScale(height, config->TaskBarHeight, TaskBarHeight, BackgroundHeight);
        move(0, BackgroundHeight-StartMenuHeight);
        resize(width, StartMenuHeight);
    }

}

StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::on_pushButton_clicked()
{
    hide();
    QProcess proc;
    proc.startDetached("qterminal");
}


void StartMenu::on_pushButton_6_clicked()
{
    auto sp = new SettingPanel();
    sp->show();
}

