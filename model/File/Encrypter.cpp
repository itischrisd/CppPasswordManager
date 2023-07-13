#include <numeric>
#include <algorithm>
#include "Encrypter.h"

auto encryptData(std::deque<std::string> &data, std::string password) -> void {
    simpleHash(password);
    encrypt(data.front(), "MasterTimestampPWD");
    std::ranges::transform(data.begin() + 1, data.end(), data.begin() + 1,
                           [password](auto elem) { return encrypt(elem, password); });
}

auto decryptData(std::deque<std::string> &data, std::string password) -> void {
    simpleHash(password);
    decrypt(data.front(), "MasterTimestampPWD");
    std::ranges::transform(data.begin() + 1, data.end(), data.begin() + 1,
                           [password](auto elem) { return decrypt(elem, password); });
}

auto simpleHash(std::string &password) -> void {
    password += std::to_string(password.length());
    password += std::to_string(std::accumulate(password.begin(), password.end(), 0));
    std::ranges::reverse(password);
}

auto encrypt(std::string line, const std::string password) -> std::string {
    auto passchar = password.begin();
    auto transformer = [&passchar, &password](const auto c) {
        if (passchar == password.end()) passchar = password.begin();
        return c + *passchar++;
    };
    std::ranges::transform(line, line.begin(), transformer);
    return line;
}

auto decrypt(std::string line, const std::string password) -> std::string {
    auto passchar = password.begin();
    auto transformer = [&passchar, &password](const auto c) {
        if (passchar == password.end()) passchar = password.begin();
        return c - *passchar++;
    };
    std::ranges::transform(line, line.begin(), transformer);
    return line;
}
