#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chrislabel.h"
#include <QtGui>
#include <QMessageBox>
#include <QRadioButton>
#include <QComboBox>
#include "iostream"
#include "radiobutton.h"
#include "horizontalslider.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("small");
    ui->comboBox->addItem("medium");
    ui->comboBox->addItem("big");
    ui->horizontalSlider->setRange(10,40);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),ui->lineEdit,SLOT(myEditingFinished(const QString&)));
    connect(ui->lineEdit,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->comboBox,SIGNAL(activated(QString)),ui->comboBox,SLOT(myCurrentFontSizeChanged(const QString&)));
    connect(ui->comboBox,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->radioButton_3,SIGNAL(clicked(bool)),ui->radioButton_3,SLOT(myStateChanged(bool)));
    connect(ui->radioButton_3,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->radioButton_2,SIGNAL(clicked(bool)),ui->radioButton_2,SLOT(myStateChanged(bool)));
    connect(ui->radioButton_2,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->radioButton,SIGNAL(clicked(bool)),ui->radioButton,SLOT(myStateChanged(bool)));
    connect(ui->radioButton,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(mySliderChanged(int)));
    connect(ui->horizontalSlider,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));
}


    void MainWindow::actByYourChange(QObject* senderObj){
        if(senderObj==ui->lineEdit){
            QFont font=ui->chrisLabel->font();
            QString sizeString = ui->lineEdit->text();
            //Modify the size of the font, keep other information of the font unchanged.
            if(sizeString == "small") {
                font.setPointSize(10);
                ui->horizontalSlider->setValue(10);
                ui->comboBox->setCurrentText("small");
            }
            else if (sizeString == "medium") {
                font.setPointSize(20);
                ui->horizontalSlider->setValue(20);
                ui->comboBox->setCurrentText("medium");
            }
            else if (sizeString == "big") {
                font.setPointSize(40);
                ui->horizontalSlider->setValue(40);
                ui->comboBox->setCurrentText("big");
            }
            //Use the modified font
            ui->chrisLabel->setFont(font);
        }
        else if(senderObj==ui->comboBox){
            QFont font=ui->chrisLabel->font();
            QString q = ui->comboBox->currentText();
            //Modify the size of the font, keep other information of the font unchanged.
            if(q == "small") {
                font.setPointSize(10);
                ui->horizontalSlider->setValue(10);
                ui->lineEdit->setText("small");
            }
            else if (q == "medium") {
                font.setPointSize(20);
                ui->horizontalSlider->setValue(20);
                ui->lineEdit->setText("medium");
            }
            else if (q == "big") {
                font.setPointSize(40);
                ui->horizontalSlider->setValue(40);
                ui->lineEdit->setText("big");
            }
            //Use the modified font
            ui->chrisLabel->setFont(font);
        }
        else if(senderObj==ui->radioButton){
            QFont font("Arial");
            font.setWeight(0); //Weight { Light, Normal, DemiBold, Bold, Black }
            ui->chrisLabel->setFont(font);
        }
        else if(senderObj==ui->radioButton_3){
            QFont font("Times New Roman");
            font.setWeight(0); //Weight { Light, Normal, DemiBold, Bold, Black }
            ui->chrisLabel->setFont(font);
        }
        else if(senderObj==ui->radioButton_2){
            QFont font("Comic Sans");
            font.setWeight(0); //Weight { Light, Normal, DemiBold, Bold, Black }
            ui->chrisLabel->setFont(font);
        }
        else if(senderObj==ui->horizontalSlider){
            //Get current font
            QFont font=ui->chrisLabel->font();
            int v = ui->horizontalSlider->value();
            font.setPointSize(v);
            QString text;
            //Use the modified font
            ui->chrisLabel->setFont(font);
        }
    }
MainWindow::~MainWindow()
{
    delete ui;
}
