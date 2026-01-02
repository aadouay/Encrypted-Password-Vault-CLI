#include "Utils.hpp"

bool Utils::createFile(const std::string& filename) {
    std::ofstream file(filename.c_str(), std::ios::app);
    if (!file) {
        return false;
    }
    file.close();
    return true;
}

bool Utils::addToFile(const std::string& file_name, const std::string& key, const std::string& encrypted_value){
    std::ofstream file(file_name.c_str(), std::ios::app);
    if(!file.is_open())
        return false;
    // check if file is empty to write header
    std::ifstream check(file_name.c_str());
    if (check.peek() == std::ifstream::traits_type::eof()) {
        file << "KEY | ENCRYPTED_VALUE" << std::endl;
        file << "----------------------" << std::endl;
    }
    check.close();
    // add new line for the new entry
    file << key << " | " << encrypted_value << std::endl;
    return true;
}
