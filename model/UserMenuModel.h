#pragma once

#include <vector>
#include "Password/Password.h"

/**
 * Class dedicated to storing all data currently loaded into Password Manager
 */
class UserMenuModel {
    std::vector<Password> passwords_;
    std::vector<std::string> categories_;
    std::string filename_;
    std::string timestamp_;

public:
    /**
     * Constructs empty object
     */
    UserMenuModel();

    /**
     * Constructs object with sample hardcoded data
     */
    explicit UserMenuModel(bool);

    /**
     * Allows write access to currently loaded passwords
     * @return reference to vector of passwords
     */
    auto getPasswords() -> std::vector<Password> &;

    /**
     * Allows read access to currently loaded passwords
     * @return const vector of all passwords
     */
    auto getPasswords() const -> std::vector<Password>;

    /**
     * Allows read access to currently loaded passwords, that have any attribute matching input
     * @return const vector of passwords satisfying query
     */
    auto getPasswords(std::string) const -> std::vector<Password>;

    /**
     * Allows read access to currently loaded categories
     * @return const vector of strings with category names
     */
    auto getCategories() const -> std::vector<std::string>;

    /**
     * Allows access to original filename/path of password vault
     * @return const string with filename/path, empty if new vault
     */
    auto getFilename() const -> std::string;

    /**
     * Allows access to timestamp of previous time file was loaded into Password Manager
     * @return string with timestamp, empty if new vault
     */
    auto getTimestamp() const -> std::string;

    /**
     * Adds Password object into current vault
     * @param password reference to Password object
     */
    auto addPassword(const Password &password) -> void;

    /**
     * Adds category name into vector of available category names
     * @param category
     */
    auto addCategory(std::string category) -> void;

    /**
     * Saves filename/path of source file data was loaded from
     * @param filename filename or path
     */
    auto setFilename(std::string filename) -> void;

    /**
     * Saves timestamp of previous time data was loaded from file
     * @param timestamp string representing datetime of previous file loading into Password Manager
     */
    auto setTimestamp(std::string timestamp) -> void;

    /**
     * Removes Password object with specified index
     * @param index index of Password object to remove
     */
    auto removePassword(int index) -> void;

    /**
     * Removes category name with specified index
     * @param index index of category name to remove
     */
    auto removeCategory(int index) -> void;

    /**
     * Checks if parameter is used as value of password field of any object currently loaded into memory
     * @param password string to check
     * @return true if string is used as password for any record, false otherwise
     */
    auto isPasswordUsed(std::string password) -> bool;

    /**
     * Checks if parameter is used as category name any category currently loaded into memory
     * @param category string to check
     * @return true if string is used as any category name, false otherwise
     */
    auto isNameInCategories(const std::string & category) -> bool;

    /**
     * Sorts Password objects currently loaded into Password Manager by parameters in the order they are in vector
     * @param params
     */
    auto sortPasswords(std::vector<int> params) -> void;

    /**
     * Compares two passwords using the parameter specified
     * @param param number of the parameter
     * @return integer representing differene between two passwords
     */
    static auto comparePasswords(int param, const Password &, const Password &) -> int;
};