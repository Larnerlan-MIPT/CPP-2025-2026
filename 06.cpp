#include <thread>
#include <vector>

template <typename F, typename... Args>
void iterate(int n, F f, Args&&... args)
{
    std::vector<std::thread> a;
    for (int i = 0; i < n; ++i)
    {
        a.emplace_back([=]()
        {
            f(args...);
        });
    }
    for (auto& t : a) t.join();
}