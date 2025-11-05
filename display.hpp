#pragma once // Prevents the header from being included multiple times

#include <vector> // Allows the use of the vector class (dynamic array)
#include <cstdint> // For fixed-width integer types which helps on handling binary data

 // Class that shows the file's content in a table format, showing it in binary, hex, and character format
class Display { 
     
    public: 
    static void showData(const std::vector<uint8_t>& data, 
                         size_t BytesPerLine = 16, 
                         size_t StartOffset = 0, 
                         size_t EndOffset = 0);
}; 