🔐 Multi-User Encrypted Password Vault (CLI) – C++
📌 Overview

This project is a command-line password vault written in C++ that supports multiple users with session-based access control.
Each user has a private encrypted storage space where passwords are securely stored and isolated from other users.

The project focuses on encryption fundamentals, file-based persistence, and session management, and was built as part of the 1337 (42 Network) Common Core learning path.

🎯 Project Goals

Design a multi-user system in a CLI environment

Implement session-based user access

Encrypt sensitive data before persistent storage

Ensure data isolation per user

Practice clean project architecture and responsibility separation

👤 User & Session Concept
What Is a User?

A user represents an individual with:

A unique username

A personal secret key used for encryption

Each user owns a private vault that cannot be accessed by others.

What Is a Session?

A session is an active logged-in state.

When a user logs in:

A session starts

All actions apply only to that user

Access to other users’ data is restricted

Logging out ends the session and clears access.

🔐 Functional Overview
User Management

Register a new user

Log in with existing credentials

Log out to end the session

Password Management (Per User)

While logged in, a user can:

Add a password (encrypted before storage)

Retrieve a stored password (decrypted in memory)

List stored services

Delete stored entries

🗂️ Data Storage Design

Each user has isolated persistent storage.

Example Layout
data/
├── users/
│   ├── ayoub.vault
│   ├── sara.vault
│   └── ali.vault


Each vault contains:

service_name | encrypted_password


Plain passwords are never written to disk.

🧱 Project Architecture (Conceptual)
Application Core
 ├── User Authentication
 ├── Session Management
 ├── Vault Management
 ├── Encryption Module
 └── File Storage System


Each component has a single responsibility to keep the system modular and maintainable.

🔒 Encryption Approach

Passwords are encrypted using a custom reversible encryption algorithm

The same user secret key is used for encryption and decryption

No hashing is used

No third-party cryptographic libraries are involved

⚠️ Encryption is implemented for educational purposes only.

📁 Project Structure
password_vault/
├── src/
│   ├── main.cpp          → program flow & CLI
│   ├── Vault.cpp         → user vault operations
│   ├── Session.cpp       → session handling
│   ├── Crypto.cpp        → encryption logic
│   └── Utils.cpp         → helper utilities
├── include/
│   ├── Vault.hpp
│   ├── Session.hpp
│   ├── Crypto.hpp
│   └── Utils.hpp
├── data/
│   └── users/            → encrypted user vaults
└── Makefile

🧠 Learning Objectives

Understand session lifecycle management

Learn how encrypted storage works

Practice file-based data persistence

Design a multi-user system

Improve C++ project organization

🚨 Security Disclaimer

This project is not intended for production use.
The encryption method is implemented for learning and demonstration purposes only.

📈 What This Project Demonstrates

Strong C++ fundamentals

Systems and architectural thinking

Awareness of security concepts

Clean CLI application design

Multi-user access control logic

👨‍💻 Author

Ayoub Adouay
Student at 1337 (42 Network)
Interested in systems programming, security, and low-level software design

🔗 LinkedIn Description (Short)

Developed a multi-user encrypted password vault in C++ with session-based access control and isolated user storage as part of the 1337 Common Core.