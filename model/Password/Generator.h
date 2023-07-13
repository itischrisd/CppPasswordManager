#include <vector>
#include <string>

/**
 * Auxiliary enum to manage password parameters requested by user
 */
enum class PasswordOption {
    LowerCase = 1,
    UpperCase = 2,
    Numbers = 3,
    SpecialCharacters = 4
};

/**
 * Generates password based on provided length and requirements vector
 * @param length length of generated password
 * @param passwordOption vector of enum values representing requirements
 * @return string satisfying required parameters and length
 */
auto generatePassword(int length, std::vector<PasswordOption> passwordOption) -> std::string;