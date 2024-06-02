#ifndef DPI_H
#define DPI_H

#include <QScreen>

#include "GetConfig.h"
#include "Background.h"
#include "StartMenu.h"
#include "TaskBar.h"

class TestWM
{
    TestDesktopConfig* cf;

    QApplication* a;
    Background* bg;
    StartMenu* sm;
    TaskBar* tb;

    friend const TestDesktopConfig* GetConfig();
    friend void SetupEverything(int argc, char* argv[]);
    friend int ExecWMMainLoop();
    friend void OpenStartMenu();
};

extern void SetupEverything(int argc, char* argv[]);
extern int ExecWMMainLoop();
extern void OpenStartMenu();

extern QList<QScreen*> GetScreenList();
extern void GetTowPartsScale(int SumScale, int x, int& FirstScale, int& SecondScale);

#endif // DPI_H
