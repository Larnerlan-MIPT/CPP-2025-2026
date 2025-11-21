#include <iostream>
#include <vector>
#include <string>

int main() {
    int* a = new int(123);
    std::string* b = new std::string("Cats and Dogs");
    int* c = new int[5]{10, 20, 30, 40, 50};
    std::vector<int>* d = new std::vector<int>{10, 20, 30, 40, 50};
    std::string* e = new std::string[3]{"Cat", "Dog", "Mouse"};

    std::cout << *a << std::endl;
    std::cout << *b << std::endl;
    
    for(int i = 0; i < 5; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;
    
    for(int num : *d) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    for(int i = 0; i < 3; i++) {
        std::cout << e[i] << " ";
    }
    std::cout << std::endl;

    delete a;
    delete b;
    delete[] c;
    delete d;
    delete[] e;

    return 0;
}