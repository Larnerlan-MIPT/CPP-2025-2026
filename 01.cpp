#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <cctype>

std::string sharedString;
bool done = false;

void readerThread()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        if (line.empty()) continue;
        while (!sharedString.empty())
            std::this_thread::yield();
        sharedString = line;
        while (!sharedString.empty())
            std::this_thread::yield();
    }
    done = true;
}

void processorThread()
{
    while (!done || !sharedString.empty())
    {
        if (sharedString.empty())
        {
            std::this_thread::yield();
            continue;
        }
        std::string local = sharedString;
        for (char& c : local)
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        std::cout << local << std::endl;
        sharedString.clear();
    }
}

int main()
{
    std::thread t1(readerThread);
    std::thread t2(processorThread);
    t1.join();
    t2.join();
}