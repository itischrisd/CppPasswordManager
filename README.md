# Password Manager

This project was developed as a final assignment for the PJC (Programming in C++) practical classes, taught by Filip Kwiatkowski during studies on [PJAIT](https://www.pja.edu.pl/en/).

## Project Description

The Password Manager is a console application built using C++ that provides functionality for managing and storing
passwords securely. The application allows users to create and store password entries along with additional information,
such as name, category, website, and login credentials. The passwords are encrypted using a custom encryption scheme,
and the master password is required for encryption and decryption operations.

The primary objectives of this project are as follows:

- Develop a console application for managing and storing passwords.
- Implement a custom encryption scheme for securing the password entries.
- Provide various operations such as adding, editing, searching, and deleting password entries.
- Enable sorting of passwords based on different parameters.
- Implement timestamp recording for decryption attempts.
- Ensure clean code architecture and adherence to good programming practices.

## Features

The Password Manager application offers the following features:

- Interactive command-line interface for user interaction.
- Secure encryption and decryption of password entries using a custom encryption scheme.
- Addition, modification, and deletion of password entries.
- Searching for passwords based on specified parameters.
- Sorting of password entries based on multiple criteria.
- Timestamp recording for decryption attempts.
- Error handling and informative error messages.

## Requirements

To build and run the Password Manager application, you need:

- C++20-compatible compiler (GCC, Clang, or MSVC)
- CMake (version 3.24 or higher)

## Installation

Follow these steps to build and run the Password Manager application:

1. Clone the repository:

  ```
  git clone https://github.com/itischrisd/CppPasswordManager.git
  ```

2. Navigate to the project directory:

  ```
  cd CppPasswordManager
  ```

3. Create a build directory and navigate to it:

  ```
  mkdir build
  cd build
  ```

4. Generate the build files using CMake:

  ```
  cmake .. -G "MinGW Makefiles"
  ```
You can use any compiler you want. For Windows platforms, I prefer to use MinGW.

5. Build the application:

  ```
  make
  ```

6. Run the application:

- On Linux/macOS:

  ```
  ./PasswordManager
  ```

- On Windows:

  ```
  PasswordManager.exe
  ```

## Usage

The Password Manager application provides a command-line interface for user interaction. Users can execute various
commands to perform operations such as adding, editing, searching, and deleting password entries. The application
provides clear instructions and prompts for each command.

Below is an example of how to use the Password Manager application:

1. Launch the application from the command line.
2. Follow the on-screen instructions to navigate the menu and select the desired operation.
3. Enter the required information for each operation (e.g., password details, search parameters).
4. View the results and follow the prompts to proceed or perform additional actions.

## License, disclaimers, known issues

The following code is distributed under the [GPLv3](./LICENSE).

---

If you need some help, notice any bugs or come up with possible improvements, feel free to reach out to me and/or create a pull request.

---

Project has been ulpoaded to GitHub as-is. Not passing some arguments by reference (such as strings) is a known issue and an unmet requirement. There is no plan to fix it at the moment.