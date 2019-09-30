#include "horizontalslider.h"
#include <QFont>
#include <QComboBox>
#include <string>
#include <QSlider>
#include "iostream"
using namespace std;

void HorizontalSlider::mySliderChanged(int){
    emit iChanged(this);
}
