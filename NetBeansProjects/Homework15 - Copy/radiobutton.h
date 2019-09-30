#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H
#include <QObject>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QMessageBox>
#include <QComboBox>
#include <QRadioButton>

class RadioButton: public QRadioButton {
    Q_OBJECT
public:
    RadioButton(const QString& qstring):QRadioButton(qstring){};
    RadioButton(QWidget* qw):QRadioButton(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void myStateChanged(bool);
};

#endif // RADIOBUTTON_H
