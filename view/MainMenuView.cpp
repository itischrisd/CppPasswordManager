#include "MainMenuView.h"
#include "Utils/Components.h"
#include "Locale/EN.cpp"

namespace main {
    auto displayMainMenu() -> void {
        displayTitle('\n' + EN::WELCOME);
        displayNumberedList({
                                    EN::LOAD_LOCAL,
                                    EN::LOAD_EXTERNAL,
                                    EN::NEW_EMPTY,
                                    EN::NEW_SAMPLE,
                                    EN::ABOUT,
                                    EN::EXIT
                            });
    }

    auto displayLoadLocalFile(const std::vector<std::string> files) -> void {
        displayTitle(EN::FILE_PROMPT);
        displayNumberedList(files);
    }

    auto displayLoadExternalFile() -> void {
        displayPrompt(EN::FILE_OWN);
    }

    auto displayNewEmptyFile() -> void {
        displayPrompt(EN::NEW_EMPTY);
    }

    auto displayNewSampleFile() -> void {
        displayPrompt(EN::NEW_SAMPLE);
    }

    auto displayAboutPasswordManager() -> void {
        displayTitle(EN::ABOUT_NAME);
        displayTitle(EN::ABOUT_AUTHOR);
        displayTitle(EN::ABOUT_CONTACT);
    }

    auto displayNoLocalFiles() -> void {
        displayError(EN::FILE_NONE);
    }

    auto displayInvalidFile() -> void {
        displayError(EN::FILE_WRONG);
    }
}