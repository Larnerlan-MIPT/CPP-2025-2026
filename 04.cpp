#include <iostream>

int& getReferenceToMax(int& a, int& b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a = 10;
    int b = 20;

    getReferenceToMax(a, b) += 1;

    std::cout << a << " " << b << std::endl;
    return 0;
}