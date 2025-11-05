#include "file_manager.hpp" 

#include <fstream> // for file stream operations (reading/writing files)

// Loads the file
bool FileManager::loadFile(const std::string& filename, std::vector<uint8_t>& data) { 
    std::ifstream file(filename, std::ios::binary);

    if (!file) { 
        return false; 
    }

    // Get file size to make sure the file is read correctly
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    data.resize(fileSize);
    file.read(reinterpret_cast<char*>(data.data()), fileSize);

    return true; 
}

// Saves the modifications on the file
bool FileManager::saveFile(const std::string& filename, const std::vector<uint8_t>& data) { 
    std::ofstream file(filename, std::ios::binary);

    if (!file) { 
        return false; 
    }

    // Write the data on the file
    file.write(reinterpret_cast<const char*>(data.data()), data.size()); 

    return true;
}