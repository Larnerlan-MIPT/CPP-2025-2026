#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std::chrono_literals;

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::thread> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = std::thread([i]()
        {
            std::cout << "Thread #" << i+1 << " started.\n";
            std::this_thread::sleep_for((i+1) * 1s);
            std::cout << "Thread #" << i+1 << " finished.\n";
        });
    }
    for (auto& t : a) t.join();
}