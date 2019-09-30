#ifndef HORIZONTALSLIDER_H
#define HORIZONTALSLIDER_H
#include <QObject>
#include <QLabel>
#include <QFont>
#include <QMessageBox>
#include <QComboBox>

class HorizontalSlider: public QSlider {
    Q_OBJECT
public:
    HorizontalSlider(QWidget* qw):QSlider(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void mySliderChanged(int);
};

#endif // HORIZONTALSLIDER_H
