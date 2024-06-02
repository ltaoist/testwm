#ifndef SETTINGPANEL_H
#define SETTINGPANEL_H

#include <QWidget>

namespace Ui {
class SettingPanel;
}

class SettingPanel : public QWidget
{
    Q_OBJECT

public:
    explicit SettingPanel(QWidget *parent = nullptr);
    ~SettingPanel();

private:
    Ui::SettingPanel *ui;
};

#endif // SETTINGPANEL_H
