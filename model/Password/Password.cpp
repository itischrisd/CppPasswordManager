#include <utility>
#include "Password.h"

Password::Password() = default;

Password::Password(std::string name, std::string password, std::string category,
                   std::string website, std::string login) : name_(std::move(name)),
                                                             password_(std::move(password)),
                                                             category_(std::move(category)),
                                                             website_(std::move(website)),
                                                             login_(std::move(login)) {}

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
    return std::vector<std::string>{name_, password_, category_, website_, login_};
}

void Password::setName(const std::string name) {
    Password::name_ = name;
}

void Password::setPassword(const std::string password) {
    Password::password_ = password;
}

void Password::setCategory(const std::string category) {
    Password::category_ = category;
}

void Password::setWebsite(const std::string website) {
    Password::website_ = website;
}

void Password::setLogin(const std::string login) {
    Password::login_ = login;
}