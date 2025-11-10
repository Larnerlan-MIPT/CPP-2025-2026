#include <iostream>
#include <string>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits = 0;
    for (char c : str)
    {
        if (isalpha(c))
            numLetters++;
        else if (isdigit(c))
            numDigits++;
    }
}

int main()
{
    std::string a = "Hello123";
    int b, c;
    countLetters(a, b, c);
    return 0;
}