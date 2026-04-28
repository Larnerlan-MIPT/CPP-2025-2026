#include <iostream>
#include <vector>
#include <typeinfo>

class Individual
{
public:
    virtual void speak() const = 0;
    virtual int id() const { return -1; }
    virtual ~Individual() = default;
};

class Alice : public Individual
{
public:
    void speak() const override { std::cout << "Hi, I am Alice" << std::endl; }
    int id() const override { return 0; }
};

class Bob : public Individual
{
public:
    void speak() const override { std::cout << "Hi, I am Bob" << std::endl; }
    int id() const override { return 1; }
};

class Casper : public Individual
{
public:
    void speak() const override { std::cout << "Hi, I am Casper" << std::endl; }
    int id() const override { return 2; }
};

// 1
std::vector<Individual*> createIndividuals()
{
    std::vector<Individual*> v;
    for (int i = 0; i < 3; ++i) v.push_back(new Alice);
    for (int i = 0; i < 2; ++i) v.push_back(new Bob);
    for (int i = 0; i < 4; ++i) v.push_back(new Casper);
    return v;
}

// 2
void letThemSpeak(const std::vector<Individual*>& v)
{
    for (auto p : v)
        p->speak();
}

// 3
void deleteIndividuals(std::vector<Individual*>& v)
{
    for (auto p : v)
        delete p;
    v.clear();
}

// 4a – виртуальный метод id() уже в классах
int identify1(Individual* p)
{
    return p->id();
}

// 4b – dynamic_cast
int identify2(Individual* p)
{
    if (dynamic_cast<Alice*>(p))  return 0;
    if (dynamic_cast<Bob*>(p))    return 1;
    if (dynamic_cast<Casper*>(p)) return 2;
    return -1;
}

// 4c – typeid
int identify3(Individual* p)
{
    if (typeid(*p) == typeid(Alice))  return 0;
    if (typeid(*p) == typeid(Bob))    return 1;
    if (typeid(*p) == typeid(Casper)) return 2;
    return -1;
}

int main()
{
    std::vector<Individual*> v = createIndividuals();
    letThemSpeak(v);

    Alice a; Bob b; Casper c;
    std::cout << identify1(&a) << " " << identify1(&b) << " " << identify1(&c) << std::endl;
    std::cout << identify2(&a) << " " << identify2(&b) << " " << identify2(&c) << std::endl;
    std::cout << identify3(&a) << " " << identify3(&b) << " " << identify3(&c) << std::endl;

    deleteIndividuals(v);
}