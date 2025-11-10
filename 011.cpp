#include <iostream>
#include <vector>

void print(const std::vector<int>& v)
{
    for (std::size_t i = 0; i < v.size(); ++i)
    std::cout << v[i] << " ";
    std::cout << std::endl;
}

void doubling(std::vector<int>& a)
{
    std::size_t b = a.size();
    for (std::size_t i = 0; i < b; i++)
        a.push_back(a[i]);
}

int main()
{
    std::vector<int> v {10, 20, 30};
    doubling(v);
    print(v);
    return 0;
}