#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::size_t>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
    std::cout << v[i] << " ";
    std::cout << std::endl;
}

std::vector<std::size_t> substringIndexes(const std::string& a, const std::string& b)
{
    std::vector<std::size_t> c;
    if (b.empty()) return c;
    std::size_t d = 0;
    while ((d = a.find(b, d)) != std::string::npos)
    {
        c.push_back(d);
        d += b.length();
    }
    return c;
}

int main()
{
    std::vector<std::size_t> v1 = substringIndexes("cat and dog and cat", "cat");
    print(v1);
    std::vector<std::size_t> v2 = substringIndexes("look, cats were here", "cat");
    print(v2);
    std::vector<std::size_t> v3 = substringIndexes("cattattattattatat", "cat");
    print(v3);
    std::vector<std::size_t> v4 = substringIndexes("dog mouse elephant", "cat");
    print(v4);
    return 0;
}