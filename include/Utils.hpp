#pragma once
#include <string>
#include <fstream>

class Utils {
    public:
        static bool addToFile(const std::string& file_name, const std::string& key, const std::string& encrypted_value);
        static bool createFile(const std::string& filename);
};