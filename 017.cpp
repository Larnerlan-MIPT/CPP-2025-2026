#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::vector<std::size_t>> calculate_word_lengths(const std::string& filename)
{
    std::vector<std::vector<std::size_t>> a;
    std::ifstream b(filename);
    std::string c;
    while (std::getline(b, c))
    {
        std::vector<std::size_t> d;
        std::istringstream e(c);
        std::string f;
        while (e >> f)
            d.push_back(f.length());
        a.push_back(d);
    }
    return a;
}

int main()
{
    return 0;
}