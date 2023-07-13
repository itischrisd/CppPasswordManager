#include <string>
#include <vector>

/**
 * Various methods dedicated to displaying user menu items using more generic methods and external strings
 */
namespace user {
    auto displayUserMenu() -> void;

    auto displayPasswords(const std::vector<std::vector<std::string>> &) -> void;

    auto displaySearchPassword() -> void;

    auto displaySortPassword() -> void;

    auto displayAddPassword() -> void;

    auto displayAddPasswordSuccess() -> void;

    auto displayEditPassword() -> void;

    auto displayEditPasswordSuccess() -> void;

    auto displayEditPasswordAttribute() -> void;

    auto displayDeletePassword() -> void;

    auto displayDeletePasswordSuccess() -> void;

    auto displayAddCategory() -> void;

    auto displayAddCategoryFail() -> void;

    auto displayAddCategorySuccess() -> void;

    auto displayDeleteCategory(std::vector<std::string>) -> void;

    auto displayDeleteList() -> void;

    auto displayAskConfirmation() -> void;

    auto displayDeleteCategorySuccess() -> void;

    auto displayViewTimestamp(std::string) -> void;

    auto displayCloseMenu() -> void;

    auto displayNameVault() -> void;

    auto displayPasswordName() -> void;

    auto displayPasswordPassword() -> void;

    auto displayPasswordPasswordOwn() -> void;

    auto displayPasswordPasswordWeak() -> void;

    auto displayPasswordPasswordUsed() -> void;

    auto displayPasswordPasswordGenLength() -> void;

    auto displayPasswordPasswordGenOptions() -> void;

    auto displayPasswordCategory(std::vector<std::string>) -> void;

    auto displayPasswordWebsite() -> void;

    auto displayPasswordLogin() -> void;

    auto displayPasswordsEmpty() -> void;

    auto displayCategoriessEmpty() -> void;
}