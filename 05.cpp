#include <iostream>
#include <string>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& a)
{
    return a.price > 1000;
}

int main()
{
    Book a = {"Book1", 300, 1500};
    bool b = isExpensive(a);
    return 0;
}