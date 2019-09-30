#ifndef CBBOX_H
#define CBBOX_H


#include <QObject>
#include <QLabel>
#include <QFont>
#include <QMessageBox>
#include <QComboBox>
using namespace std;

class CBBox: public QComboBox {
    Q_OBJECT
public:
    CBBox(QWidget* qw):QComboBox(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void myCurrentFontSizeChanged(const QString&);
};
#endif // CBBOX_H
