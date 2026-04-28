#include <atomic>
#include <memory>
#include <optional>

template <typename T>
class LockFreeQueue {
    struct Node {
        T data;
        std::atomic<Node*> next;
        Node() : next(nullptr) {}
        Node(const T& val) : data(val), next(nullptr) {}
    };

    std::atomic<Node*> head_;
    std::atomic<Node*> tail_;
    std::atomic<Node*> retired_;

    void retire(Node* node) {
        node->next = retired_.load();
        while (!retired_.compare_exchange_weak(node->next, node));
    }

    void cleanup_all() {
        Node* node = retired_.exchange(nullptr);
        while (node) {
            Node* next = node->next.load();
            delete node;
            node = next;
        }
    }

public:
    LockFreeQueue() {
        Node* dummy = new Node();
        head_ = dummy;
        tail_ = dummy;
        retired_ = nullptr;
    }

    ~LockFreeQueue() {
        cleanup_all();
        Node* node = head_.load();
        while (node) {
            Node* next = node->next.load();
            delete node;
            node = next;
        }
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        while (true) {
            Node* last = tail_.load();
            Node* next = last->next.load();
            if (last == tail_.load()) {
                if (next == nullptr) {
                    if (last->next.compare_exchange_weak(next, newNode)) {
                        tail_.compare_exchange_strong(last, newNode);
                        return;
                    }
                } else {
                    tail_.compare_exchange_strong(last, next);
                }
            }
        }
    }

    std::optional<T> pop() {
        while (true) {
            Node* first = head_.load();
            Node* last = tail_.load();
            Node* next = first->next.load();
            if (first == head_.load()) {
                if (first == last) {
                    if (next == nullptr)
                        return std::nullopt;
                    tail_.compare_exchange_strong(last, next);
                } else {
                    T value = next->data;
                    if (head_.compare_exchange_weak(first, next)) {
                        retire(first);
                        return value;
                    }
                }
            }
        }
    }

    void finalize() {
        cleanup_all();
    }
};