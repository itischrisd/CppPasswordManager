#pragma once

#include <string>
#include <vector>

/**
 * Class representing password record in memory
 */
class Password {
    std::string name_;
    std::string password_;
    std::string category_;
    std::string website_;
    std::string login_;
public:
    /**
     * Constructs Password object with all provided arguments
     * @param name name of record
     * @param password plaintext password string
     * @param category category name
     * @param website webstie URL, empty if none
     * @param login account login, empty if none
     */
    Password(std::string name, std::string password, std::string category,
             std::string website, std::string login);

    /**
     * Construct empty Password object
     */
    Password();

    auto getName() const -> std::string;

    auto getPassword() const -> std::string;

    auto getCategory() const -> std::string;

    auto getWebsite() const -> std::string;

    auto getLogin() const -> std::string;

    /**
     * Provides string representation of object
     * @return vector of strings, which are object's fields values
     */
    auto getAll() const -> std::vector<std::string>;

    void setName(std::string);

    void setPassword(std::string);

    void setCategory(std::string);

    void setWebsite(std::string);

    void setLogin(std::string);
};