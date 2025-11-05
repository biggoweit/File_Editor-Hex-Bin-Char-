#pragma once // Prevents the header from being included multiple times

#include <string> // Allows using string class to handle filenames
#include <vector> // Allows the use of the vector class (dynamic array) 
#include <cstdint> // Helps on handling binary data


//Class to manage file loading and saving 
class FileManager { 

public:
    static bool loadFile(const std::string& filename, std::vector<uint8_t>& data);

    static bool saveFile(const std::string& filename, const std::vector<uint8_t>& data);

}; 