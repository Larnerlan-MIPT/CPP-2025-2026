#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& a, char b)
{
    std::vector<std::string> c;
    std::size_t d = 0;
    std::size_t e = a.find(b);
    while (e != std::string::npos)
    {
        c.push_back(a.substr(d, e - d));
        d = e + 1;
        e = a.find(b, d);
    }
    c.push_back(a.substr(d));
    return c;
}

int main()
{
    std::string data = "apple,banana,cherry,durian";
    char delimiter = ',';
    std::vector<std::string> parts = split(data, delimiter);
    for (std::size_t i = 0; i < parts.size(); ++i)
    std::cout << parts.at(i) << std::endl;
    return 0;
}