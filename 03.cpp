#include <iostream>
#include <set>

int main() {
    int a;
    std::cin >> a;
    
    std::multiset<int> b;
    for (int c = 0; c < a; ++c) {
        int d;
        std::cin >> d;
        b.insert(d);
    }
    
    for (int e : b) {
        std::cout << e << " ";
    }
    
    return 0;
}