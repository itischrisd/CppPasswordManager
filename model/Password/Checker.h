#include <string>
#include <vector>
#include "Generator.h"

/**
 * Invokes isUpper, isLower, isNumber, isSpecial and isLong on argument
 * @param password string to validate
 * @return true if all requirements satisfied, false otherwise
 */
auto isStrong(std::string password) -> bool;

/**
 * Checks if string has any uppercase letters
 * @param password string to validate
 * @return true if password contains uppercase letters, false otherwise
 */
auto isUpper(std::string password) -> bool;

/**
 * Checks if string has any lowercase letters
 * @param password string to validate
 * @return true if password contains lowercase letters, false otherwise
 */
auto isLower(std::string password) -> bool;

/**
 * Checks if string has any numbers
 * @param password string to validate
 * @return true if password contains numbers, false otherwise
 */
auto isNumber(std::string password) -> bool;

/**
 * Checks if string has any special characters
 * @param password string to validate
 * @return true if password contains special characters, false otherwise
 */
auto isSpecial(std::string password) -> bool;

/**
 * Checks if string is at least 8 characters long
 * @param password string to validate
 * @return true if password length larger or equal 8, false otherwise
 */
auto isLong(std::string password) -> bool;