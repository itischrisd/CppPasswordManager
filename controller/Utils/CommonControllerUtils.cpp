#include "CommonControllerUtils.h"
#include "../../view/Utils/CommonViewUtils.h"
#include "Validator.h"
#include "Sanitizer.h"

auto getSingleOption(const int limit) -> int {
    while (true) {
        auto input = querySingleItem();
        if (not isSingleNumber(input) or not isNotEmpty(input)) {
            displayInvalidSelection();
            continue;
        }
        auto option = string_to_int(input);
        if (isFromRange(option, limit))
            return option;
        displayInvalidSelection();
    }
}

auto getMultiOption(const int limit) -> std::vector<int> {
    while (true) {
        auto input = queryMultiItems();
        if (not isMultiNumber(input) or not isNotEmpty(input)) {
            displayInvalidSelection();
            continue;
        }
        auto option = string_to_vec_int(input);
        if (isFromRange(option, limit))
            return option;
        displayInvalidSelection();
    }
}

auto getStringInput() -> std::string {
    while (true) {
        auto input = queryStringInput();
        if (isNotEmpty(input)) {
            return input;
        }
        displayEmptyInput();
    }
}

auto getYesNoInput() -> std::string {
    while (true) {
        auto input = queryStringInput();
        if (isNotEmpty(input) and (input == "Y" or input == "N")) {
            return input;
        }
        displayInvalidSelection();
    }
}