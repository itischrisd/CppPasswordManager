#include <vector>
#include <string>

/**
 * Checks if all integers in vector are smaller or equal to max and bigger than zero
 * @param input vector with integers to validate
 * @param max biggest allowed integer
 * @return true if 0 < all integers from input <= max, false otherwise
 */
auto isFromRange(std::vector<int> input, int max) -> bool;

/**
 * Checks if input integer is smaller or equal to max integer and bigger than zero
 * @param input integer to validate
 * @param max biggest allowed integer
 * @return true if 0 < input <= max, false otherwise
 */
auto isFromRange(int input, int max) -> bool;

/**
 * Checks if string contains only a positive integer representation
 * @param input string to validate
 * @return true if string is positive integer, false otherwise
 */
auto isSingleNumber(std::string input) -> bool;

/**
 * Checks if string contains only  positive integers seperated by space
 * @param input string to validate
 * @return true if contains only positive integers and spaces, false otherwise
 */
auto isMultiNumber(std::string input) -> bool;

/**
 * Checks if string is not empty
 * @param input string to validate
 * @return true if not empty, false otherwise
 */
auto isNotEmpty(std::string input) -> bool;

/**
 * Checks if file specified by parameter exists in filesystem
 * @param input path to file to validate
 * @return true if input is valid file, false otherwise
 */
auto isValidFile(std::string input) -> bool;