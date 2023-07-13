#include <string>
#include <deque>
#include <vector>

/**
 * Reads every line from file, puts timestamp with current date into file
 * @param path_to_file filename or path to file
 * @return deque of strings with lines from file
 */
auto readFile(std::string path_to_file) -> std::deque<std::string>;

/**
 * Writes every line to file
 * @param data reference to deque of strings to write to file
 * @param path_to_file filename or path to file
 */
auto writeFile(const std::deque<std::string> &data, std::string path_to_file) -> void;

/**
 * Searches program's folder for txt files
 * @return vector of strings with filenames
 */
auto getLocalFiles() -> std::vector<std::string>;