#include "arithmeticAverage.hpp"
#include <execution>
#include <numeric>

double ArithmeticAverage(const std::vector<int>& numbersA, const std::vector<int>& numbersB) {
    double sum = std::transform_reduce(std::execution::unseq,
                                       begin(numbersA),
                                       end(numbersA),
                                       begin(numbersB),
                                       0,
                                       std::plus<int>(),
                                       std::plus<int>());

    return sum / (numbersA.size() + numbersB.size());
}