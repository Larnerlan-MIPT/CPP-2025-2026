#include <iostream>
#include <map>

int main() {
    int a;
    std::cin >> a;
    
    std::map<int, int> b;
    for (int c = 0; c < a; ++c) {
        int d;
        std::cin >> d;
        b[d]++;
    }
    
    for (auto e = b.begin(); e != b.end(); ++e) {
        if (e != b.begin()) std::cout << " ";
        std::cout << e->first;
    }
    std::cout << std::endl;
    
    for (auto e = b.begin(); e != b.end(); ++e) {
        if (e != b.begin()) std::cout << " ";
        std::cout << e->second;
    }
    
    return 0;
}