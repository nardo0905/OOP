#ifndef __COMPONENTCOLLECTION_H__
#define __COMPONENTCOLLECTION_H__
#include "Label.hpp"
#include "RadioButton.hpp"
#include "TextBox.hpp"
#include <vector>

class ComponentCollection {

private:

    std::vector<ComponentBase*> components;

    void copy(const ComponentCollection&);
    void deleteCollection();

public:

    ComponentCollection(){}
    ComponentCollection(const ComponentCollection&);
    ~ComponentCollection();
    ComponentCollection& operator=(const ComponentCollection&);

    void addLabel();
    void addRadioButton();
    void addTextBox();

};

void ComponentCollection::copy(const ComponentCollection& other) {

    for (ComponentBase* comp : other.components) {

        components.push_back(comp->clone());

    }
    
}

void ComponentCollection::deleteCollection() {

    for (ComponentBase* comp : this->components) {

        delete comp;

    }

}

ComponentCollection::ComponentCollection(const ComponentCollection& other) {

    copy(other);

}

ComponentCollection::~ComponentCollection() {

    deleteCollection();

}

ComponentCollection& operator=(const ComponentCollection& other) {

    if (this != &other) {

        deleteCollection();
        copy(other);

    }

    return *this;

}

void ComponentCollection::addLabel() {

    ComponentBase* temp = new Label{};
    components.push_back(temp);

}

void ComponentCollection::addRadioButton() {

    ComponentBase* temp = new RadioButton{};
    components.push_back(temp);

}

void ComponentCollection::addTextBox() {

    ComponentBase* temp = new TextBox{};
    components.push_back(temp);

}

#endif // __COMPONENTCOLLECTION_H__