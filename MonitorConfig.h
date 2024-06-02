#ifndef MONITORCONFIG_H
#define MONITORCONFIG_H

#include <QObject>

class MonitorConfig : public QObject
{
    Q_OBJECT
public:
    explicit MonitorConfig(QObject *parent = nullptr);
    void SetResolution();

signals:

};

#endif // MONITORCONFIG_H
