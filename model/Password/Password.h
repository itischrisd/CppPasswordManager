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
    Password(
        std::string name,
        std::string password,
        std::string category,
        std::string website,
        std::string login
    );

    /**
     * Construct empty Password object
     */
    Password();

    [[nodiscard]] auto getName() const -> std::string;

    [[nodiscard]] auto getPassword() const -> std::string;

    [[nodiscard]] auto getCategory() const -> std::string;

    [[nodiscard]] auto getWebsite() const -> std::string;

    [[nodiscard]] auto getLogin() const -> std::string;

    /**
     * Provides string representation of object
     * @return vector of strings, which are object's fields values
     */
    [[nodiscard]] auto getAll() const -> std::vector<std::string>;

    auto setName(const std::string &) -> void;

    auto setPassword(const std::string &) -> void;

    auto setCategory(const std::string &) -> void;

    auto setWebsite(const std::string &) -> void;

    auto setLogin(const std::string &) -> void;
};
