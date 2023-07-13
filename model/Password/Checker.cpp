#include <algorithm>
#include "Checker.h"

auto isStrong(const std::string password) -> bool {
    return isUpper(password) && isLower(password) && isNumber(password) && isSpecial(password) &&
           isLong(password);
}

auto isUpper(const std::string password) -> bool {
    return std::ranges::any_of(password, [](const char c) { return std::isupper(c); });
}

auto isLower(const std::string password) -> bool {
    return std::ranges::any_of(password, [](const char c) { return std::islower(c); });
}

auto isNumber(const std::string password) -> bool {
    return std::ranges::any_of(password, [](const char c) { return std::isdigit(c); });
}

auto isSpecial(const std::string password) -> bool {
    return std::ranges::any_of(password, [](const char c) { return !std::isalnum(c); });
}

auto isLong(const std::string password) -> bool {
    return password.length() >= 8;
}