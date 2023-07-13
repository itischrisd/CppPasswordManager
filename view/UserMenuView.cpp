#include "UserMenuView.h"
#include "Locale/EN.cpp"
#include "Utils/Components.h"

namespace user {
    auto displayUserMenu() -> void {
        displayTitle('\n' + EN::USER_WELCOME);
        displayNumberedList({
                                    EN::USER_VIEW,
                                    EN::USER_SEARCH,
                                    EN::USER_SORT,
                                    EN::USER_ADD_PASS,
                                    EN::USER_EDIT,
                                    EN::USER_DEL_PASS,
                                    EN::USER_ADD_CAT,
                                    EN::USER_DEL_CAT,
                                    EN::USER_TIMESTAMP,
                                    EN::USER_SAVE_CLOSE
                            });
    }

    auto displayPasswords(const std::vector<std::vector<std::string>> &passwords) -> void {
        displayTable(passwords);
    }

    auto displaySearchPassword() -> void {
        displayPrompt(EN::SEARCH_PROMPT);
    }

    auto displaySortPassword() -> void {
        displayTitle(EN::SORT_PROMPT);
        displayNumberedList({EN::ATTR_NAME, EN::ATTR_PASSWORD, EN::ATTR_CATEGORY, EN::ATTR_WEBSITE, EN::ATTR_LOGIN});
    }

    auto displayAddPassword() -> void {
        displayTitle(EN::ADD_PASS_START);
    }

    auto displayAddPasswordSuccess() -> void {
        displayTitle(EN::ADD_PASS_SUCCESS);
    }

    auto displayEditPassword() -> void {
        displayTitle(EN::EDIT_PASS_PROMPT);
    }

    auto displayEditPasswordSuccess() -> void {
        displayTitle(EN::EDIT_PASS_SUCCESS);
    }

    auto displayEditPasswordAttribute() -> void {
        displayTitle(EN::EDIT_PASS_ATTRIBUTE);
        displayNumberedList({EN::ATTR_NAME, EN::ATTR_PASSWORD, EN::ATTR_CATEGORY, EN::ATTR_WEBSITE, EN::ATTR_LOGIN});
    }

    auto displayDeletePassword() -> void {
        displayTitle(EN::DEL_PASS_PROMPT);
    }

    auto displayDeletePasswordSuccess() -> void {
        displayTitle(EN::DEL_PASS_SUCCESS);
    }

    auto displayAddCategory() -> void {
        displayPrompt(EN::ADD_CAT_ATTRIBUTE + EN::ATTR_NAME);
    }

    auto displayAddCategoryFail() -> void {
        displayError(EN::ADD_CAT_EXISTS);
    }

    auto displayAddCategorySuccess() -> void {
        displayTitle(EN::DEL_CAT_SUCCESS);
    }

    auto displayDeleteCategory(const std::vector<std::string> categories) -> void {
        displayTitle(EN::DEL_CAT_PROMPT);
        displayNumberedList(categories);
    }

    auto displayDeleteList() -> void {
        displayTitle(EN::DEL_CAT_PASS);
    }

    auto displayAskConfirmation() -> void {
        displayPrompt(EN::ENTER_SURE);
    }

    auto displayDeleteCategorySuccess() -> void {
        displayTitle(EN::DEL_CAT_SUCCESS);
    }

    auto displayViewTimestamp(const std::string timestamp) -> void {
        displayTitle(timestamp.empty() ? EN::TIMESTAMP_EMPTY : EN::TIMESTAMP_READ + ' ' + timestamp);
    }

    auto displayCloseMenu() -> void {
        displayTitle(EN::SAVE_CLOSE_ASK);
    }

    auto displayNameVault() -> void {
        displayPrompt(EN::FILE_NAME);
    }

    auto displayPasswordName() -> void {
        displayPrompt(EN::ADD_PASS_ATTRIBUTE + EN::ATTR_NAME);
    }

    auto displayPasswordPassword() -> void {
        displayTitle(EN::ADD_PASS_GEN_PROMPT);
        displayNumberedList({EN::ADD_PASS_OWN, EN::ADD_PASS_GEN});
    }

    auto displayPasswordPasswordOwn() -> void {
        displayPrompt(EN::ADD_PASS_ATTRIBUTE + EN::ATTR_PASSWORD);
    }

    auto displayPasswordPasswordWeak() -> void {
        displayError(EN::ADD_PASS_WEAK);
    }

    auto displayPasswordPasswordUsed() -> void {
        displayError(EN::ADD_PASS_EXISTS);
    }

    auto displayPasswordPasswordGenLength() -> void {
        displayTitle(EN::ADD_PASS_GEN_LENGTH);
    }

    auto displayPasswordPasswordGenOptions() -> void {
        displayTitle(EN::ADD_PASS_GEN_OPTIONS);
        displayNumberedList(
                {EN::ADD_PASS_GEN_LOWER, EN::ADD_PASS_GEN_UPPER, EN::ADD_PASS_GEN_NUMBERS, EN::ADD_PASS_GEN_SPECIAL});
    }

    auto displayPasswordCategory(const std::vector<std::string> categories) -> void {
        displayTitle(EN::ADD_PASS_ATTRIBUTE + EN::ATTR_CATEGORY);
        displayNumberedList(categories);
    }

    auto displayPasswordWebsite() -> void {
        displayPrompt(EN::ADD_PASS_ATTRIBUTE + EN::ATTR_WEBSITE + EN::ATTR_EMPTY);
    }

    auto displayPasswordLogin() -> void {
        displayPrompt(EN::ADD_PASS_ATTRIBUTE + EN::ATTR_LOGIN + EN::ATTR_EMPTY);
    }

    auto displayPasswordsEmpty() -> void {
        displayError(EN::EMPTY_PASS);
    }

    auto displayCategoriessEmpty() -> void {
        displayError(EN::EMPTY_CAT);
    }
}