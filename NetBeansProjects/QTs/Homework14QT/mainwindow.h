#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mydialog.h"
#include <QMainWindow>
#include <QSlider>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openButton_clicked();

    void on_deleteButton_clicked();
    void SetSliderValue() { slider->setValue(0); }

private:
    Ui::MainWindow *ui;
    myDialog *meD;
    QSlider  *slider;
};

#endif // MAINWINDOW_H
