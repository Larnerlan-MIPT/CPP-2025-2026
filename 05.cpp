#include <iostream>
#include <string>
#include <stdexcept>

int sumFromString(const std::string& str) {
    if (str.empty() || str[0] != '[' || str.back() != ']') {
        throw std::invalid_argument("Invalid string format");
    }
    
    std::string content = str.substr(1, str.length() - 2);
    int sum = 0;
    size_t pos = 0;
    
    while (pos < content.length()) {
        size_t comma = content.find(',', pos);
        std::string numStr;
        
        if (comma == std::string::npos) {
            numStr = content.substr(pos);
            pos = content.length();
        } else {
            numStr = content.substr(pos, comma - pos);
            pos = comma + 1;
        }
        
        if (!numStr.empty()) {
            try {
                sum += std::stoi(numStr);
            } catch (const std::exception&) {
                throw std::invalid_argument("Invalid number");
            }
        }
    }
    
    return sum;
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    try {
        int result = sumFromString(input);
        std::cout << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}