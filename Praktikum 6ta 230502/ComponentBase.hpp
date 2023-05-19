#ifndef __COMPONENTBASE_H__
#define __COMPONENTBASE_H__

class ComponentBase {

private:

    float x, y;

public:

    ComponentBase() = default;
    ComponentBase(const float, const float);
    virtual ~ComponentBase() = default;

    void move(const float, const float);

    virtual void showDialog() = 0;
    virtual ComponentBase* copy() const = 0;

};

ComponentBase::ComponentBase(const float x, const float y) : x(x), y(y){}

void ComponentBase::move(const float dx, const float dy) {

    x = dx;
    y = dy;
    
}

#endif // __COMPONENTBASE_H__