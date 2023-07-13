#include <deque>
#include <string>

/**
 * Encrypts strings in deque using provided password string
 * @param data reference to deque of strings to encrypt
 * @param password plaintext password
 */
auto encryptData(std::deque<std::string> &data, std::string password) -> void;

/**
 * Decrypts strings in deque using provided password string
 * @param data reference to deque of strings to decrypt
 * @param password plaintext password
 */
auto decryptData(std::deque<std::string> &data, std::string password) -> void;

/**
 * Ensures hashed password is unique by transforming it in designed way
 * @param password reference to plaintext password
 */
auto simpleHash(std::string &password) -> void;

/**
 * Encrypts single string using provided password string
 * @param line string to encrypt
 * @param password hashed password
 * @return encrypted string
 */
auto encrypt(std::string line, std::string password) -> std::string;

/**
 * Decrypts single string using provided password string
 * @param line string to decrypt
 * @param password hashed password
 * @return decrypted string
 */
auto decrypt(std::string line, std::string password) -> std::string;