#include <thread>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename RandIt>
RandIt getMax(RandIt start, RandIt finish)
{
    if (start == finish) return finish;
    RandIt a = start;
    for (auto it = start; it != finish; ++it)
        if (*it > *a) a = it;
    return a;
}

template <typename RandIt>
RandIt getMax(int n, RandIt start, RandIt finish)
{
    if (start == finish) return finish;
    n = std::max(1, std::min(n, static_cast<int>(std::distance(start, finish))));
    std::vector<std::thread> a(n);
    std::vector<RandIt> b(n);
    auto len = std::distance(start, finish);
    size_t c = len / n;
    for (int i = 0; i < n; ++i)
    {
        RandIt d = start;
        std::advance(d, i * c);
        RandIt e = d;
        if (i == n-1) e = finish;
        else std::advance(e, c);
        b[i] = d;
        a[i] = std::thread([d, e, &b, i]()
        {
            RandIt f = d;
            for (auto it = d; it != e; ++it)
                if (*it > *f) f = it;
            b[i] = f;
        });
    }
    for (auto& t : a) t.join();
    RandIt g = b[0];
    for (int i = 1; i < n; ++i)
        if (*b[i] > *g) g = b[i];
    return g;
}