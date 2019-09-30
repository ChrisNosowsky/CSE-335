#ifndef CHRISLABEL_H
#define CHRISLABEL_H
#include <QObject>
#include <QLabel>
#include <QFont>
#include <QMessageBox>
#include <QComboBox>

class ChrisLabel: public QLabel {
    Q_OBJECT
public:
    ChrisLabel(QWidget* qw):QLabel(qw){};
};

#endif // CHRISLABEL_H
