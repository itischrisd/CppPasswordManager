#include "../model/UserMenuModel.h"

class UserMenuController {
private:
    UserMenuModel userMenuModel;
public:
    /**
     * Constructs new object of User Menu Controller
     * @param userMenuModel object containing all password data currently loaded into Password Manager
     */
    explicit UserMenuController(UserMenuModel userMenuModel);

    /**
     * Initiates display of user menu and handles control fow
     */
    auto userMenu() -> void;

    /**
     * Fetches all password data and sends it to display
     */
    auto viewPasswords() -> void;

    /**
     * Queries search parameter, fetches all password data that contains it and sends it to display
     */
    auto searchPassword() -> void;

    /**
     * Gets parameters to sorty by, initiates sorting of password data, then fetches it for display
     */
    auto sortPassword() -> void;

    /**
     * Initiates workflow of creating new password record
     */
    auto addPassword() -> void;

    /**
     * Initiates workflow of editing existing password record
     */
    auto editPassword() -> void;

    /**
     * Initiates workflow of deleting existing password record
     */
    auto deletePassword() -> void;

    /**
     * Initiates workflow of adding new category name
     */
    auto addCategory() -> void;

    /**
     * Initiates workflow of deleting existing category name and its passwords
     */
    auto deleteCategory() -> void;

    /**
     * Fetches timestamp of previous file acces and sends it for display
     */
    auto viewTimestamp() -> void;

    /**
     * Asks user wether to save the data in Password Manager or not, then returns to main menu
     */
    auto saveAndClose() -> void;

    /**
     * Fetches all password data from model, then sends it for display
     */
    auto passwordTable() -> void;

    /**
     * Fetches all password data from model that satisfy query string, then sends it for display
     * @param query string that should be contained in resulting password's attributes
     */
    auto passwordTable(std::string query) -> void;

    /**
     * Fetches password data from model that have provided indexes, then sends it for display
     * @param indexes vector of indexes of passwords to display
     */
    auto passwordTable(std::vector<int> indexes) -> void;

    /**
     * Gets, validates and sanitizes new password name
     * @return string with password name
     */
    static auto passwordName() -> std::string;

    /**
     * Controls workflow of either generating or entering new plaintext password
     * @return string with new plaintext password
     */
    auto passwordPassword() -> std::string;

    /**
     * Controls workflow of entering new plaintext password
     * @return string with new plaintext password
     */
    auto passwordPasswordOwn() -> std::string;

    /**
     * Controls workflow of generating new plaintext password
     * @return string with new plaintext password
     */
    static auto passwordPasswordGenerate() -> std::string;

    /**
     * Fetches all category names from model, then sends them for display
     */
    auto passwordCategory() -> std::string;

    /**
     * Gets, validates and sanitizes new password website URL
     * @return string with password website URL
     */
    static auto passwordWebsite() -> std::string;

    /**
     * Gets, validates and sanitizes new password login
     * @return string with password login
     */
    static auto passwordLogin() -> std::string;

    /**
     * Checks if model has any password currently loaded into program
     * @return true if there are no existing passwords, false otherwise
     */
    auto checkPasswordsEmpty() -> bool;

    /**
     * Checks if model has any category names currently loaded into program
     * @return true if there are no existing category names, false otherwise
     */
    auto checkCategoriessEmpty() -> bool;
};