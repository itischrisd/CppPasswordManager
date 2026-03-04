#pragma once
#include <string>
#include <vector>

/**
 * Displays title string in console on a seperate line
 * @param title string to display
 */
auto displayTitle(const std::string &title) -> void;

/**
 * Displays prompt string in console on a seperate line
 * @param prompt string to display
 */
auto displayPrompt(const std::string &prompt) -> void;

/**
 * Displays error string in console on a seperate line
 * @param error string to display
 */
auto displayError(const std::string &error) -> void;

/**
 * Displays numbered list with every string from vector on a new line
 * @param list vector of strings to display
 */
auto displayNumberedList(const std::vector<std::string> &list) -> void;

/**
 * Displays data in console in a formatted, numbered table
 * @param table reference to vector of vectors of strings to display
 */
auto displayTable(const std::vector<std::vector<std::string> > &table) -> void;

/**
 * Gets raw input from user
 * @return string input from user
 */
auto getInput() -> std::string;
