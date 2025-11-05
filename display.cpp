#include "display.hpp"

#include <iostream> // Standard input-output stream library
#include <iomanip> // Allows formatting input and output
#include <bitset> // For representing binary data


// Displays file content in table form showing it in binary, hex, and character format
void Display::showData(const std::vector<uint8_t>& data,
                       size_t BytesPerLine,
                       size_t StartOffset,
                       size_t lines)
{

    // Offset initialization to ensure the file's content is displayed correctly
    size_t n = data.size(); 
    if (StartOffset >= n) return; 

    if (lines == 0) {
        lines = (n - StartOffset + BytesPerLine - 1) / BytesPerLine;
    }

    for (size_t line = 0; line < lines; ++line) {
        size_t offset = StartOffset + line * BytesPerLine;
        if (offset >= n) break;

        std::cout << " | ";
        std::cout << std::left;
         
        // Print in binary representation
        for (size_t i = 0; i < BytesPerLine; ++i) { 
            if (offset + i < n) { 
                std::cout << std::bitset<8>(data[offset + i]) << " "; 
            } else { 
                std::cout << "       "; 
            }
        }

        std::cout << " | "; // Separation for hex representation

        // Print hex representation
        for (size_t i = 0; i < BytesPerLine; ++i) { 
            if (offset + i < n) { 
                std::cout << std::setw(2) << std::setfill('0') << std::hex 
                          << std::uppercase << (int)data[offset + i] << " "; 
            } else {
                std::cout << "      "; 
            }
        }

        std::cout << " | "; // Separation between hex and character representation

        // Print character representation
        for (size_t i = 0; i < BytesPerLine; ++i) {
            if (offset + i < n) {
                unsigned char c = data[offset + i];
                if (std::isprint(c)) std::cout << c;
                else std::cout << ' ';
            }
        }

        std::cout << "\n"; 
    }
}
