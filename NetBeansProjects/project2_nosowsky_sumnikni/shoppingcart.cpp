#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include <QtGui>
#include <QTableWidget>
#include "buttons.h"
#include <QPushButton>
#include <QWidget>
#include <QCloseEvent>
#include "tablevisitor.h"

using namespace std;
#include <iostream>
ShoppingCart::ShoppingCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    ui->shoppingTable->verticalHeader()->hide();
    ui->shoppingTable->horizontalHeader()->setStretchLastSection(true);
    ui->shoppingTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->label->hide();
    ui->checkout->setEnabled(true);
    ui->checkout->setEnabled(true);


    connect(ui->checkout,SIGNAL(clicked(bool)),ui->checkout,SLOT(myStateChanged(bool)));
    connect(ui->checkout,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange2(QObject*)));
    connect(ui->delete_2,SIGNAL(clicked(bool)),ui->delete_2,SLOT(myStateChanged(bool)));
    connect(ui->delete_2,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange2(QObject*)));
}


void ShoppingCart::actByYourChange2(QObject* senderObj){
    if(senderObj == ui->checkout) {
        ui->checkout->setEnabled(false);
        ui->delete_2->setEnabled(false);
        ui->label->show();
        TableVisitor *tv = new TableVisitor();
        double result = tv->VisitTable(ui->shoppingTable);
        ui->label->setText("TOTAL: " + QString::number(result));
        ui->label->setStyleSheet("QLabel {color: red;}");
    }
    if(senderObj == ui->delete_2) {
        for(int x = ui->shoppingTable->rowCount()-1; x >= 0; x--) {
            if(ui->shoppingTable->item(x,0)->isSelected()) {
                ui->shoppingTable->removeRow(x);
            }
        }
    }
}

void ShoppingCart::displayToCart() {
    for(auto item : shopItems){
        auto inTable = ui->shoppingTable->findItems(item[0]->text(), Qt::MatchExactly);
        if (inTable.length() == 0){
            if (item.length() == 4) {
                ui->shoppingTable->insertRow(ui->shoppingTable->rowCount());
                ui->shoppingTable->setItem(ui->shoppingTable->rowCount()-1,0,item[0]);
                ui->shoppingTable->setItem(ui->shoppingTable->rowCount()-1,1,item[2]);
            }
            else {
                ui->shoppingTable->insertRow(ui->shoppingTable->rowCount());
                ui->shoppingTable->setItem(ui->shoppingTable->rowCount()-1,0,item[0]);
                ui->shoppingTable->setItem(ui->shoppingTable->rowCount()-1,1,item[1]);
            }
        }
    }
    shopItems.clear();
}

void ShoppingCart::closeEvent(QCloseEvent *event) {
    this->hide();
    emit exitClicked();
}
ShoppingCart::~ShoppingCart()
{
    delete ui;
}
