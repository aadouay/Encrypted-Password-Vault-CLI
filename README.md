🔐 Single-User Encrypted Password Vault (CLI) – C++
📌 Overview

This project is a command-line password vault written in C++ for a single local user.
It allows the user to securely store, retrieve, and manage passwords by encrypting them before saving to a file and decrypting them only when needed.

The project focuses on encryption fundamentals, file-based persistence, and clean program structure, and was developed as part of the 1337 (42 Network) Common Core learning path.

🎯 Project Goals

Understand how encrypted storage works

Learn how to safely store sensitive data in files

Practice structuring a real CLI application in C++

Apply separation of responsibilities (logic, encryption, storage)

Build a simple but realistic security-oriented project

🧠 Core Concept

The application is designed for one trusted user

All passwords are:

Encrypted before being written to disk

Stored in a local file

Decrypted only in memory when accessed

Plain-text passwords are never stored

There is no multi-user system and no sessions, keeping the project simple and focused.

⚙️ Functional Overview
Password Management

The user can:

Add a new password for a service

Retrieve a stored password

List all stored services

Delete a password entry

Encryption

Passwords are encrypted using a custom reversible encryption method

The same secret key is used for encryption and decryption

No hashing is used

No third-party cryptographic libraries are involved

⚠️ The encryption logic is implemented for educational purposes only.

🗂️ Data Storage

Encrypted data is stored locally in a file.

Example storage format:

github | <encrypted_password>
email  | <encrypted_password>


The vault file never contains readable passwords

Decryption happens only at runtime

🧱 Project Architecture (Conceptual)
Application
 ├── CLI Interface
 ├── Vault Manager
 ├── Encryption Module
 └── File Storage System


Each component has a single responsibility, making the project easier to understand and maintain.

📁 Project Structure
password_vault/
├── src/
│   ├── main.cpp          → program flow & CLI
│   ├── Vault.cpp         → password management
│   ├── Crypto.cpp        → encryption logic
│   └── Utils.cpp         → helper utilities
├── include/
│   ├── Vault.hpp
│   ├── Crypto.hpp
│   └── Utils.hpp
├── data/
│   └── vault.dat         → encrypted password storage
└── Makefile

🧠 Learning Objectives

Understand reversible encryption concepts

Learn how to protect data at rest

Practice file I/O in C++

Improve project organization and design

Build a real-world CLI utility

🚨 Security Disclaimer

This project is not intended for production use.
The encryption method is implemented strictly for learning and demonstration purposes.

📈 What This Project Demonstrates

Solid C++ fundamentals

Clean project structure

Awareness of security concepts

Ability to design practical CLI tools

Clear and honest technical thinking

👨‍💻 Author

Ayoub Adouay
Student at 1337 (42 Network)
Interested in systems programming, security, and low-level software design