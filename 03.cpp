#include <cstdint>
#include <vector>
#include <thread>
#include <algorithm>
#include <limits>

uint64_t getMax(const std::vector<uint64_t>& v)
{
    if (v.empty()) return 0;
    return *std::max_element(v.begin(), v.end());
}

uint64_t getMax(int n, const std::vector<uint64_t>& v)
{
    if (v.empty()) return 0;
    n = std::max(1, std::min(n, static_cast<int>(v.size())));
    std::vector<std::thread> a(n);
    std::vector<uint64_t> b(n, 0);
    size_t c = v.size() / n;
    for (int i = 0; i < n; ++i)
    {
        size_t d = i * c;
        size_t e = (i == n-1) ? v.size() : d + c;
        a[i] = std::thread([d, e, &v, &b, i]()
        {
            uint64_t mx = std::numeric_limits<uint64_t>::min();
            for (size_t j = d; j < e; ++j)
                if (v[j] > mx) mx = v[j];
            b[i] = mx;
        });
    }
    for (auto& t : a) t.join();
    return *std::max_element(b.begin(), b.end());
}