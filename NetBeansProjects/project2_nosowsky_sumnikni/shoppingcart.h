#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>
#include <QList>
#include <QTableWidgetItem>
#include "mainwindow.h"

namespace Ui {
class ShoppingCart;
}
class MainWindow;
class ShoppingCart : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();
    QList<QList<QTableWidgetItem*>> shopItems;
public slots:
    void actByYourChange2(QObject*);
    void displayToCart();
    void closeEvent(QCloseEvent*);
signals:
    void exitClicked();
private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
