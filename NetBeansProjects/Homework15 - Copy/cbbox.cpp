#include "cbbox.h"
#include <QFont>
#include <QComboBox>
#include <string>
#include "iostream"
using namespace std;

void CBBox::myCurrentFontSizeChanged(const QString&){
    emit iChanged(this);
}
