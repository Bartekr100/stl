#include "vowel.hpp"
#include <algorithm>

void removeVowels(std::vector<std::string>& words) {
    auto is_vowel = [](char letter) {
        constexpr std::string_view vowels = "aeiouyAEIOUY";
        return vowels.find(letter) != vowels.npos;
    };

    std::for_each(begin(words), end(words),

                  [&is_vowel](auto& word) { word.erase(std::remove_if(begin(word), end(word), is_vowel), end(word)); });
}
