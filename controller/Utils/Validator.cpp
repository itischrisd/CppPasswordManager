#include <algorithm>
#include <filesystem>
#include "Validator.h"

auto isFromRange(const std::vector<int> input, const int max) -> bool {
    return std::ranges::all_of(input, [&max](auto elem) { return elem <= max; });
}

auto isFromRange(const int input, const int max) -> bool {
    return input <= max && input > 0;
}

auto isSingleNumber(const std::string input) -> bool {
    return std::ranges::all_of(input, ::isdigit);
}

auto isMultiNumber(const std::string input) -> bool {
    return input.find_first_not_of("0123456789 ") == std::string::npos;
}

auto isNotEmpty(const std::string input) -> bool {
    return not input.empty();
}

auto isValidFile(const std::string input) -> bool {
    return input.ends_with(".txt") && std::filesystem::exists(input);
}