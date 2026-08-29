#include "advancedCalculator.hpp"
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>


auto plus = [](const double first, const double second) { return first + second; };
auto minus = [](const double first, const double second) { return first - second; };
auto divide = [](const double first, const double second) { return first / second; };
auto multiply = [](const double first, const double second) { return first * second; };
auto modulo = [](const double first, const double second) { return static_cast<int>(first) % static_cast<int>(second); };
auto factorial = [](const double first, const double second) { return std::tgamma(first + 1); };
auto power = [](const double first, const double second) { return std::pow(first, second); };
auto root = [](const double first, const double second) { return std::pow(first, 1.0 / second); };

std::unordered_map<char, std::function<double(double, double)>> operations =
    {{'+', plus}, {'-', minus}, {'/', divide}, {'*', multiply}, {'%', modulo}, {'^', power}, {'!', factorial}, {'$', root}};

double getNumber(std::string& input, ErrorCode& status) {
    size_t currentPosStart = 0;
    size_t currentPosStop = 0;
    std::string number = "";

    currentPosStart = input.find_first_of("+-0123456789.");
    if (currentPosStart == std::string::npos) {
        status = ErrorCode::BadFormat;
        return 0.0;
    }
    if (currentPosStart != currentPosStop) {
        std::string pre = input.substr(currentPosStop, currentPosStart);
        if (std::any_of(begin(pre), end(pre), [](const char el) { return el != ' '; })) {
            status = ErrorCode::BadFormat;
            return 0.0;
        }
    }

    if (input[currentPosStart] == '-') {
        number += input[currentPosStart];
        ++currentPosStart;
    } else if (input[currentPosStart] == '+') {
        number += input[currentPosStart];
        ++currentPosStart;
    }

    currentPosStop = input.find_first_not_of("0123456789.", currentPosStart);
    if (currentPosStop == std::string::npos) {
        return std::stod(input);
    }

    if (currentPosStop == currentPosStart) {
        status = ErrorCode::BadFormat;
        return 0.0;
    }
    number += input.substr(currentPosStart, currentPosStop - currentPosStart);
    if (std::count_if(begin(number), end(number), [](const char element) { return element == '.'; }) > 1) {
        status = ErrorCode::BadFormat;
        return 0.0;
    }

    if (input.length() > currentPosStop || currentPosStop != std::string::npos) {
        input = input.substr(currentPosStop);
    }
    return std::stod(number);
}

ErrorCode process(std::string input, double* out) {
    ErrorCode status = ErrorCode::OK;
    double firstNumber = 0.0;
    double secondNumber = 0.0;
    char sign = ' ';
    firstNumber = getNumber(input, status);
    if (status != ErrorCode::OK) {
        return status;
    }
    size_t currentPosStart = 0;
    size_t currentPosStop = 0;

    std::string signs = "+-/*%!^$";
    currentPosStart = input.find_first_of(signs);
    if (currentPosStart != currentPosStop) {
        std::string pre = input.substr(currentPosStop, currentPosStart);
        if (std::any_of(begin(pre), end(pre), [](const char el) { return el != ' '; })) {
            return ErrorCode::BadFormat;
        }
    }
    sign = input[currentPosStart];
    input = input.substr(currentPosStart + 1);

    secondNumber = getNumber(input, status);
    if (status != ErrorCode::OK) {
        return status;
    }
}