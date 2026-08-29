#pragma once
#include <stdint.h>
#include <string>

enum class ErrorCode : uint8_t {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

ErrorCode process(std::string input, double* out);