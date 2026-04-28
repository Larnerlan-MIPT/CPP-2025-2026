#include <atomic>
#include <memory>
#include <optional>
#include <array>

constexpr unsigned MAX_THREADS = 64;
constexpr unsigned HP_PER_THREAD = 2;

template <typename T>
class LockFreeQueueHP;

class HazardPointerManager {
    static std::atomic<void*> hp_[MAX_THREADS * HP_PER_THREAD];
public:
    static void*& hazard(unsigned thread_id, unsigned idx) {
        return hp_[thread_id * HP_PER_THREAD + idx];
    }

    template <typename T>
    friend class LockFreeQueueHP;
};
std::atomic<void*> HazardPointerManager::hp_[MAX_THREADS * HP_PER_THREAD] = {};

template <typename T>
class LockFreeQueueHP {
    struct Node {
        T data;
        std::atomic<Node*> next;
        Node() : next(nullptr) {}
        Node(const T& val) : data(val), next(nullptr) {}
    };

    std::atomic<Node*> head_;
    std::atomic<Node*> tail_;

    static Node* safe_read(std::atomic<Node*>& ptr, unsigned tid, unsigned hpIdx) {
        while (true) {
            Node* p = ptr.load();
            HazardPointerManager::hazard(tid, hpIdx) = p;
            if (p == ptr.load())
                return p;
        }
    }

public:
    LockFreeQueueHP() {
        Node* dummy = new Node();
        head_ = dummy;
        tail_ = dummy;
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        while (true) {
            Node* last = tail_.load();
            Node* next = last->next.load();
            if (last == tail_.load()) {
                if (next == nullptr) {
                    if (last->next.compare_exchange_weak(next, newNode)) {
                        tail_.compare_exchange_weak(last, newNode);
                        return;
                    }
                } else {
                    tail_.compare_exchange_weak(last, next);
                }
            }
        }
    }

    std::optional<T> pop(unsigned tid) {
        while (true) {
            Node* first = safe_read(head_, tid, 0);
            Node* last = tail_.load();
            Node* next = first->next.load();
            HazardPointerManager::hazard(tid, 1) = next;
            if (first != head_.load()) continue;
            if (first == last) {
                if (next == nullptr) {
                    HazardPointerManager::hazard(tid, 0) = nullptr;
                    HazardPointerManager::hazard(tid, 1) = nullptr;
                    return std::nullopt;
                }
                tail_.compare_exchange_weak(last, next);
            } else {
                T value = next->data;
                if (head_.compare_exchange_weak(first, next)) {
                    HazardPointerManager::hazard(tid, 0) = nullptr;
                    HazardPointerManager::hazard(tid, 1) = nullptr;
                    delete first;
                    return value;
                }
            }
        }
    }
};