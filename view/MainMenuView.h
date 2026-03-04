#pragma once
#include <string>
#include <vector>

/**
 * Various methods dedicated to displaying main menu items using more generic methods and external strings
 */
namespace main {
    auto displayMainMenu() -> void;

    auto displayLoadLocalFile(const std::vector<std::string> &) -> void;

    auto displayLoadExternalFile() -> void;

    auto displayNewEmptyFile() -> void;

    auto displayNewSampleFile() -> void;

    auto displayAboutPasswordManager() -> void;

    auto displayNoLocalFiles() -> void;

    auto displayInvalidFile() -> void;
}
