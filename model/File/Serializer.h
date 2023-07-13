#include <deque>
#include <string>
#include "../UserMenuModel.h"

/**
 * Puts all categories and password's attributes from model into deque of strings, adds timestamp
 * @param userMenuModel reference to object with data currently loaded into password manager's memory
 * @return deque of strings with timestamp, categories and all password's attributes
 */
auto deserializeToDeque(const UserMenuModel &userMenuModel) -> std::deque<std::string>;

/**
 * Reads all strings from deque and constructs objects based on them
 * @param data reference to deque of strings with timestamp, categories and all password's attributes
 * @return UserMenuModel object with data loaded into
 */
auto serializeToVault(std::deque<std::string> &data) -> UserMenuModel;