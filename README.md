Encrypted Password Vault CLI

A simple C++ command-line tool to securely store and retrieve encrypted passwords.

📌 Project Overview

The Encrypted Password Vault CLI allows a user to:

Encrypt passwords using a custom, printable-character-based algorithm.

Store encrypted passwords in a local file (vault.dat).

Decrypt stored passwords for retrieval.

Support multiple entries safely, keeping previous data intact.

This tool is designed as a learning project in C++, ideal for practicing:

File I/O (fstream)

String manipulation

Custom encryption algorithms

CLI argument handling

⚡ Features

Encrypt passwords with a key

Decrypt passwords using the same key

Automatically creates a vault file if it does not exist

Stores passwords in a structured, readable format

Handles multiple entries without overwriting existing data

Ensures all encrypted characters are printable for safe storage

🛠️ Installation / Build
git clone <your-repo-url>
cd Encrypted-Password-Vault-CLI
make


This will compile the project and generate the executable:

./password_vault

💻 Usage
1️⃣ Encrypt and store a password
./password_vault <KEY> <PASSWORD> ENC


Example:

./password_vault Github AJASD1234!@#$ ENC


KEY → User-defined key for encryption

PASSWORD → The password you want to store securely

ENC → Method to encrypt the password

✅ Output:

Encrypted value stored successfully.


The encrypted password is stored in data/vault.dat.

2️⃣ Decrypt a password
./password_vault <KEY> <ENCRYPTED_PASSWORD> DEC


Example:

./password_vault Github <encrypted_value_here> DEC


KEY → The same key used during encryption

DEC → Method to decrypt the password

✅ Output:

Github | AJASD1234!@#
Decrypted value displayed successfully.

📂 File Structure
Encrypted-Password-Vault-CLI/
│
├─ src/
│   ├─ main.cpp          # CLI interface
│   ├─ Crypto.cpp        # Encryption/Decryption functions
│   ├─ Utils.cpp         # File handling utilities
│
├─ include/
│   ├─ Crypto.hpp
│   ├─ Utils.hpp
│
├─ data/
│   └─ vault.dat         # Password vault file (created automatically)
│
├─ Makefile
└─ README.md

🔐 Encryption Details

Custom printable-character-based encryption

Uses key-based shifting and reversal

Keeps encrypted characters within the printable ASCII range (32–126)

Safe for storing in a text file

Symmetric: the same key must be used to encrypt and decrypt

⚙️ Notes / Tips

Always remember your key, it is required for decryption

Each entry in vault.dat is stored in the format:

KEY | ENCRYPTED_VALUE


Adding a new password appends to the file, keeping old passwords intact

🎯 Goals / Learning Outcomes

This project demonstrates:

Handling CLI arguments in C++

Reading/writing to files with fstream

Building custom encryption algorithms

Structuring a secure password vault for a single user

📈 Next Steps / Improvements

Add multi-user support with separate vaults

Implement double encryption for higher security

Add password retrieval by key without requiring the encrypted value on CLI

Add unit tests to ensure encryption/decryption correctness

👨‍💻 Author

Ayoub Adouay
Student at 1337 (42 Network)
Interested in systems programming, security, and low-level software design


📝 License

This project is open-source and educational. Free to use and modify.