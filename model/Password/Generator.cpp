#include "Generator.h"

#include "../Utils/Randomizer.h"

auto generatePassword(const int length, const std::vector<PasswordOption> &passwordOption) -> std::string {
    auto password = std::string();
    const auto lower = std::string("abcdefghijklmnopqrstuvwxyz");
    const auto upper = std::string("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    const auto numbers = std::string("0123456789");
    const auto special = std::string("!@#$%^&*()_+");

    for (int i = 0; i < length; i++) {
        switch (passwordOption[i % passwordOption.size()]) {
            case PasswordOption::LowerCase:
                password += lower[rnd::rand(static_cast<int>(lower.size() - 1))];
                break;
            case PasswordOption::UpperCase:
                password += upper[rnd::rand(static_cast<int>(upper.size() - 1))];
                break;
            case PasswordOption::Numbers:
                password += numbers[rnd::rand(static_cast<int>(numbers.size() - 1))];
                break;
            case PasswordOption::SpecialCharacters:
                password += special[rnd::rand(static_cast<int>(special.size() - 1))];
                break;
        }
    }

    return password;
}
