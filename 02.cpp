#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional>

template <typename T>
class ThreadSafeQueue
{
    std::queue<T> q;
    mutable std::mutex mtx;
    std::condition_variable cv;
public:
    void push(T value)
    {
        std::lock_guard<std::mutex> lock(mtx);
        q.push(std::move(value));
        cv.notify_one();
    }

    std::optional<T> pop()
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]{ return !q.empty(); });
        T item = std::move(q.front());
        q.pop();
        return item;
    }

    bool try_pop(T& item)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (q.empty()) return false;
        item = std::move(q.front());
        q.pop();
        return true;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(mtx);
        return q.empty();
    }
};