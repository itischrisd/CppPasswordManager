#pragma once
#include <string>

/**
 * Invokes isUpper, isLower, isNumber, isSpecial and isLong on argument
 * @param password string to validate
 * @return true if all requirements satisfied, false otherwise
 */
auto isStrong(const std::string &password) -> bool;

/**
 * Checks if string has any uppercase letters
 * @param password string to validate
 * @return true if password contains uppercase letters, false otherwise
 */
auto isUpper(const std::string &password) -> bool;

/**
 * Checks if string has any lowercase letters
 * @param password string to validate
 * @return true if password contains lowercase letters, false otherwise
 */
auto isLower(const std::string &password) -> bool;

/**
 * Checks if string has any numbers
 * @param password string to validate
 * @return true if password contains numbers, false otherwise
 */
auto isNumber(const std::string &password) -> bool;

/**
 * Checks if string has any special characters
 * @param password string to validate
 * @return true if password contains special characters, false otherwise
 */
auto isSpecial(const std::string &password) -> bool;

/**
 * Checks if string is at least 8 characters long
 * @param password string to validate
 * @return true if password length larger or equal 8, false otherwise
 */
auto isLong(const std::string &password) -> bool;
