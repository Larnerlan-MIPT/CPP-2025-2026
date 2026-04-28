#include <mutex>
#include <memory>
#include <optional>

template <typename T>
class ThreadSafeListQueue
{
    struct Node
    {
        T data;
        std::unique_ptr<Node> next;
        Node(T val) : data(std::move(val)), next(nullptr) {}
    };

    std::unique_ptr<Node> head;
    Node* tail = nullptr;
    mutable std::mutex mtx;
    std::condition_variable cv;

public:
    void push(T value)
    {
        auto newNode = std::make_unique<Node>(std::move(value));
        Node* newTail = newNode.get();
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (tail)
                tail->next = std::move(newNode);
            else
                head = std::move(newNode);
            tail = newTail;
        }
        cv.notify_one();
    }

    std::optional<T> pop()
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]{ return head != nullptr; });
        T item = std::move(head->data);
        head = std::move(head->next);
        if (!head)
            tail = nullptr;
        return item;
    }

    bool try_pop(T& item)
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (!head) return false;
        item = std::move(head->data);
        head = std::move(head->next);
        if (!head)
            tail = nullptr;
        return true;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> lock(mtx);
        return head == nullptr;
    }
};