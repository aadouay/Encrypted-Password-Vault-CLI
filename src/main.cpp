#include "Crypto.hpp"
#include <Utils.hpp>
#include <Vault.hpp>
#include <iostream>

int main(int ac, char** av) {
    std::cout << "Welcome to the Encrypted Password Vault CLI!" << std::endl;

    if(ac != 4){
        std::cout << "Please Enter the key and value and method to encrypt it" << std::endl;
        std::cout << "example:" << std::endl;
        std::cout << "./password_vault Github  AJASD1234!@#$ ENC " << std::endl;
    }
    std::string key = av[1];
    std::string value = av[2];
    std::string method = av[3];
    std::string encrypted;
    std::string decrypted;
    //check method
    if(method == "ENC")
        encrypted = Crypto::encrypt(value, key);
    else if(method == "DEC")
        decrypted = Crypto::decrypt(value, key);
    else
       return (std::cout << "Invalid method. Use ENC for encryption or DEC for decryption." << std::endl), 1;
    // create and store in the vault.dat file

    return 0;
}