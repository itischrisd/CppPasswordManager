#include <string>

/**
 * Public class containing all strings available for user display
 */
struct EN {
    static inline const std::string WELCOME = "Welcome to Password Manager";
    static inline const std::string LOAD_LOCAL = "Load file from app directory";
    static inline const std::string LOAD_EXTERNAL = "Load file from external directory";
    static inline const std::string NEW_EMPTY = "Create new empty file with no data";
    static inline const std::string NEW_SAMPLE = "Create new file with sample data";
    static inline const std::string ABOUT = "About Password Manager";
    static inline const std::string EXIT = "Exit program";

    static inline const std::string USER_WELCOME = "Password vault menu - choose option";
    static inline const std::string USER_VIEW = "View passwords";
    static inline const std::string USER_SEARCH = "Search for password";
    static inline const std::string USER_SORT = "Sort passwords";
    static inline const std::string USER_ADD_PASS = "Add new password";
    static inline const std::string USER_EDIT = "Edit password";
    static inline const std::string USER_DEL_PASS = "Delete password";
    static inline const std::string USER_ADD_CAT = "Add new category";
    static inline const std::string USER_DEL_CAT = "Delete category";
    static inline const std::string USER_TIMESTAMP = "Check file timestamp";
    static inline const std::string USER_SAVE_CLOSE = "Save and close";

    static inline const std::string SEARCH_PROMPT = "Enter search query";

    static inline const std::string SORT_PROMPT = "Select sort parameters in order of importance";

    static inline const std::string ADD_PASS_START = "Creating new password";
    static inline const std::string ADD_PASS_ATTRIBUTE = "Enter new record's ";
    static inline const std::string ADD_PASS_GEN_PROMPT = "Select password creation method";
    static inline const std::string ADD_PASS_OWN = "Input my own password";
    static inline const std::string ADD_PASS_WEAK = "Password is too weak";
    static inline const std::string ADD_PASS_GEN = "Generate password for me";
    static inline const std::string ADD_PASS_GEN_LENGTH = "Choose password length";
    static inline const std::string ADD_PASS_GEN_OPTIONS = "Select password options";
    static inline const std::string ADD_PASS_GEN_LOWER = "Lowercase letters";
    static inline const std::string ADD_PASS_GEN_UPPER = "Uppercase letters";
    static inline const std::string ADD_PASS_GEN_NUMBERS = "Numbers";
    static inline const std::string ADD_PASS_GEN_SPECIAL = "Special characters";
    static inline const std::string ADD_PASS_EXISTS = "Password already used for another record";
    static inline const std::string ADD_PASS_SUCCESS = "Password successfully added";

    static inline const std::string EDIT_PASS_PROMPT = "Choose password to edit";
    static inline const std::string EDIT_PASS_ATTRIBUTE = "Select password's attribute to edit";
    static inline const std::string EDIT_PASS_SUCCESS = "Password successfully edited";

    static inline const std::string DEL_PASS_PROMPT = "Choose password to delete";
    static inline const std::string DEL_PASS_SUCCESS = "Password successfully deleted";

    static inline const std::string ADD_CAT_ATTRIBUTE = "Enter new category ";
    static inline const std::string ADD_CAT_EXISTS = "Category already exists";

    static inline const std::string DEL_CAT_PROMPT = "Choose category to delete";
    static inline const std::string DEL_CAT_PASS = "Following passwords will be deleted";
    static inline const std::string DEL_CAT_SUCCESS = "Category successfully deleted";

    static inline const std::string TIMESTAMP_READ = "File last accessed on";
    static inline const std::string TIMESTAMP_EMPTY = "This is a new vault file";

    static inline const std::string SAVE_CLOSE_ASK = "Do you want to save before closing vault? (Y/N)";

    static inline const std::string ATTR_NAME = "Name";
    static inline const std::string ATTR_PASSWORD = "Password";
    static inline const std::string ATTR_CATEGORY = "Category";
    static inline const std::string ATTR_WEBSITE = "Website";
    static inline const std::string ATTR_LOGIN = "Login";
    static inline const std::string ATTR_EMPTY = " (press ENTER for empty)";

    static inline const std::string FILE_PROMPT = "Choose file from list";
    static inline const std::string FILE_NONE = "No files in app directory. Please select different option";
    static inline const std::string FILE_OWN = "Enter path to file (including filename and extension)";
    static inline const std::string FILE_WRONG = "File is not a valid password vault";
    static inline const std::string FILE_PASS = "Enter password to vault file";
    static inline const std::string FILE_NAME = "Name your vault file";

    static inline const std::string ENTER_SEL_SINGLE = "Enter selected number";
    static inline const std::string ENTER_SEL_MULTI = "Enter selected numbers separated by space";
    static inline const std::string ENTER_SURE = "Are you sure? (Y/N)";
    static inline const std::string ENTER_INVALID = "Invalid input, please retry";
    static inline const std::string ENTER_EMPTY = "Empty input, please retry";

    static inline const std::string EMPTY_PASS = "No password records present in vault";
    static inline const std::string EMPTY_CAT = "No category records present in vault";

    static inline const std::string ABOUT_NAME = "Password Manager v1.0, AD 2023";
    static inline const std::string ABOUT_AUTHOR = "by Krzysztof Dudek @ PJAIT";
    static inline const std::string ABOUT_CONTACT = "Reach me @ krzysztof.dudek [at] pjwstk.edu.pl";
};