#include <string>

/**
 * Displays prompt and fetches user input
 * @return input string from user
 */
auto querySingleItem() -> std::string;

/**
 * Displays prompt and fetches user input
 * @return input string from user
 */
auto queryMultiItems() -> std::string;

/**
 * Displays prompt and fetches user input
 * @return input string from user
 */
auto queryStringInput() -> std::string;

/**
 * Displays information about wrong numeric input
 */
auto displayInvalidSelection() -> void;

/**
 * Displays information about unwarranted empty input
 */
auto displayEmptyInput() -> void;

/**
 * Displays password input prompt
 */
auto displayPasswordPrompt() -> void;