#include <iostream>
#include <string>
#include <vector>

std::string concatenate(const std::vector<std::string>& a)
{
    std::string b;
    for (const std::string& c : a)
        b += c;
    return b;
}

int main()
{
    std::vector<std::string> v {"Cat", "Dog", "Mouse", "Tiger", "Elk"};
    std::cout << concatenate(v) << std::endl;
    return 0;
}