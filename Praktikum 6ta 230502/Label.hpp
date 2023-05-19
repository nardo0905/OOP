#ifndef __LABEL_H__
#define __LABEL_H__
#include "ComponentBase.hpp"
#include <cstring>
#include <iostream>

class Label : public ComponentBase {

private:

    char text[17];

public:

    Label();
    Label(const float x, const float y, const char* text);

    void showDialog();
    ComponentBase* clone() const;

};

Label::Label() {

    showDialog();
    
}

Label::Label(const float x, const float y, const char* text) : ComponentBase(x, y) {
    
    strncpy(this->text, text, 16);

}

void Label::showDialog() {

    std::cout << "Enter coordinates: ";
    int x, y;
    std::cin >> x >> y;
    move(x, y);

    std::cout << "Enter Label text: ";
    std::cin >> text;
    
}

ComponentBase* Label::clone() const {

    return new Label{*this};
    
}

#endif // __LABEL_H__