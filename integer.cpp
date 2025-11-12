#include "integer.hpp"

Integer::Integer() {
    digits.push_back(0);
}

Integer::Integer(int a) {
    if (a == 0) {
        digits.push_back(0);
        return;
    }
    
    while (a > 0) {
        digits.push_back(a % base);
        a /= base;
    }
}

Integer::Integer(const Integer& n) : digits(n.digits) {}

Integer::Integer(const std::string& str) {
    if (str.empty()) {
        digits.push_back(0);
        return;
    }

    std::string s = str;
    while (!s.empty()) {
        int len = s.length();
        int take = (len > 2) ? 2 : len;
        std::string segment = s.substr(len - take, take);
        digits.push_back(std::stoi(segment));
        s = s.substr(0, len - take);
    }
}

Integer& Integer::operator=(const Integer& n) {
    digits = n.digits;
    return *this;
}

Integer& Integer::operator+=(const Integer& n) {
    int carry = 0;
    size_t max_size = std::max(digits.size(), n.digits.size());
    
    for (size_t i = 0; i < max_size || carry; ++i) {
        if (i == digits.size()) {
            digits.push_back(0);
        }
        
        int sum = digits[i] + carry;
        if (i < n.digits.size()) {
            sum += n.digits[i];
        }
        
        digits[i] = sum % base;
        carry = sum / base;
    }
    
    return *this;
}

Integer Integer::operator+(const Integer& n) const {
    Integer result = *this;
    result += n;
    return result;
}

bool Integer::isEven() const {
    return (digits[0] % 2) == 0;
}

Integer Integer::operator*(const Integer& n) const {
    Integer result;
    result.digits.resize(digits.size() + n.digits.size(), 0);
    
    for (size_t i = 0; i < digits.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < n.digits.size() || carry; ++j) {
            long long product = result.digits[i + j] + 
                               digits[i] * (j < n.digits.size() ? n.digits[j] : 0) + 
                               carry;
            result.digits[i + j] = product % base;
            carry = product / base;
        }
    }
    
    while (result.digits.size() > 1 && result.digits.back() == 0) {
        result.digits.pop_back();
    }
    
    return result;
}

std::ostream& operator<<(std::ostream& stream, const Integer& num) {
    stream << num.digits.back();
    for (int i = num.digits.size() - 2; i >= 0; --i) {
        stream << std::setfill('0') << std::setw(2) << num.digits[i];
    }
    return stream;
}