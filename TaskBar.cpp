#include "TaskBar.h"
#include "ui_TaskBar.h"
#include "dpi.h"

TaskBar::TaskBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskBar)
{
    ui->setupUi(this);

    {
        Qt::WindowFlags WinFlags = Qt::FramelessWindowHint;
        WinFlags |= Qt::WindowDoesNotAcceptFocus;
        WinFlags |= Qt::WindowStaysOnTopHint;
        WinFlags |= Qt::Tool;
        setWindowFlags(WinFlags);
        setAttribute(Qt::WA_AlwaysShowToolTips);
        setAttribute(Qt::WA_AcceptDrops);
    }

    {
        auto config = GetConfig();
        auto ScreenList = GetScreenList();
        auto geo = ScreenList[0]->geometry();
        auto width = geo.width();
        auto height = geo.height();
        int BackgroundHeight, TaskBarHeight;
        GetTowPartsScale(height, config->TaskBarHeight, TaskBarHeight, BackgroundHeight);
        move(0, BackgroundHeight);
        resize(width, TaskBarHeight);
    }
}

TaskBar::~TaskBar()
{
    delete ui;
}

void TaskBar::on_pushButton_clicked()
{
    OpenStartMenu();
}

