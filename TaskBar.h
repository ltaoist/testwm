#ifndef TASKBAR_H
#define TASKBAR_H

#include <QWidget>

namespace Ui {
class TaskBar;
}

class TaskBar : public QWidget
{
    Q_OBJECT

public:
    explicit TaskBar(QWidget *parent = nullptr);
    ~TaskBar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TaskBar *ui;
};

#endif // TASKBAR_H
