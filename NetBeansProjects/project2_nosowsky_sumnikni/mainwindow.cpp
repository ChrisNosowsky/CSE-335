#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QTableWidget>
#include "iostream"
#include "shoppingcart.h"
#include "buttons.h"
#include <QDesktopWidget>
#include <QSize>
#include <QFile>
#include <QTextStream>
#include <QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sc = new ShoppingCart(this);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_3->setEnabled(false);
    ui->itemsTable->setColumnCount(4);
    ui->itemsTable->setHorizontalHeaderLabels(QStringList() << "Product Name" << "Type" << "Price" << "Special Attribute");
    ui->itemsTable->verticalHeader()->hide();
    ui->bundleTable->verticalHeader()->hide();
    ui->itemsTable->horizontalHeader()->setStretchLastSection(true);
    ui->bundleTable->horizontalHeader()->setStretchLastSection(true);
    ui->itemsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->bundleTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->pushButton,SIGNAL(clicked(bool)),ui->pushButton,SLOT(myStateChanged(bool)));
    connect(ui->pushButton,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(ui->pushButton_2,SIGNAL(clicked(bool)),ui->pushButton_2,SLOT(myStateChanged(bool)));
    connect(ui->pushButton_2,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    connect(sc,SIGNAL(exitClicked()),this,SLOT(on_closeEvent_clicked()));

}
 void MainWindow::actByYourChange(QObject* senderObj){
     if(senderObj == ui->pushButton) {
         ui->pushButton_2->setEnabled(true);
         ui->pushButton_3->setEnabled(true);
         ui->pushButton->setEnabled(false);
         QString p1 = "Technology.csv";
         QString p2 = "Bundles.csv";
         this->load(p1);
         this->load(p2);
     }
     if(senderObj == ui->pushButton_2) {
        this->addToCart();
     }
 }

 void MainWindow::on_pushButton_3_clicked()
 {
     if (ui->pushButton_3->text() == "Hide Cart") {
            ui->pushButton_3->setText("Show Cart");
            sc->hide();
     }
     else if (ui->pushButton_3->text() == "Show Cart") {
         QDesktopWidget *desktop = QApplication::desktop();
         int screenWidth;
         int screenHeight;
         int x, y;
         sc->show();
         QSize size = sc->sizeHint();
         screenWidth = desktop->width();
         screenHeight = desktop->height();
         int mw = size.width();
         int mh = size.height();
         x = (screenWidth/2) - (mw/2);
         y = (screenHeight/2) - (mh/2);
         sc->move(x+325, y-250);
         ui->pushButton_3->setText("Hide Cart");
         sc->shopItems = addItems;
         addItems.clear();
         sc->displayToCart();
     }
 }

 void MainWindow::on_closeEvent_clicked() {
     ui->pushButton_3->setText("Show Cart");
 }

 void MainWindow::load(QString s) { //this function loads up the file and formats it for BOTH tables.
     double price = 0.00;
     QString name = "C:/Users/Admin/Documents/build-Project2-Desktop_Qt_5_10_0_MinGW_32bit-Profile/" + s;
     QFile file(name);
     if ( !file.open(QIODevice::ReadOnly) ) {
         qDebug() << "File does not exist";
     } else {
         QTextStream in(&file);
         while (!in.atEnd()) {
             QString line = in.readLine();
             QList<QTableWidgetItem *> standardItemsList;
             QList<QString> items;

             for (QString item : line.split(",")) {
                 standardItemsList.append(new QTableWidgetItem(item));
                 items.append(item);
             }
             if (s == "Technology.csv") {
                 ui->itemsTable->insertRow(ui->itemsTable->rowCount());
                 for (int i=0; i<standardItemsList.length(); i++) {
                     if(i == 3 or i==2) {
                         continue;
                     }
                     else {
                         if (i == 0) {
                            ui->itemsTable->setItem(ui->itemsTable->rowCount()-1,1,standardItemsList[i]);
                         }
                         if(i == 1) {
                            ui->itemsTable->setItem(ui->itemsTable->rowCount()-1,0,standardItemsList[i]);
                         }
                         if(i > 3)
                            ui->itemsTable->setItem(ui->itemsTable->rowCount()-1,i-2,standardItemsList[i]);
                     }
                 }
                 itemsList.append(items);
             }
             else {
                 double discount = 0.00;
                 price = 0.00;
                 for(int i = 0; i < itemsList.length(); i++) {
                     for(int t = 0; t < items.length(); t++) {
                         if(itemsList[i][1] == items[t]) {
                             price += itemsList[i][4].toDouble();
                         }
                     }
                 }
                 discount = round(((price - items[1].toDouble())/price)*100);
                 standardItemsList[2] = new QTableWidgetItem(QString::fromStdString(to_string(int(discount)) + "%"));
                 ui->bundleTable->insertRow(ui->bundleTable->rowCount());
                 ui->bundleTable->setItem(ui->bundleTable->rowCount()-1,0,standardItemsList[0]);
                 ui->bundleTable->setItem(ui->bundleTable->rowCount()-1,1,standardItemsList[1]);
                 ui->bundleTable->setItem(ui->bundleTable->rowCount()-1,2,standardItemsList[2]);
             }
         }
         file.close();
        }
 }

 void MainWindow::addToCart() {
    QList<QTableWidgetItem*> list;
    for(QTableWidgetItem* item : ui->itemsTable->selectedItems()) {
        QString hey = item->text();
        list.append(new QTableWidgetItem(hey));
        if(list.length() == 4) {
            addItems.append(list);
            list.clear();
        }
    }
    for(QTableWidgetItem* item : ui->bundleTable->selectedItems()) {
        QString hey = item->text();
        list.append(new QTableWidgetItem(hey));
        if(list.length() == 3) {
            addItems.append(list);
            list.clear();
        }
    }
    if(sc->isVisible()) {
        sc->shopItems = addItems;
        addItems.clear();
        sc->displayToCart();
    }
 }
MainWindow::~MainWindow()
{
    delete ui;
    delete sc;
}



