#include <algorithm>
#include "UserMenuModel.h"

UserMenuModel::UserMenuModel() = default;

UserMenuModel::UserMenuModel(const bool sample) {
    this->addCategory("Social media");
    this->addCategory("E-mails");
    this->addCategory("Banking");

    this->addPassword(Password{"Facebook", "qwerty123", "Social media", "facebook.com", "stupid_user@buziaczek.pl"});
    this->addPassword(Password{"Instagram", "qwerty123", "Social media", "instagram.com", "stupid_user@buziaczek.pl"});
    this->addPassword(Password{"GMail", "DecentPassword90", "E-mails", "", ""});
    this->addPassword(Password{"PKO", "SuperStronPwd2137", "Banking", "ipko.pl", "gambling_money"});
}

auto UserMenuModel::getPasswords() -> std::vector<Password> & {
    return passwords_;
}

auto UserMenuModel::getPasswords() const -> std::vector<Password> {
    return passwords_;
}

auto UserMenuModel::getPasswords(const std::string query) const -> std::vector<Password> {
    auto result = std::vector<Password>();
    const auto matcher = [query](const auto &pwd_elem) { return pwd_elem.find(query) != std::string::npos; };
    for (const auto &password: passwords_) {
        if (std::ranges::any_of(password.getAll(), matcher)) {
            result.push_back(password);
        }
    }
    return result;
}

auto UserMenuModel::getCategories() const -> std::vector<std::string> {
    return categories_;
}

auto UserMenuModel::getFilename() const -> std::string {
    return filename_;
}

auto UserMenuModel::getTimestamp() const -> std::string {
    return timestamp_;
}

auto UserMenuModel::addPassword(const Password &password) -> void {
    passwords_.push_back(password);
}

auto UserMenuModel::addCategory(const std::string category) -> void {
    categories_.push_back(category);
}

auto UserMenuModel::setFilename(const std::string filename) -> void {
    filename_ = filename;
}

auto UserMenuModel::setTimestamp(const std::string timestamp) -> void {
    timestamp_ = timestamp;
}

auto UserMenuModel::removePassword(const int index) -> void {
    passwords_.erase(passwords_.begin() + index);
}

auto UserMenuModel::removeCategory(const int index) -> void {
    auto category = categories_[index];
    const auto [first, last] = std::ranges::remove_if(passwords_, [&category](const auto &password) {
        return password.getCategory() == category;
    });
    passwords_.erase(first, last);
    categories_.erase(categories_.begin() + index);
}

auto UserMenuModel::isPasswordUsed(const std::string password) -> bool {
    return std::ranges::any_of(passwords_, [&password](const auto &password_) {
        return password_.getPassword() == password;
    });
}

auto UserMenuModel::isNameInCategories(const std::string & category) -> bool {
    return std::ranges::any_of(categories_, [&category](const auto category_) {
        return category_ == category;
    });
}

auto UserMenuModel::sortPasswords(const std::vector<int> params) -> void {
    std::ranges::sort(passwords_, [&params](const auto &pwd1, const auto &pwd2) {
        for (int i = 0; i < params.size(); i++) {
            const int result = comparePasswords(params[i], pwd1, pwd2);
            if (result == 0 and i + 1 == params.size())
                return false;
            if (result != 0)
                return result < 0;
        }
        return true;
    });
}

auto UserMenuModel::comparePasswords(const int param, const Password &pwd1, const Password &pwd2) -> int {
    const auto by_name = [](auto &pwd1, auto &pwd2) { return pwd1.getName() < pwd2.getName(); };
    const auto by_password = [](auto &pwd1, auto &pwd2) { return pwd1.getPassword() < pwd2.getPassword(); };
    const auto by_category = [](auto &pwd1, auto &pwd2) { return pwd1.getCategory() < pwd2.getCategory(); };
    const auto by_website = [](auto &pwd1, auto &pwd2) { return pwd1.getWebsite() < pwd2.getWebsite(); };
    const auto by_login = [](auto &pwd1, auto &pwd2) { return pwd1.getLogin() < pwd2.getLogin(); };

    if (param == 1)
        return by_name(pwd1, pwd2) ? -1 : (by_name(pwd2, pwd1) ? 1 : 0);
    if (param == 2)
        return by_password(pwd1, pwd2) ? -1 : (by_password(pwd2, pwd1) ? 1 : 0);
    if (param == 3)
        return by_category(pwd1, pwd2) ? -1 : (by_category(pwd2, pwd1) ? 1 : 0);
    if (param == 4)
        return by_website(pwd1, pwd2) ? -1 : (by_website(pwd2, pwd1) ? 1 : 0);
    if (param == 5)
        return by_login(pwd1, pwd2) ? -1 : (by_login(pwd2, pwd1) ? 1 : 0);

    return 0;
}
