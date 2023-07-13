#include <vector>
#include <string>

/**
 * Various methods dedicated to displaying main menu items using more generic methods and external strings
 */
namespace main {
    auto displayMainMenu() -> void;

    auto displayLoadLocalFile(std::vector<std::string>) -> void;

    auto displayLoadExternalFile() -> void;

    auto displayNewEmptyFile() -> void;

    auto displayNewSampleFile() -> void;

    auto displayAboutPasswordManager() -> void;

    auto displayNoLocalFiles() -> void;

    auto displayInvalidFile() -> void;
}
