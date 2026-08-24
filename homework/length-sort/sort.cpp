#include "sort.hpp"
#include <algorithm>

deque lengthSort(const forward_list& words) {
      deque sortedWords(begin(words), end(words));

    auto cmp = [](const std::string_view lhs, const std::string_view rhs) {
        return std::tuple(lhs.size(), lhs) < std::tuple(rhs.size(), rhs);
    };
    std::sort(begin(sortedWords), end(sortedWords), cmp);

    return sortedWords;
}