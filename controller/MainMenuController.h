#include <string>

/**
 * Handles user navigation between main menu options, invokes requested functionalities
 */
auto mainMenu() -> void;

/**
 * Allows user to select file located in program's folder and initiates its loading into program's memory
 */
auto loadLocalFile() -> void;

/**
 * Allows user to input filename from any system diretory and, if valid, initiates its loading into program's memory
 */
auto loadExternalFile() -> void;

/**
 * Loads empty password vault into program's memory
 */
auto newEmptyFile() -> void;

/**
 * Loads password vault with sample data into program's memory
 */
auto newSampleFile() -> void;

/**
 * Invokes displaying of information about program
 */
auto aboutPasswordManager() -> void;

/**
 *
 */
/**
 * Invokes functions loading and decrypting data from provided filename/path
 * @param filename filename or path to file
 */
auto loadData(std::string filename) -> void;

/**
 * Allows user to select vault file from program's folder and loads its filename into parameter
 * @param filename reference to filename
 */
auto selectFileName(std::string &filename) -> void;