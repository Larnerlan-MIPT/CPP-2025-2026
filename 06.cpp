#include <vector>
#include <utility>

template <typename Container>
std::vector<std::pair<typename Container::value_type, typename Container::value_type>> make_pairs(const Container& c) {
    std::vector<std::pair<typename Container::value_type, typename Container::value_type>> result;
    auto it = c.begin();
    while (it != c.end()) {
        typename Container::value_type first = *it;
        ++it;
        typename Container::value_type second = (it != c.end()) ? *it : typename Container::value_type();
        result.push_back({first, second});
        if (it != c.end()) ++it;
    }
    return result;
}