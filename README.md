🔐 Secure Password Manager (CLI) – C++
📌 Overview

This project is a command-line password manager developed in C++, designed to securely store, retrieve, and manage passwords locally.
It uses a master password, hashing, and basic encryption to protect sensitive data and demonstrates fundamental security and system programming concepts.

This project was built as part of my learning journey in the 1337 (42 Network) Common Core.

🎯 Project Goals

Understand how password managers work internally

Practice secure data storage principles

Apply Object-Oriented Programming (OOP) in C++

Work with file persistence and error handling

Build a real-world CLI application from scratch

⚙️ Features

🔑 Master password authentication

🔒 Encrypted storage of passwords (no plain text)

➕ Add new password entries

📋 List stored services

🔍 Retrieve a password for a specific service

🗑️ Delete a password entry

💾 Persistent storage using encrypted files

🛠️ Technologies & Concepts Used

Language: C++

Programming Paradigm: Object-Oriented Programming

Concepts:

File I/O

Hashing & basic encryption

Input validation

Error handling

Memory management

Tools: Git, Makefile, Linux CLI

🧠 Architecture (Simplified)

/src
 ├── main.cpp
 ├── Vault.cpp / Vault.hpp
 ├── PasswordEntry.cpp / PasswordEntry.hpp
 ├── Crypto.cpp / Crypto.hpp
 └── Utils.cpp / Utils.hpp

▶️ How to Use
make
./password_manager


Example commands:

add github
get github
list
delete github

🚨 Security Notes

This project is educational and not intended for production use

Encryption is implemented for learning purposes

No third-party crypto libraries are used to better understand the fundamentals

📈 What This Project Demonstrates

Strong understanding of C++ fundamentals

Awareness of security best practices

Ability to design and structure a complete project

Experience building real-world CLI tools

👨‍💻 Author

Ayoub Adouay
Student at 1337 (42 Network)
Passionate about systems programming, security, and low-level development

🔗 GitHub: (...)
🔗 LinkedIn: (...)
