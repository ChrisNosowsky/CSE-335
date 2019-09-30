#include "buttons.h"
#include <QPushButton>
#include "qpushbutton.h"

void Buttons::myStateChanged(bool){
    emit iChanged(this);
}
