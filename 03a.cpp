#include <iostream>
#include <vector>

class Widget
{
public:
    virtual void draw() const = 0;
    virtual void handle() = 0;
    virtual ~Widget() = default;
};

class Button : public Widget
{
public:
    void draw() const override { std::cout << "Button\n"; }
    void handle() override {}
};

class Slider : public Widget
{
public:
    void draw() const override { std::cout << "Slider\n"; }
    void handle() override {}
};

class Draggable : public Widget
{
public:
    void draw() const override { std::cout << "Draggable\n"; }
    void handle() override {}
};

int main()
{
    std::vector<Widget*> w;
    w.push_back(new Button);
    w.push_back(new Slider);
    w.push_back(new Draggable);

    for (auto p : w)
    {
        p->draw();
        p->handle();
    }

    for (auto p : w)
        delete p;
}