#pragma once // Prevents the header from being included multiple times

#include <vector> // Allows the use of the vector class (dynamic array)
#include <cstdint> // For fixed-width integer types which helps on handling binary data

class Editor { // Class declaration to modify binary data

    public: 
    static void editByte(std::vector<uint8_t>& data);
 
}; 