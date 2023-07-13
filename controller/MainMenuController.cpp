#include <stdexcept>
#include "MainMenuController.h"
#include "UserMenuController.h"
#include "Utils/CommonControllerUtils.h"
#include "Utils/Validator.h"
#include "../view/MainMenuView.h"
#include "../model/File/ReaderWriter.h"
#include "../model/File/Encrypter.h"
#include "../model/File/Serializer.h"
#include "../view/Utils/CommonViewUtils.h"

auto mainMenu() -> void {
    while (true) {
        main::displayMainMenu();
        auto option = getSingleOption(6);
        switch (option) {
            case 1:
                loadLocalFile();
                break;
            case 2:
                loadExternalFile();
                break;
            case 3:
                newEmptyFile();
                break;
            case 4:
                newSampleFile();
                break;
            case 5:
                aboutPasswordManager();
                break;
            case 6:
            default:
                break;
        }
        if (option == 6) {
            break;
        }
    }
}

auto loadLocalFile() -> void {
    auto filename = std::string();
    selectFileName(filename);
    loadData(filename);
}

auto loadExternalFile() -> void {
    main::displayLoadExternalFile();
    auto filename = getStringInput();
    if (not isValidFile(filename)) {
        main::displayInvalidFile();
        return;
    }
    loadData(filename);
}

auto newEmptyFile() -> void {
    main::displayNewEmptyFile();
    auto userMenuModel = UserMenuModel();
    auto userMenuController = UserMenuController(userMenuModel);
    userMenuController.userMenu();
}

auto newSampleFile() -> void {
    main::displayNewSampleFile();
    auto userMenuModel = UserMenuModel(true);
    auto userMenuController = UserMenuController(userMenuModel);
    userMenuController.userMenu();
}

auto aboutPasswordManager() -> void {
    main::displayAboutPasswordManager();
}

auto loadData(const std::string filename) -> void {
    auto data = readFile(filename);
    displayPasswordPrompt();
    auto password = getStringInput();
    decryptData(data, password);
    UserMenuModel userMenuModel;
    try {
        userMenuModel = serializeToVault(data);
    } catch (const std::out_of_range &e) {
        main::displayInvalidFile();
        return;
    }
    userMenuModel.setFilename(filename);
    auto userMenuController = UserMenuController(userMenuModel);
    userMenuController.userMenu();
}

auto selectFileName(std::string &filename) -> void {
    const auto files = getLocalFiles();
    if (files.empty()) {
        main::displayNoLocalFiles();
        return;
    }
    main::displayLoadLocalFile(files);
    filename = files[getSingleOption((int) files.size()) - 1];
}
