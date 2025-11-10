#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
    std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::string> prefixes(const std::string& a)
{
    std::vector<std::string> b;
    for (std::size_t i = 1; i <= a.length(); i++)
        b.push_back(a.substr(0, i));
    return b;
}

int main()
{
    std::vector<std::string> v = prefixes("Mouse");
    print(v);
    return 0;
}