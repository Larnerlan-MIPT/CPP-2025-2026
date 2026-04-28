#include <iostream>
#include <thread>
#include <string>
#include <cctype>
#include "ThreadSafeQueue.h"   // Подставьте реализацию из Задачи 2

ThreadSafeQueue<std::string> globalQueue;
bool finished = false;

void reader()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line.empty()) continue;
        globalQueue.push(std::move(line));
    }
    finished = true;
}

void processor()
{
    while (true)
    {
        auto item = globalQueue.pop();
        if (!item.has_value()) continue;
        std::string str = item.value();
        if (finished && str.empty()) break;
        for (char& c : str)
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        std::cout << str << std::endl;
    }
}

int main()
{
    std::thread t1(reader);
    std::thread t2(processor);
    t1.join();
    t2.join();
}