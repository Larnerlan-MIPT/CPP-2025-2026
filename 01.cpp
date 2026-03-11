#include <iostream>
#include <cmath>

struct Vector2f
{
    float x, y;
};

Vector2f operator+(Vector2f left, Vector2f right) { return {left.x + right.x, left.y + right.y}; }
Vector2f operator*(Vector2f left, float right) { return {left.x * right, left.y * right}; }
Vector2f operator*(float left, Vector2f right) { return {left * right.x, left * right.y}; }
Vector2f& operator+=(Vector2f& left, Vector2f right) { left.x += right.x; left.y += right.y; return left; }

float getDistance(Vector2f a, Vector2f b) { return std::sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); }
std::ostream& operator<<(std::ostream& out, Vector2f right) { out << "(" << right.x << ", " << right.y << ")"; return out; }

class Shape
{
protected:
    Vector2f mPosition;
public:
    Shape() : mPosition({0,0}) {}
    Vector2f getPosition() { return mPosition; }
    void setPosition(Vector2f newPosition) { mPosition = newPosition; }
    void move(Vector2f change) { mPosition = mPosition + change; }
    virtual float calculatePerimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape
{
private:
    float mRadius;
public:
    Circle(float radius) : mRadius(radius) {}
    float calculatePerimeter() override { return 2 * std::numbers::pi * mRadius; }
};

class Rectangle : public Shape
{
private:
    float mWidth, mHeight;
public:
    Rectangle(float width, float height) : mWidth(width), mHeight(height) {}
    float calculatePerimeter() override { return 2 * (mWidth + mHeight); }
};

class Triangle : public Shape
{
private:
    Vector2f mPointA, mPointB, mPointC;
public:
    Triangle(Vector2f pointA, Vector2f pointB, Vector2f pointC)
        : mPointA(pointA), mPointB(pointB), mPointC(pointC) {}
    float calculatePerimeter() override
    {
        return getDistance(mPointA, mPointB) + getDistance(mPointB, mPointC) + getDistance(mPointC, mPointA);
    }
};

int main()
{
    Circle a(10);
    std::cout << a.calculatePerimeter() << std::endl;
    a.move({5,5});
    std::cout << a.getPosition() << std::endl;

    Rectangle b(100, 200);
    std::cout << b.calculatePerimeter() << std::endl;
    b.move({10,-10});
    std::cout << b.getPosition() << std::endl;

    Triangle c({5, 2}, {-7, 5}, {4, 4});
    std::cout << c.calculatePerimeter() << std::endl;
    c.move({20,20});
    std::cout << c.getPosition() << std::endl;

    return 0;
}