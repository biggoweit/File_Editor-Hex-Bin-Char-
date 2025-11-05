#include "editor.hpp" 

#include <iostream> // Standard input-output stream library
#include <string> // Allows using the string class to handle user input
#include <iomanip>

// Allows editing one byte in binary, hex, or character format
void Editor::editByte(std::vector<uint8_t>& data) { 

    size_t index; 

    // Asks the user for the index of the byte to edit
    std::cout << "Enter the index of the byte to edit (0 to " << data.size() - 1 << "): ";
    
    while (true) { 
        std::cin >> index; 

        // Index input validation 
        if (index >= data.size()) {
            std::cout << "Invalid input. Please enter a valid index: ";
        } else {
            break; 
        }
    }

    // Choose format to edit the byte
    std::cout << "Choose format to edit the selected byte: \n"; 
    std::cout << "1. Binary\n"; 
    std::cout << "2. Hexadecimal\n"; 
    std::cout << "3. Character\n"; 
    std::cout << "Enter your choice (1-3): ";


    // Get the user's choice
    int choice; 
    while (true) { 
        std::cin >> choice;

        // Input validation
        if (choice < 1 || choice > 3) { 
            std::cout << "Invalid choice. Please enter a valid number (1-3): ";
        } else {
            break;
        }
    }

    // Get new value in the chosen format
    uint8_t newValue;

    // For binary format
    if (choice == 1) {
        std::string binInput;
        std::cout << "Enter the new value in binary form (8 bits): ";
        while (true) {
            std::cin >> binInput;
            if (binInput.length() != 8) {
                std::cout << "Invalid input. Please enter a valid binary value (8 bits. e.g: 01001000): ";
                continue;
            }
            
            bool invalid = false;
            for (char c : binInput) {
                if (c != '0' && c != '1') {
                    invalid = true;
                    break;
                }
            }
            if (invalid) {
                std::cout << "Invalid input. Please enter a valid binary value (8 bits. e.g: 01001000): ";
                continue;
            }
            uint8_t value = 0;
            for (char c : binInput) {
                value <<= 1;
                if (c == '1') value |= 1;
            }
            newValue = value;

            // Displays the binary output in its original form, hex and char formats
               std::cout << binInput 
                  << std::hex << std::uppercase << std::setw(2) 
                  << std::setfill('0') << static_cast<int>(newValue) 
                  << static_cast<char>(newValue) 
                  << std::dec << std::endl; 
            break;
        }

    }
    // For hexadecimal format
    else if (choice == 2) {
        std::string hexInput;
        std::cout << "Enter the new value in hexadecimal: ";
        while (true) {
            std::cin >> hexInput;
            if (hexInput.length() != 2) {
                std::cout << "Invalid input. Please enter a valid hexadecimal value (00-FF): ";
                continue;
            }
            
            bool invalid = false;
            for (char c : hexInput) {
                bool isDigit = (c >= '0' && c <= '9');
                bool isUpper = (c >= 'A' && c <= 'F');
                bool isLower = (c >= 'a' && c <= 'f');
                if (!isDigit && !isUpper && !isLower) {
                    invalid = true;
                    break;
                }
            }
            if (invalid) {
                std::cout << "Invalid input. Please enter a valid hexadecimal value (00-FF): ";
                continue;
            } else {
                   newValue = static_cast<uint8_t>(std::stoi(hexInput, nullptr, 16));

                   // Convert to binary and display all formats
                    std::bitset<8> binary(newValue); 
                    std::cout << std::uppercase << hexInput 
                              << binary 
                              << static_cast<char>(newValue) 
                              << std::endl; 
                break;
            }
            
        }

    } else {
        
        // For character format
        char c;

        std::cout << "Enter the new value in character form: "; 
        std::cin.get(c); 
        if (c == '\n') std::cin.get(c); 
        newValue = static_cast<uint8_t>(c);       
    }

    // Update the byte and confirm the change to the user
    data[index] = newValue; 
    std::cout << "Byte " << index << " updated to " << static_cast<char>(newValue) << " successfully. \n"; 
}
