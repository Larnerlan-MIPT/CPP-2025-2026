#include <cstdint>
#include <vector>
#include <future>
#include <algorithm>
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
    std::vector<std::future<uint64_t>> futures;
    for (int i = 0; i < n; ++i)
    {
        size_t s = i * chunk;
        size_t e = (i == n - 1) ? total : s + chunk;
        futures.push_back(std::async(std::launch::async, partMax, std::cref(v), s, e));
    }
    uint64_t globalMax = 0;
    for (auto& f : futures)
    {
        uint64_t m = f.get();
        if (m > globalMax) globalMax = m;
    }
    return globalMax;
}