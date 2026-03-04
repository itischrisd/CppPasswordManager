#include "Password.h"

#include <utility>

Password::Password(std::string name, std::string password, std::string category,
                   std::string website, std::string login) : name_(std::move(name)),
                                                             password_(std::move(password)),
                                                             category_(std::move(category)),
                                                             website_(std::move(website)),
                                                             login_(std::move(login)) {
}

Password::Password() = default;

auto Password::getName() const -> std::string {
    return name_;
}

auto Password::getPassword() const -> std::string {
    return password_;
}

auto Password::getCategory() const -> std::string {
    return category_;
}

auto Password::getWebsite() const -> std::string {
    return website_;
}

auto Password::getLogin() const -> std::string {
    return login_;
}

auto Password::getAll() const -> std::vector<std::string> {
    return std::vector{name_, password_, category_, website_, login_};
}

auto Password::setName(const std::string &name) -> void {
    name_ = name;
}

auto Password::setPassword(const std::string &password) -> void {
    password_ = password;
}

auto Password::setCategory(const std::string &category) -> void {
    category_ = category;
}

auto Password::setWebsite(const std::string &website) -> void {
    website_ = website;
}

auto Password::setLogin(const std::string &login) -> void {
    login_ = login;
}
