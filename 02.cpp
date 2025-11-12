#include <iostream>

class Vector2f {
public:
    float x;
    float y;

    Vector2f(float x = 0, float y = 0) : x(x), y(y) {}
};

Vector2f operator+(const Vector2f& a, const Vector2f& b) {
    return Vector2f(a.x + b.x, a.y + b.y);
}

Vector2f operator-(const Vector2f& a, const Vector2f& b) {
    return Vector2f(a.x - b.x, a.y - b.y);
}

Vector2f operator*(const Vector2f& a, float b) {
    return Vector2f(a.x * b, a.y * b);
}

Vector2f operator*(float a, const Vector2f& b) {
    return Vector2f(a * b.x, a * b.y);
}

float operator*(const Vector2f& a, const Vector2f& b) {
    return a.x * b.x + a.y * b.y;
}

Vector2f operator+(const Vector2f& a) {
    return a;
}

Vector2f operator-(const Vector2f& a) {
    return Vector2f(-a.x, -a.y);
}

bool operator==(const Vector2f& a, const Vector2f& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vector2f& a, const Vector2f& b) {
    return !(a == b);
}

Vector2f& operator+=(Vector2f& a, const Vector2f& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

Vector2f& operator-=(Vector2f& a, const Vector2f& b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

Vector2f& operator*=(Vector2f& a, float b) {
    a.x *= b;
    a.y *= b;
    return a;
}

std::ostream& operator<<(std::ostream& out, const Vector2f& a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector2f& a) {
    in >> a.x >> a.y;
    return in;
}

int main() {
    Vector2f a = {1.0, 2.0};
    Vector2f b = {4.0, -1.0};
    std::cout << "a = " << a << std::endl << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "-a = " << -a << std::endl;
    std::cout << "Scalar product of a and b = " << a * b << std::endl;
    a *= 5;
    std::cout << "a after a *= 5;" << a << std::endl;
    a += b;
    std::cout << "a after a += b;" << a << std::endl;
}