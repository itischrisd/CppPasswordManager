#include <utility>
#include <algorithm>
#include "UserMenuController.h"
#include "Utils/CommonControllerUtils.h"
#include "../view/UserMenuView.h"
#include "../view/Utils/CommonViewUtils.h"
#include "../model/File/ReaderWriter.h"
#include "../model/File/Serializer.h"
#include "../model/File/Encrypter.h"
#include "../model/Password/Checker.h"

UserMenuController::UserMenuController(UserMenuModel userMenuModel) : userMenuModel(std::move(userMenuModel)) {}

auto UserMenuController::userMenu() -> void {
    while (true) {
        user::displayUserMenu();
        auto option = getSingleOption(10);
        switch (option) {
            case 1:
                viewPasswords();
                break;
            case 2:
                searchPassword();
                break;
            case 3:
                sortPassword();
                break;
            case 4:
                addPassword();
                break;
            case 5:
                editPassword();
                break;
            case 6:
                deletePassword();
                break;
            case 7:
                addCategory();
                break;
            case 8:
                deleteCategory();
                break;
            case 9:
                viewTimestamp();
                break;
            case 10:
            default:
                saveAndClose();
                break;
        }
        if (option == 10) {
            break;
        }
    }
}

auto UserMenuController::viewPasswords() -> void {
    if (checkPasswordsEmpty())
        return;
    passwordTable();
}

auto UserMenuController::searchPassword() -> void {
    if (checkPasswordsEmpty())
        return;
    user::displaySearchPassword();
    const auto query = getStringInput();
    passwordTable(query);
}

auto UserMenuController::sortPassword() -> void {
    if (checkPasswordsEmpty())
        return;
    user::displaySortPassword();
    const auto options = getMultiOption(5);
    userMenuModel.sortPasswords(options);
    passwordTable();
}

auto UserMenuController::addPassword() -> void {
    if (checkCategoriessEmpty())
        return;
    user::displayAddPassword();
    const auto name = passwordName();
    const auto password = passwordPassword();
    const auto category = passwordCategory();
    const auto website = passwordWebsite();
    const auto login = passwordLogin();
    userMenuModel.addPassword(Password(name, password, category, website, login));
    user::displayAddPasswordSuccess();
}

auto UserMenuController::editPassword() -> void {
    if (checkPasswordsEmpty())
        return;
    user::displayEditPassword();
    passwordTable();
    const auto index = getSingleOption((int) userMenuModel.getPasswords().size()) - 1;
    user::displayEditPasswordAttribute();
    const auto attribute = getSingleOption(5);
    switch (attribute) {
        case 1:
            userMenuModel.getPasswords()[index].setName(passwordName());
            break;
        case 2:
            userMenuModel.getPasswords()[index].setPassword(passwordPassword());
            break;
        case 3:
            userMenuModel.getPasswords()[index].setCategory(passwordCategory());
            break;
        case 4:
            userMenuModel.getPasswords()[index].setWebsite(passwordWebsite());
            break;
        case 5:
            userMenuModel.getPasswords()[index].setLogin(passwordLogin());
            break;
        default:
            break;
    }
    user::displayEditPasswordSuccess();
}

auto UserMenuController::deletePassword() -> void {
    if (checkPasswordsEmpty())
        return;
    user::displayDeletePassword();
    passwordTable();
    auto indexes = getMultiOption((int) userMenuModel.getPasswords().size());
    std::ranges::sort(indexes, [](auto a, auto b) { return a - b; });
    std::ranges::transform(indexes, indexes.begin(), [](auto elem) { return elem - 1; });
    user::displayDeleteList();
    passwordTable(indexes);
    user::displayAskConfirmation();
    if (getYesNoInput() == "N")
        return;
    for (const auto index: indexes)
        userMenuModel.removePassword(index);
    user::displayDeletePasswordSuccess();
}

auto UserMenuController::addCategory() -> void {
    user::displayAddCategory();
    const auto category_name = getStringInput();
    if (userMenuModel.isNameInCategories(category_name)) {
        user::displayAddCategoryFail();
    } else {
        userMenuModel.addCategory(category_name);
        user::displayAddCategorySuccess();
    }
}

auto UserMenuController::deleteCategory() -> void {
    if (checkCategoriessEmpty())
        return;
    user::displayDeleteCategory(userMenuModel.getCategories());
    const auto index = getSingleOption((int) userMenuModel.getCategories().size()) - 1;
    user::displayDeleteList();
    passwordTable(userMenuModel.getCategories()[index]);
    user::displayAskConfirmation();
    while (true) {
        if (getYesNoInput() == "Y") {
            userMenuModel.removeCategory(index);
            user::displayDeleteCategorySuccess();
            return;
        } else {
            return;
        }
    }
}

auto UserMenuController::viewTimestamp() -> void {
    user::displayViewTimestamp(userMenuModel.getTimestamp());
}

auto UserMenuController::saveAndClose() -> void {
    user::displayCloseMenu();
    if (getYesNoInput() == "Y") {
        auto data = deserializeToDeque(userMenuModel);
        displayPasswordPrompt();
        auto password = getStringInput();
        encryptData(data, password);
        auto filename = userMenuModel.getFilename();
        if (filename.empty()) {
            user::displayNameVault();
            filename = getStringInput() + ".txt";
        }
        writeFile(data, filename);
    }
}

auto UserMenuController::passwordTable() -> void {
    auto password_table = std::vector<std::vector<std::string>>();
    for (const auto &password: userMenuModel.getPasswords())
        password_table.push_back(password.getAll());
    user::displayPasswords(password_table);
}

auto UserMenuController::passwordTable(const std::string query) -> void {
    auto password_table = std::vector<std::vector<std::string>>();
    for (const auto &password: userMenuModel.getPasswords(query))
        password_table.push_back(password.getAll());
    user::displayPasswords(password_table);
}

auto UserMenuController::passwordTable(const std::vector<int> indexes) -> void {
    auto password_table = std::vector<std::vector<std::string>>();
    for (int i = 0; i < userMenuModel.getPasswords().size(); i++) {
        if (std::ranges::any_of(indexes, [&i](const auto index) { return i == index; }))
            password_table.push_back(userMenuModel.getPasswords()[i].getAll());
    }
    user::displayPasswords(password_table);
}

auto UserMenuController::passwordName() -> std::string {
    user::displayPasswordName();
    return getStringInput();
}

auto UserMenuController::passwordPassword() -> std::string {
    user::displayPasswordPassword();
    const auto option = getSingleOption(2);
    switch (option) {
        case 1:
            return passwordPasswordOwn();
        case 2:
        default:
            return passwordPasswordGenerate();
    }
}

auto UserMenuController::passwordPasswordOwn() -> std::string {
    while (true) {
        user::displayPasswordPasswordOwn();
        auto password = getStringInput();
        if (userMenuModel.isPasswordUsed(password)) {
            user::displayPasswordPasswordUsed();
            user::displayAskConfirmation();
            if (getYesNoInput() == "N")
                continue;
        }
        if (not isStrong(password)) {
            user::displayPasswordPasswordWeak();
            user::displayAskConfirmation();
            if (getYesNoInput() == "N")
                continue;
        }
        return password;
    }
}

auto UserMenuController::passwordPasswordGenerate() -> std::string {
    int length;
    while (true) {
        user::displayPasswordPasswordGenLength();
        length = getSingleOption(50);
        if (length < 8) {
            user::displayPasswordPasswordWeak();
            user::displayAskConfirmation();
            if (getYesNoInput() == "N")
                continue;
        }
        break;
    }
    user::displayPasswordPasswordGenOptions();
    auto options = std::vector<PasswordOption>();
    std::ranges::transform(getMultiOption(4), std::back_inserter(options),
                           [](const auto n) { return static_cast<PasswordOption>(n); });
    return generatePassword(length, options);
}

auto UserMenuController::passwordCategory() -> std::string {
    user::displayPasswordCategory(userMenuModel.getCategories());
    const auto index = getSingleOption((int) userMenuModel.getCategories().size()) - 1;
    return userMenuModel.getCategories()[index];
}

auto UserMenuController::passwordWebsite() -> std::string {
    user::displayPasswordWebsite();
    return queryStringInput();
}

auto UserMenuController::passwordLogin() -> std::string {
    user::displayPasswordLogin();
    return queryStringInput();
}

auto UserMenuController::checkPasswordsEmpty() -> bool {
    if (userMenuModel.getPasswords().empty()) {
        user::displayPasswordsEmpty();
        return true;
    } else
        return false;
}

auto UserMenuController::checkCategoriessEmpty() -> bool {
    if (userMenuModel.getCategories().empty()) {
        user::displayCategoriessEmpty();
        return true;
    } else
        return false;
}