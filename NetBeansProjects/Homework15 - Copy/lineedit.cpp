#include "lineedit.h"
#include <QObject>
#include <QLabel>
#include <QFont>
#include <QLineEdit>
#include <QMessageBox>
#include <QComboBox>


void LineEdit::myEditingFinished(const QString&){
    emit iChanged(this);
}

