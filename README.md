# File Editor – Binary, Hexadecimal and Character Representation

This project is a modular **C++ file editor** that allows users to **view, edit, and save binary files** directly from the terminal.  
It displays the contents of a file in **binary**, **hexadecimal**, and **character (ASCII)** formats simultaneously, providing a simple and efficient way to inspect and modify data at the byte level.

---

## Project Overview

The program was developed for the **Programming in C/C++** course as a three-phase project:
1. **Conception Phase** – System design and planning.  
2. **Development Phase** – Implementation of core functionalities (load, display, edit, save).  
3. **Finalization Phase** – Optimization and bug fixing.

The system follows a **modular design** with three main classes:
- **FileManager** – Handles file reading and saving.  
- **Display** – Prints the file content in Binary, Hexadecimal, and Character formats.  
- **Editor** – Allows the user to edit any byte of the file interactively.

---

## Installation Instructions

No external installation is required, to use it, simply click on the green button "code" and create a codespace. 
There, it's possible to test it by creating a file, typing: echo "Anything you want to put on the file" > file_name.bin

### To compile

Run the following command in the terminal:
g++ main.cpp file_manager.cpp display.cpp editor.cpp -o file_editor

### To execute

Run on the terminal:
./file_editor

### Usage

First the program will ask for the file's name and allow to input:
file_name.bin
After loading the file and validating if it's not empty, a simple menu is shown in the terminal:
Menu:
1. Display file content
2. Edit a byte
3. Save file
4. Exit
Enter your choice (1-4):

Where: 

Option 1 → Displays file contents in Binary, Hex, and Character formats.

Option 2 → Allows you to choose a byte index and edit it (Binary / Hex / Char).

Option 3 → Saves all modifications.

Option 4 → Exits the program.

**Example**
By choosing 1 after creating a file with "Hello"written on it, the output will look similar to this:
 | 01001000 01100101 01101100 01101100 01101111  | 48 65 6C 6C 6F  | Hello

 ### Structure

The program is structured in four modules

├── main.cpp

├── display.cpp

├── display.hpp

├── editor.cpp

├── editor.hpp

├── file_manager.cpp

├── file_manager.hpp


main: calls the other modules and controls the program stream.

display: outputs the file's content in the three formats (Bin, Hex and Char).

editor: allows the user to edit specific bytes in any of the three formats.

file_manager: reads/saves the files content and saves any change made by the user.

### Features

Display file contents in binary, hex, and character forms

Edit specific bytes in three formats

Input validation for binary and hexadecimal editing

File loading and saving

Modular class-based architecture

Clear and readable terminal interface

### Licence

MIT

### Author

Lucas Barretto Biggoweit
2025
