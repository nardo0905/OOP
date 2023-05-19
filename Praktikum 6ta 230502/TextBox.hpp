#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__
#include "ComponentBase.hpp"
#include <string>
#include <iostream>

class TextBox : public ComponentBase {

private:

    std::string text;

public:

    TextBox();
    TextBox(const float, const float, std::string&);

    void showDialog();
    ComponentBase* clone() const;

};

TextBox::TextBox() {

    showDialog();
    
}

TextBox::TextBox(const float x, const float y, std::string& text) : ComponentBase(x, y), text(text){}

void TextBox::showDialog() {

    std::cout << "Enter text: ";
    std::cin >> text;
    
}

ComponentBase* TextBox::clone() const {

    return new TextBox{*this};
    
}

#endif // __TEXTBOX_H__