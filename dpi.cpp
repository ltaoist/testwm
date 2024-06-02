#include "dpi.h"
#include <QObject>
#include <QApplication>
#include <QGuiApplication>
#include <QDebug>
#include <QProcess>
#include <QTimer>
#include <QDialog>

#include <KWindowSystem>
#include <NETWM>

TestWM* testWM;

void startXfwm4()
{

    if (auto x11NativeInterface = qGuiApp->nativeInterface<QNativeInterface::QX11Application>()) {
        if (!QString::fromUtf8(NETRootInfo(x11NativeInterface->connection(), NET::SupportingWMCheck).wmName()).isEmpty())
        {
            return;
        }
    }

    QProcess xfwm4Proc;
    xfwm4Proc.startDetached("xfwm4");

    QEventLoop waitLoop;
    auto checker = [&waitLoop] {
        if (auto x11NativeInterface = qGuiApp->nativeInterface<QNativeInterface::QX11Application>()) {
            if (!QString::fromUtf8(NETRootInfo(x11NativeInterface->connection(), NET::SupportingWMCheck).wmName()).isEmpty())
            {
                waitLoop.exit();
            }
        }
    };
    QTimer t;
    QObject a;
    QObject::connect(&t, &QTimer::timeout, checker);
    t.setSingleShot(false);
    t.start(50);
    QTimer::singleShot(30 * 1000, &waitLoop, &QEventLoop::quit);
    waitLoop.exec();
}


const TestDesktopConfig *GetConfig(){
    return testWM->cf;
}

void SetupEverything(int argc, char* argv[]){


    testWM = new TestWM;

    testWM->cf = new TestDesktopConfig;

    testWM->a = new QApplication(argc, argv);

    {
        QStringList args;
        QProcess setResolutionProc;
        args << QStringLiteral("-s") << QStringLiteral("1280x768");
        setResolutionProc.startDetached("xrandr", args);
        setResolutionProc.waitForFinished();
    }

    startXfwm4();

    testWM->bg = new Background;
    testWM->bg->show();

    testWM->tb = new TaskBar();
    testWM->tb->show();

    testWM->sm = NULL;

    return;
}

int ExecWMMainLoop(){
    return testWM->a->exec();
}

void OpenStartMenu(){
    if(testWM->sm == NULL){
        testWM->sm = new StartMenu();
    }
    testWM->sm->show();
}

QList<QScreen*> GetScreenList(){
    return QGuiApplication::screens();
}

void GetTowPartsScale(int SumScale, int x, int& FirstScale, int& SecondScale){
    FirstScale = x;
    SecondScale = SumScale - x;
}
