
#include <iostream>
#include <set>
#include <vector>

int main() {
    int a, b;
    std::cin >> a >> b;
    
    std::set<int> c;
    c.insert(0);
    c.insert(a);
    
    std::multiset<int> d;
    d.insert(a);
    
    std::vector<int> e(b);
    for (int f = 0; f < b; ++f) {
        std::cin >> e[f];
    }
    
    for (int f = 0; f < b; ++f) {
        int g = e[f];
        auto h = c.lower_bound(g);
        int i = *h;
        int j = *(--h);
        
        d.erase(d.find(i - j));
        c.insert(g);
        d.insert(g - j);
        d.insert(i - g);
        
        std::cout << *d.rbegin() << " ";
    }
    
    return 0;
}