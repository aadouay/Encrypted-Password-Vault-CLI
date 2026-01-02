#include "Utils.hpp"

bool Utils::createFile(const std::string& filename) {
    std::ofstream file(filename.c_str());
    if (!file) {
        return false;
    }
    file.close();
    return true;
}

bool Utils::appendToFile(const std::string& file_name, const std::string& key, const std::string& encrypted_value){
    
}
