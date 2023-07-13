#include <iostream>
#include <unordered_map>
#include "Components.h"

auto displayTitle(const std::string title) -> void {
    std::cout << title << '\n';
}

auto displayPrompt(const std::string prompt) -> void {
    std::cout << prompt << "...\n";
}

auto displayError(const std::string error) -> void {
    std::cout << error << "!\n";
}

auto displayNumberedList(const std::vector<std::string> list) -> void {
    for (int i = 0; i < list.size(); i++) {
        std::cout << i + 1 << ". " << list[i] << ".\n";
    }
}

auto displayTable(const std::vector<std::vector<std::string>> &table) -> void {
    auto sizes = std::unordered_map<int, int>();
    for (const auto &row: table) {
        for (int j = 0; j < row.size(); j++) {
            if (row[j].size() > sizes[j]) {
                sizes[j] = (int) row[j].size();
            }
        }
    }
    for (int i = 0; i < table.size(); i++) {
        std::cout << i + 1 << ". ";
        for (int j = 0; j < table[i].size(); j++) {
            std::cout << table[i][j] << std::string(sizes[j] - table[i][j].size(), ' ') << '\t';
        }
        std::cout << '\n';
    }
}


auto getInput() -> std::string {
    std::string input;
    std::getline(std::cin, input);
    return input;
}