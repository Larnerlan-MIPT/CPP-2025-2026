#include <iostream>
#include <exception>

class BadOptionalAccess : public std::exception {
public:
    const char* what() const noexcept override {
        return "Bad optional access";
    }
};

template<typename T>
class Optional {
private:
    alignas(T) unsigned char data[sizeof(T)];
    bool has_value_flag;
    
public:
    Optional() : has_value_flag(false) {}
    
    Optional(const T& value) : has_value_flag(true) {
        new (data) T(value);
    }
    
    Optional(const Optional& other) : has_value_flag(other.has_value_flag) {
        if (other.has_value_flag) {
            new (data) T(*other);
        }
    }
    
    template<typename U>
    Optional(const Optional<U>& other) : has_value_flag(other.has_value()) {
        if (other.has_value()) {
            new (data) T(other.value());
        }
    }
    
    ~Optional() {
        reset();
    }
    
    Optional& operator=(const Optional& other) {
        if (this != &other) {
            reset();
            has_value_flag = other.has_value_flag;
            if (other.has_value_flag) {
                new (data) T(*other);
            }
        }
        return *this;
    }
    
    template<typename U>
    Optional& operator=(const Optional<U>& other) {
        reset();
        has_value_flag = other.has_value();
        if (other.has_value()) {
            new (data) T(other.value());
        }
        return *this;
    }
    
    bool has_value() const {
        return has_value_flag;
    }
    
    T& operator*() {
        return *reinterpret_cast<T*>(data);
    }
    
    const T& operator*() const {
        return *reinterpret_cast<const T*>(data);
    }
    
    T& value() {
        if (!has_value_flag) {
            throw BadOptionalAccess();
        }
        return *reinterpret_cast<T*>(data);
    }
    
    const T& value() const {
        if (!has_value_flag) {
            throw BadOptionalAccess();
        }
        return *reinterpret_cast<const T*>(data);
    }
    
    explicit operator bool() const {
        return has_value_flag;
    }
    
    void reset() {
        if (has_value_flag) {
            reinterpret_cast<T*>(data)->~T();
            has_value_flag = false;
        }
    }
    
    T value_or(const T& default_value) const {
        if (has_value_flag) {
            return *reinterpret_cast<const T*>(data);
        }
        return default_value;
    }
};