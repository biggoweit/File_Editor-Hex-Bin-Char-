#include "display.hpp"
#include "editor.hpp"
#include "file_manager.hpp"

#include <iostream> // Standard input-output stream library
#include <fstream> // File stream library for file handling
#include <vector> // Allows the use of the vector class (dynamic array)
#include <cstdint> // Helps on handling binary data



// Main function
int main() {

    std::string filename = "test.bin"; 
    std::vector<uint8_t> data;

    FileManager::loadFile(filename, data);

    FileManager::saveFile(filename, data);

    // Load file
    if (!FileManager::loadFile(filename, data)) {
        std::cout << "File not loaded or empty \n";
        return 1; 
    } else {
        std::cout << "File loaded: " << filename << "\n";
    }

    // Main loop that shows the menu and prompts the user to choose what to do
    bool running = true; 
    while (running) { 
        std::cout << "\nMenu:\n"; 
        std::cout << "1. Display file content\n"; 
        std::cout << "2. Edit a byte\n"; 
        std::cout << "3. Save file\n"; 
        std::cout << "4. Exit\n"; 
        std::cout << "Enter your choice (1-4): ";

        // Get user's choice
        int choice; 
        std::cin >> choice; 
        if (choice == 1) {
            Display::showData(data); 
        } else if (choice == 2) {
            Editor::editByte(data); 
        } else if (choice == 3) {
            FileManager::saveFile(filename, data); 
            std::cout << "File saved: " << filename << "\n"; 
        } else if (choice == 4) {
            running = false; 
        } else {
            std::cout << "Invalid choice. Please try again.\n"; 
        }

    }

    return 0; 
    
} 
