#ifndef __RADIOBUTTON_H__
#define __RADIOBUTTON_H__
#include "ComponentBase.hpp"
#include <cstring>
#include <iostream>

class RadioButton : public ComponentBase {

private:

    char text[17];
    bool state; // on or off

public:

    RadioButton();
    RadioButton(const float, const float, const char*, const bool);

    void showDialog();
    ComponentBase* clone() const;

    void flip();
    bool isOn() const;

};

RadioButton::RadioButton() {

    showDialog();
    
}

RadioButton::RadioButton(const float x, const float y, const char* text, const bool state) : ComponentBase(x, y), state(state) {

    strncpy(this->text, text, 16);
    
}

void RadioButton::showDialog() {

    std::cout << "Enter RadioButton text: ";
    std::cin >> text;

    std::cout << "1 for on 0 for off: ";
    std::cin >> state;
    
}

ComponentBase* RadioButton::clone() const {

    return new RadioButton{*this};
    
}

void RadioButton::flip() {

    state = !state;
    
}

bool RadioButton::isOn() const {

    return state;
    
}

#endif // __RADIOBUTTON_H__