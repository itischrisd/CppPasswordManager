#include <fstream>
#include <filesystem>
#include <iostream>
#include "ReaderWriter.h"
#include "Encrypter.h"
#include "../Utils/Timestamp.h"

auto readFile(const std::string& path_to_file) -> std::deque<std::string> {
    auto file = std::fstream(path_to_file, std::ios::in | std::ios::out);
    auto data = std::deque<std::string>{};
    auto timestamp = std::string();
    std::getline(file, timestamp);
    data.push_back(timestamp);
    file.clear();
    file.seekg(0);
    timestamp = createTimestamp();
    file << timestamp << '\n';
    for (std::string line; std::getline(file, line); data.push_back(line));
    return data;
}

auto writeFile(const std::deque<std::string> &data, const std::string& path_to_file) -> void {
    auto file = std::fstream(path_to_file, std::ios::out);
    for (auto const &line: data) file << line << '\n';
    file.close();
}

auto getLocalFiles() -> std::vector<std::string> {
    auto files = std::vector<std::string>();
    for (auto const &entry: std::filesystem::directory_iterator(std::filesystem::current_path())) {
        if (entry.path().filename().string().ends_with(".txt")) {
            files.push_back(entry.path().filename().string());
        }
    }
    return files;
}