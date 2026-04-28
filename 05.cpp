#include <thread>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename RandIt, typename Comparator>
void parallelSort(int n, RandIt start, RandIt finish, Comparator comp)
{
    auto d = std::distance(start, finish);
    if (d <= 1) return;
    n = std::max(1, std::min(n, static_cast<int>(d)));
    size_t c = d / n;
    std::vector<std::thread> a(n);
    std::vector<RandIt> b(n + 1);
    b[0] = start;
    for (int i = 0; i < n; ++i)
        b[i+1] = (i == n-1) ? finish : b[i] + c;
    for (int i = 0; i < n; ++i)
    {
        a[i] = std::thread([&b, i, &comp]()
        {
            std::sort(b[i], b[i+1], comp);
        });
    }
    for (auto& t : a) t.join();
    for (int s = 1; s < n; s *= 2)
    {
        for (int l = 0; l < n - s; l += 2 * s)
        {
            RandIt m = b[l + s];
            RandIt e = b[std::min(l + 2 * s, n)];
            std::inplace_merge(b[l], m, e, comp);
        }
    }
}