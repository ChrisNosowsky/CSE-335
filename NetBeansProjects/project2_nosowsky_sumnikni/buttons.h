#ifndef BUTTONS_H
#define BUTTONS_H
#include <QPushButton>
#include "qpushbutton.h"

using namespace std;

class Buttons: public QPushButton
{
   Q_OBJECT
public:
    Buttons(QWidget* qw):QPushButton(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void myStateChanged(bool);
};

#endif // BUTTONS_H
