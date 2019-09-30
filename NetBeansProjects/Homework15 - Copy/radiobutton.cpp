#include "radiobutton.h"

void RadioButton::myStateChanged(bool){
    emit iChanged(this);
}
