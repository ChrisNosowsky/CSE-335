#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSlider>
#include "mydialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *resetButton = new QPushButton("Reset");
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setValue(0);
    slider->setRange(0, 99);
    connect(resetButton, SIGNAL(clicked() ), this, SLOT(SetSliderValue() ) );
    connect( slider, SIGNAL((slider->valueChanged())), this, SLOT(setValue(double)) );
}

MainWindow::~MainWindow()
{
    delete ui;
    delete meD;
}

void MainWindow::on_openButton_clicked()
{
    meD = new myDialog(this);
    meD->show();
}
