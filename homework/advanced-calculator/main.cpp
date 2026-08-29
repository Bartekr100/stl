#include <iostream>
#include "advancedCalculator.hpp"

int main() {
    std::string formula = "";
    double result = 0.0;
    ErrorCode status = ErrorCode::OK;
    while (true) {
        std::cout << "Enter formula to calculate: ";
        std::getline(std::cin, formula);

        if (formula == "q" || formula == "exit") {
            break;
        }

        switch (status) {
        case ErrorCode::OK:
            std::cout << "Result of " << formula << " equals: " << result << "\n";
            break;
        case ErrorCode::BadCharacter:
            std::cout << "ERROR: Entered wrong character." << "\n";
            break;
        case ErrorCode::BadFormat:
            std::cout << "ERROR: Wrong format of formula." << "\n";
            break;
        case ErrorCode::DivideBy0:
            std::cout << "ERROR: Can't divide by 0." << "\n";
            break;
        case ErrorCode::SqrtOfNegativeNumber:
            std::cout << "ERROR: Can't calculate sqrt root of negative number." << "\n";
            break;
        case ErrorCode::ModuleOfNonIntegerValue:
            std::cout << "ERROR: Can't calculate modulo with non integer values." << "\n";
            break;
        }
    }
}
