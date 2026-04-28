#include <cstdint>
#include <vector>
#include <future>
#include <limits>

uint64_t partMax(const std::vector<uint64_t>& v, size_t start, size_t end)
{
    uint64_t m = std::numeric_limits<uint64_t>::min();
    for (size_t i = start; i < end; ++i)
        if (v[i] > m) m = v[i];
    return m;
}

uint64_t getMax(int n, const std::vector<uint64_t>& v)
{
    if (v.empty()) return 0;
    size_t total = v.size();
    if (n <= 0) n = 1;
    if (static_cast<size_t>(n) > total) n = static_cast<int>(total);
    size_t chunk = total / n;
    std::vector<std::packaged_task<uint64_t()>> tasks;
    std::vector<std::future<uint64_t>> futures;
    for (int i = 0; i < n; ++i)
    {
        size_t s = i * chunk;
        size_t e = (i == n - 1) ? total : s + chunk;
        std::packaged_task<uint64_t()> task([&v, s, e](){ return partMax(v, s, e); });
        futures.push_back(task.get_future());
        tasks.emplace_back(std::move(task));
    }
    for (auto& t : tasks)
        std::thread(std::move(t)).detach();
    uint64_t globalMax = 0;
    for (auto& f : futures)
    {
        uint64_t m = f.get();
        if (m > globalMax) globalMax = m;
    }
    return globalMax;
}