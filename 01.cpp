#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::string sharedString;
std::mutex mtx;
std::condition_variable cv;
bool ready = false;
bool finished = false;

void reader()
{
    std::ifstream file("invisible_man.txt");
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        {
            std::unique_lock<std::mutex> lock(mtx);
            sharedString = line;
            ready = true;
        }
        cv.notify_one();
        {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, []{ return !ready; });
        }
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        finished = true;
    }
    cv.notify_one();
}

void processor()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return ready || finished; });
        if (finished && !ready) break;
        std::string line = sharedString;
        ready = false;
        lock.unlock();
        cv.notify_one();

        for (char& c : line)
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        std::cout << line << std::endl;
    }
}

int main()
{
    std::thread t1(reader);
    std::thread t2(processor);
    t1.join();
    t2.join();
}