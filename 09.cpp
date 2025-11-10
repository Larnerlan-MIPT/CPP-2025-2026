#include <iostream>
#include <string>

std::string repeat(int n)
{
    std::string a;
    if (n < 0)
        return a;
    std::string b = std::to_string(n);
    for (int i = 0; i < n; i++)
        a += b;
    return a;
}

int main()
{
    std::cout << repeat(5) << std::endl;
    std::cout << repeat(10) << std::endl;
    std::cout << repeat(-1) << std::endl;
    return 0;
}