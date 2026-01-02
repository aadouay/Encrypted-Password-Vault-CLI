#pragma once

#include <string>
#include <memory>
#include <map>
#include <vector>

class Crypto {
    public:
        static std::string encrypt(const std::string& data, const std::string& key);
        static std::string decrypt(const std::string& encryptedData, const std::string& key);
        
};
