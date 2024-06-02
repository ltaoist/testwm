#include "MonitorConfig.h"

#include <KScreen/Output>
#include <KScreen/Mode>
#include <KScreen/Config>
#include <KScreen/GetConfigOperation>
#include <KScreen/SetConfigOperation>
#include <KScreen/EDID>

MonitorConfig::MonitorConfig(QObject *parent)
    : QObject{parent}
{

}


void _SetResolution(KScreen::ConfigPtr config){
    const KScreen::OutputList outputs = config->outputs();
    int width, height;
    width = height = 0;
    for (const KScreen::OutputPtr &output : outputs) {
        if( !output->isConnected() )
            continue;
        QPoint pos = output->pos();
        if (output->currentMode()) {
            KScreen::ModePtr mode(output->currentMode());
            width = qMax(pos.x() + mode->size().width(), width);
            height = qMax(pos.y() + mode->size().height(), height);
        }
    }
    if (width != 0 && height != 0)
        config->screen()->setCurrentSize(QSize(width, height));
    //
    if (config && KScreen::Config::canBeApplied(config)) {
            KScreen::SetConfigOperation(config).exec();
        }
}

void MonitorConfig::SetResolution(){
    KScreen::GetConfigOperation *operation = new KScreen::GetConfigOperation();

    /*
    try{
        QObject::connect(operation, &KScreen::GetConfigOperation::finished, [this, operation] (KScreen::ConfigOperation *op) {
            KScreen::GetConfigOperation *configOp = qobject_cast<KScreen::GetConfigOperation *>(op);
            qDebug() << "Connecting to KScreen...";
            if (configOp && configOp->config() && configOp->config()->screen()) {
                _SetResolution(configOp->config());
                operation->deleteLater();
            }
        });
    } catch (...) {

    }
    */
}
