#include <iostream>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;

void chain(int i, int n)
{
    std::cout << "Thread #" << i << " started.\n";
    std::this_thread::sleep_for(200ms);
    if (i < n)
    {
        std::thread t(chain, i+1, n);
        t.join();
    }
    std::this_thread::sleep_for(200ms);
    std::cout << "Thread #" << i << " finished.\n";
}

int main()
{
    int n;
    std::cin >> n;
    if (n >= 1)
    {
        std::thread t(chain, 1, n);
        t.join();
    }
}