#include "SettingPanel.h"
#include "ui_SettingPanel.h"

SettingPanel::SettingPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingPanel)
{
    ui->setupUi(this);
}

SettingPanel::~SettingPanel()
{
    delete ui;
}
