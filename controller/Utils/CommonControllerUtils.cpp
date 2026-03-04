#include "CommonControllerUtils.h"

#include "Sanitizer.h"
#include "Validator.h"
#include "../../view/Utils/CommonViewUtils.h"

auto getSingleOption(const int limit) -> int {
    while (true) {
        auto input = querySingleItem();

        if (not isSingleNumber(input) or not isNotEmpty(input)) {
            displayInvalidSelection();
            continue;
        }

        if (const auto option = string_to_int(input); isFromRange(option, limit)) {
            return option;
        }

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

        if (auto option = string_to_vec_int(input); isFromRange(option, limit)) {
            return option;
        }

        displayInvalidSelection();
    }
}

auto getStringInput() -> std::string {
    while (true) {
        if (auto input = queryStringInput(); isNotEmpty(input)) {
            return input;
        }

        displayEmptyInput();
    }
}

auto getYesNoInput() -> std::string {
    while (true) {
        if (auto input = queryStringInput(); isNotEmpty(input) and (input == "Y" or input == "N")) {
            return input;
        }

        displayInvalidSelection();
    }
}
