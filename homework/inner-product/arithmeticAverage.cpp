#include "arithmeticAverage.hpp"
#include <cmath>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& numbersA, const std::vector<int>& numbersB) {
    double sum = std::transform_reduce(
        begin(numbersA), end(numbersA),
        begin(numbersB),
        0.0,
        std::plus<int>(),
        std::plus<int>());

    return sum / (numbersA.size() + numbersB.size());
}

double Distance(const std::vector<int>& numbersA, const std::vector<int>& numbersB) {
    double sumOfSquares = std::transform_reduce(
        begin(numbersA), end(numbersA),
        begin(numbersB),
        0.0,
        std::plus<int>(),
        [](const auto first, const auto second) { return (first - second) * (first - second); });

    return std::sqrt(sumOfSquares);
}