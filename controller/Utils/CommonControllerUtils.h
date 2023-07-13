#include <string>
#include <vector>

/**
 * Gets single integer input from user and validates it against parameter
 * @param limit highest possible integer
 * @return integer from user no bigger than argument
 */
auto getSingleOption(int limit) -> int;

/**
 * Gets multiple integers input from user and validates it against parameter
 * @param limit highest possible integer
 * @return vector of integers from user no bigger than argument
 */
auto getMultiOption(int limit) -> std::vector<int>;

/**
 * Gets string input from user and validates it
 * @return non-empty string from user
 */
auto getStringInput() -> std::string;

/**
 * Gets Y/N input from user
 * @return string with Y or N value
 */
auto getYesNoInput() -> std::string;