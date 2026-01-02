#include "Crypto.hpp"
#include <Utils.hpp>
#include <iostream>
#include <string>

int main(int ac, char** av) {
    std::cout << "Welcome to the Encrypted Password Vault CLI!" << std::endl;

    if(ac != 4){
        std::cout << "Please Enter the key and value and method to encrypt it" << std::endl;
        std::cout << "example:" << std::endl;
        std::cout << "./password_vault Github  AJASD1234!@#$ ENC " << std::endl;
        return 1;
    }
    std::string key = av[1];
    std::string value = av[2];
    std::string method = av[3];
    std::string encrypted;
    std::string decrypted;
    const std::string vaultPath = "data/vault.dat";
    //check method
    if(method == "ENC")
        encrypted = Crypto::encrypt(value, key);
    else if(method == "DEC")
        decrypted = Crypto::decrypt(value, key);
    else
       return (std::cout << "Invalid method. Use ENC for encryption or DEC for decryption." << std::endl), 1;
    
    // CHECK IF FILE vault.dat EXISTS, IF NOT CREATE IT
    if(!Utils::createFile(vaultPath)){
        std::cout << "Error creating vault file." << std::endl;
        return 1;
    }
    // APPEND TO FILE
    if(method == "ENC"){
        if(!Utils::addToFile(vaultPath, key, encrypted)){
            std::cout << "Error appending to vault file." << std::endl;
            return 1;
        }
        std::cout << "Encrypted value stored successfully." << std::endl;
    }
    else{
        std::cout << key << " | " << decrypted << std::endl;
        std::cout << "Decrypted value displayed successfully." << std::endl;
    }
    return 0;
}