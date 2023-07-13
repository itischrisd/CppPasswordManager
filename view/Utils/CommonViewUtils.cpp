#include "CommonViewUtils.h"
#include "Components.h"
#include "../Locale/EN.cpp"

auto querySingleItem() -> std::string {
    displayPrompt(EN::ENTER_SEL_SINGLE);
    return getInput();
}

auto queryMultiItems() -> std::string {
    displayPrompt(EN::ENTER_SEL_MULTI);
    return getInput();
}

auto queryStringInput() -> std::string {
    return getInput();
}

auto displayInvalidSelection() -> void {
    displayError(EN::ENTER_INVALID);
}

auto displayEmptyInput() -> void {
    displayError(EN::ENTER_EMPTY);
}

auto displayPasswordPrompt() -> void {
    displayPrompt(EN::FILE_PASS);
}