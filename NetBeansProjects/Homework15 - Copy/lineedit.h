#ifndef LINEEDIT_H
#define LINEEDIT_H
#include <QObject>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QMessageBox>
#include <QComboBox>

class LineEdit: public QLineEdit {
    Q_OBJECT
public:
    LineEdit(const QString& qstring):QLineEdit(qstring){};
    LineEdit(QWidget* qw):QLineEdit(qw){};
signals:
    void iChanged(QObject*);
public slots:
    void myEditingFinished(const QString&);
};

#endif // LINEEDIT_H
