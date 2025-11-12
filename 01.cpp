#include <iostream>
#include <cmath>
#include "point.hpp"

class Circle
{
private:
    Point center;
    float radius;

public:
    Circle(const Point& center, float radius) : center(center), radius(radius) 
    {
        if(radius < 0) this->radius = 0;
    }

    Circle() : center(Point(0,0)), radius(1) {}

    Circle(const Circle& circle) : center(circle.center), radius(circle.radius) {}

    Point getCenter() const { return center; }
    float getRadius() const { return radius; }

    void setCenter(const Point& center) { this->center = center; }
    void setRadius(float radius) 
    { 
        if(radius < 0) 
            this->radius = 0;
        else 
            this->radius = radius;
    }

    float area() const 
    {
        return M_PI * radius * radius;
    }

    float distance(const Point& p) const 
    {
        float d = center.distance(p);
        return std::abs(d - radius);
    }

    bool isColliding(const Circle& c) const 
    {
        float d = center.distance(c.center);
        return d <= (radius + c.radius);
    }

    void move(const Point& p) 
    {
        center = center + p;
    }
};

int main()
{
    Point p = {7, -1};
    Point q = {-4, 2};
    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "p + q = " << p + q << std::endl;

    Circle a({4, 1}, 3);
    Circle b;

    std::cout << "Circle a: center: " << a.getCenter() << " radius: " << a.getRadius() << std::endl; 
    std::cout << "Circle b: center: " << b.getCenter() << " radius: " << b.getRadius() << std::endl;

    std::cout << "Area of a = " << a.area() << std::endl;
    std::cout << "Distance from point p to circle a = " << a.distance(p) << std::endl;

    std::cout << "Collisions:" << std::endl;
    if(a.isColliding(b))
        std::cout << "Yes, a is colliding b" << std::endl;
    else
        std::cout << "No, a isn't colliding b" << std::endl;

    std::cout << "Moving b by {1, 1}:" << std::endl;
    b.move({1, 1});
    if(a.isColliding(b))
        std::cout << "Yes, a is colliding b" << std::endl;
    else
        std::cout << "No, a isn't colliding b" << std::endl;
}