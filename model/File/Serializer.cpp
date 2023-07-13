#include <stdexcept>
#include "Serializer.h"
#include "../Utils/Timestamp.h"

auto deserializeToDeque(const UserMenuModel &userMenuModel) -> std::deque<std::string> {
    std::deque<std::string> data;
    data.push_back(createTimestamp());
    for (const auto &category: userMenuModel.getCategories())
        data.push_back("cat " + category);
    data.emplace_back("");
    for (const auto &password: userMenuModel.getPasswords()) {
        data.push_back("nam " + password.getName());
        data.push_back("pas " + password.getPassword());
        data.push_back("cat " + password.getCategory());
        data.push_back("web " + password.getWebsite());
        data.push_back("log " + password.getLogin());
        data.emplace_back("\n");
    }
    return data;
}

auto serializeToVault(std::deque<std::string> &data) -> UserMenuModel {
    UserMenuModel userMenuModel;
    userMenuModel.setTimestamp(data.front());
    data.pop_front();
    while (true) {
        if (data.front().size() < 2) {
            data.pop_front();
            break;
        }
        userMenuModel.addCategory(data.front().substr(4, data.front().length()));
        data.pop_front();
    }
    while (true) {
        if (data.empty() or data.front().size() < 2) break;
        auto password = Password();
        if (data.empty()) throw (std::out_of_range("Unexpected empty line!"));
        password.setName(data.front().substr(4, data.front().length()));
        data.pop_front();
        if (data.empty()) throw (std::out_of_range("Unexpected empty line!"));
        password.setPassword(data.front().substr(4, data.front().length()));
        data.pop_front();
        if (data.empty()) throw (std::out_of_range("Unexpected empty line!"));
        password.setCategory(data.front().substr(4, data.front().length()));
        data.pop_front();
        if (data.empty()) throw (std::out_of_range("Unexpected empty line!"));
        password.setWebsite(data.front().substr(4, data.front().length()));
        data.pop_front();
        if (data.empty()) throw (std::out_of_range("Unexpected empty line!"));
        password.setLogin(data.front().substr(4, data.front().length()));
        data.pop_front();
        userMenuModel.addPassword(password);
        data.pop_front();
    }
    return userMenuModel;
}
