#include <algorithm>
#include <iostream>
#include "Sanitizer.h"

auto string_to_vec_int(std::string str) -> std::vector<int> {
    str.erase(str.begin(), std::ranges::find_if(str, [](const auto ch) { return !std::isspace(ch); }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](const auto ch) { return !std::isspace(ch); }).base(),
              str.end());
    std::cout << str << '\n';
    auto start = 0;
    auto end = str.find(' ');
    auto result = std::vector<int>();
    while (end != std::string::npos) {
        result.push_back(std::stoi(str.substr(start, end - start)));
        start = (int) end + 1;
        end = str.find(' ', start);
    }
    result.push_back(std::stoi(str.substr(start, end - start)));
    return result;
}

auto string_to_int(const std::string str) -> int {
    return std::stoi(str);
}