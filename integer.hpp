#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Integer {
private:
    static const int base = 100;
    std::vector<int> digits;

public:
    Integer();
    Integer(int a);
    Integer(const Integer& n);
    Integer(const std::string& str);
    
    Integer& operator=(const Integer& n);
    
    Integer& operator+=(const Integer& n);
    Integer operator+(const Integer& n) const;
    
    bool isEven() const;
    
    Integer operator*(const Integer& n) const;

    friend std::ostream& operator<<(std::ostream& stream, const Integer& num);
};