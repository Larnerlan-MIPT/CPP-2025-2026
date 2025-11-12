#include "integer.hpp"

int main() {
    Integer a = 0;
    Integer b = 1;
    
    for (int i = 2; i <= 1000; ++i) {
        Integer c = a + b;
        a = b;
        b = c;
    }
    std::cout << b << std::endl;

    Integer fact = 1;
    for (int i = 2; i <= 1000; ++i) {
        fact = fact * Integer(i);
    }
    std::cout << fact << std::endl;
    
    return 0;
}