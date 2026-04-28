#include <iostream>
#include <vector>
#include <memory>

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
    std::vector<std::unique_ptr<Widget>> w;
    w.push_back(std::make_unique<Button>());
    w.push_back(std::make_unique<Slider>());
    w.push_back(std::make_unique<Draggable>());

    for (const auto& p : w)
    {
        p->draw();
        p->handle();
    }
}