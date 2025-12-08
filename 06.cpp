#include <iostream>

template<typename T, int N>
class Modular {
private:
    T value;
    
    T mod(T x) const {
        x %= N;
        if (x < 0) x += N;
        return x;
    }

public:
    Modular(T val = 0) : value(mod(val)) {}
    
    Modular(const Modular& other) : value(other.value) {}
    
    Modular& operator=(const Modular& other) {
        value = other.value;
        return *this;
    }
    
    Modular operator+(const Modular& other) const {
        return Modular(value + other.value);
    }
    
    Modular operator+(T val) const {
        return Modular(value + val);
    }
    
    Modular operator-(const Modular& other) const {
        return Modular(value - other.value);
    }
    
    Modular operator-(T val) const {
        return Modular(value - val);
    }
    
    Modular operator*(const Modular& other) const {
        return Modular(value * other.value);
    }
    
    Modular operator*(T val) const {
        return Modular(value * val);
    }
    
    Modular operator-() const {
        return Modular(-value);
    }
    
    template<typename U, int M>
    Modular(const Modular<U, M>& other) : value(mod(other.getValue())) {}
    
    T getValue() const {
        return value;
    }
};

template<typename T, int N>
std::ostream& operator<<(std::ostream& os, const Modular<T, N>& m) {
    os << m.getValue();
    return os;
}

int main() {
    Modular<int, 7> a(10);
    std::cout << a << std::endl;
    a = (a + 8) * 4;
    std::cout << a << std::endl;

    Modular<int, 7> b(a);
    b = b + 2;
    a = a - b;
    std::cout << a << std::endl;

    Modular<short, 3> c(a);
    std::cout << c << std::endl;

    return 0;
}