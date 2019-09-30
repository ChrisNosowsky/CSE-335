#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <string>
#include <QString>
#include <QList>
#include <QTableWidgetItem>

using namespace std;

namespace Ui {
class MainWindow;
}
class ShoppingCart;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QList<QTableWidgetItem*>> addItems;
public slots:
    void actByYourChange(QObject*);
    void on_closeEvent_clicked();
private slots:
    void on_pushButton_3_clicked();
    void load(QString);
    void addToCart();
private:
    QList<QList<QString>> itemsList;
    Ui::MainWindow *ui;
    ShoppingCart *sc;
};

#endif // MAINWINDOW_H
