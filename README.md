# 🔐 Encrypted Password Vault CLI

> A secure C++ command-line tool for storing and retrieving encrypted passwords with multi-layer encryption

---

## 📌 Project Overview

The **Encrypted Password Vault CLI** is a robust password management system that implements a multi-layered encryption approach to securely store passwords locally. It combines custom encryption algorithms with serial ID-based obfuscation for enhanced security.

### 🎯 Key Capabilities

- 🔒 **Multi-Layer Encryption**: Uses custom shift-based cipher with additional obfuscation
- 🆔 **Serial ID Generation**: Each encrypted password gets a unique serial identifier
- 💾 **Persistent Storage**: Automatically creates and manages a vault file (`data/vault.dat`)
- 🔑 **Key-Based Security**: Encrypt/decrypt using user-defined keys
- 📝 **Multiple Entries**: Safely stores multiple passwords without data loss
- ✅ **Printable Characters**: Ensures all encrypted data is safely printable (ASCII 32-126)

---

## ⚡ Features

| Feature | Description |
|---------|-------------|
| 🔐 **Dual-Shift Encryption** | Uses first and last character of key for two-pass encryption |
| 🔄 **String Reversal** | Adds an extra layer by reversing the encrypted string |
| 🎲 **Random Serial IDs** | Generates 5-character random serial for additional obfuscation |
| 📊 **Structured Storage** | Organized vault file with headers and formatted entries |
| 🛡️ **Custom Algorithm** | Additional encryption layer using serial ID and position-based math |

---

## 🛠️ Installation / Build

### Prerequisites
- C++ compiler with C++98 support
- Make utility

### Build Steps

```bash
# Clone the repository
git clone <your-repo-url>
cd Encrypted-Password-Vault-CLI

# Build the project
make

# Run the executable
./password_vault
```

---

## 💻 Usage

### 1️⃣ Encrypt and Store a Password

```bash
./password_vault <KEY> <PASSWORD> ENC
```

**Example:**
```bash
./password_vault Github "MySecretPass123!" ENC
```

**Parameters:**
- `KEY` → Your encryption key (used for decryption later)
- `PASSWORD` → The password you want to store securely
- `ENC` → Encryption mode

**✅ Output:**
```
Encrypted value stored successfully.
```

The encrypted password is stored in [data/vault.dat](data/vault.dat) with a unique serial ID.

---

### 2️⃣ Decrypt a Password

```bash
./password_vault <KEY> <ENCRYPTED_VALUE> DEC
```

**Example:**
```bash
./password_vault Github "xY9#mP..." DEC
```

**Parameters:**
- `KEY` → The same key used during encryption
- `ENCRYPTED_VALUE` → The encrypted string from the vault
- `DEC` → Decryption mode

**⚠️ Important:** Before decrypting, you need to:
1. Extract the serial ID from the vault file
2. Use your custom decryption function with the serial ID
3. Then run the DEC command with the properly prepared encrypted value

---

## 📂 Project Structure

```
Encrypted-Password-Vault-CLI/
│
├── 📁 src/
│   ├── main.cpp          # 🖥️  CLI interface and argument handling
│   ├── Crypto.cpp        # 🔐 Core encryption/decryption algorithms
│   └── Utils.cpp         # 🛠️  File I/O and utility functions
│
├── 📁 include/
│   ├── Crypto.hpp        # 🔐 Encryption/decryption class declarations
│   └── Utils.hpp         # 🛠️  Utility functions declarations
│
├── 📁 data/
│   └── vault.dat         # 💾 Password vault (auto-created)
│
├── Makefile              # 🔨 Build configuration
└── README.md             # 📖 This file
```

---

## 🔐 Encryption Algorithm Explained

### Layer 1: Dual-Shift Cipher
```
1. Extract key_shift1 from first character of key
2. Extract key_shift2 from last character of key
3. Apply first shift to all characters
4. Apply second shift to the result
5. Reverse the entire string
```

### Layer 2: Serial ID Obfuscation
```
For each character at position i:
  - Convert to 0-94 range (printable chars)
  - Calculate dynamic key: k = (serial_ID[i] + i * 31) % 95
  - Apply formula: e = ((c + k) * (c + k)) % 95
  - Convert back to printable ASCII
```

**Key Features:**
- 🔄 **Reversible**: Same key decrypts the data
- 📊 **Printable**: All output characters are ASCII 32-126
- 🎲 **Position-Based**: Each character position affects encryption
- 🆔 **Serial-Dependent**: Unique serial ID adds extra security layer

---

## 📊 Vault File Format

The `data/vault.dat` file stores entries in the following format:

```
KEY | ENCRYPTED_VALUE
----------------------
Github | xY9#mP...ID7k@2n
Facebook | aB3$qZ...ID9m!5x
Email | pQ1&rT...ID2c#8w
```

Each line contains:
- **Key**: Your identifier for the password
- **Encrypted Value**: The encrypted password
- **Serial ID**: Appended with "ID" prefix (e.g., `ID7k@2n`)

---

## 🔧 Function Reference

### Crypto Class

#### `encrypt(data, key)`
Encrypts a password using dual-shift cipher and string reversal.

**Parameters:**
- `data` (string): The password to encrypt
- `key` (string): The encryption key

**Returns:** Encrypted string with printable characters only

**Algorithm:**
1. Apply first shift based on key[0]
2. Apply second shift based on key[last]
3. Reverse the string

---

#### `decrypt(encryptedData, key)`
Decrypts a password (requires pre-processing with serial ID).

**Parameters:**
- `encryptedData` (string): The encrypted password
- `key` (string): The same key used for encryption

**Returns:** Decrypted password

**Note:** ⚠️ User must apply custom serial ID decryption before using this function

---

### Utils Class

#### `createFile(filename)`
Creates a file if it doesn't exist.

**Parameters:**
- `filename` (string): Path to the file

**Returns:** `true` if successful, `false` otherwise

---

#### `addToFile(filename, key, encryptedValue, serialID)`
Appends an encrypted password entry to the vault.

**Parameters:**
- `filename` (string): Vault file path
- `key` (string): Password identifier
- `encryptedValue` (string): The encrypted password
- `serialID` (string): Generated serial identifier

**Returns:** `true` if successful, `false` otherwise

**Features:**
- Auto-creates header if file is empty
- Formats entry with key, encrypted value, and serial ID

---

#### `encreption_algorithm(value, serialID)`
Applies an additional encryption layer using serial ID.

**Parameters:**
- `value` (string): Already encrypted password
- `serialID` (string): Random serial identifier

**Returns:** Double-encrypted password string

**Algorithm:**
- Uses position-based mathematical transformation
- Incorporates serial ID for unique obfuscation
- Ensures output remains in printable ASCII range

---

#### `generateSerialIDs(length)`
Generates a random serial identifier.

**Parameters:**
- `length` (size_t): Number of characters (default: 5)

**Returns:** Random string of printable ASCII characters

---

## ⚙️ Makefile Targets

| Target | Description | Emoji |
|--------|-------------|-------|
| `make` or `make all` | Build the executable | ✨ |
| `make clean` | Remove object files | 🧹 |
| `make fclean` | Remove all generated files | 🗑️ |
| `make re` | Rebuild from scratch | 🔄 |

---

## 🎯 Educational Goals

This project is excellent for learning:

- ✅ **File I/O Operations** - Using `fstream` for persistent storage
- ✅ **String Manipulation** - Character shifting, reversal, and transformation
- ✅ **Custom Algorithms** - Building encryption from scratch
- ✅ **CLI Argument Handling** - Processing command-line inputs
- ✅ **C++98 Standard** - Writing portable, standards-compliant code
- ✅ **Memory Management** - Working with strings and vectors
- ✅ **Modular Design** - Separating concerns into classes

---

## ⚠️ Security Notice

> **Important:** This is an educational project demonstrating basic encryption concepts. For production use, always rely on industry-standard encryption libraries like OpenSSL, libsodium, or similar.

**Current Limitations:**
- Custom encryption algorithm (not cryptographically secure)
- Serial ID decryption requires external implementation
- No password hashing for the encryption key
- Vault file is not encrypted at rest

---

## 🚀 Future Enhancements

- [ ] Implement AES-256 encryption
- [ ] Add password hashing (SHA-256, bcrypt)
- [ ] Support for password searching by key
- [ ] Delete/update existing entries
- [ ] Master password for vault access
- [ ] Export/import functionality
- [ ] Automatic serial ID decryption integration

---

## 📝 License

This project is open source and available for educational purposes.

---

## 👨‍💻 Author

Created as a C++ learning project focusing on encryption, file I/O, and CLI development.

---

**Happy Coding! 🔐✨**

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