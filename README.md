## 🔐 Encrypted Password Vault CLI

Simple C++98 command‑line tool to store and retrieve passwords in a local encrypted vault file.

Passwords are encrypted with a key, obfuscated again with a short random serial ID, and then saved in data/vault.dat.

> ⚠️ Educational/demo project – do not use for real sensitive data.

---

## 🛠️ Build

Requirements:
- 🧱 Any C++ compiler with C++98 support
- 🧰 make

Build the main CLI:
```bash
make
```

This produces:
- ./password_vault – main vault program

Build the standalone decrypt helper in dec/:
```bash
cd dec
make
```

This produces:
- ./dec – helper that removes the serial‑ID layer only

---

## ⚙️ How It Works

When you encrypt, the program:
1. 🔑 Encrypts the password using key‑based shifts and string reversal (Crypto).
2. 🎲 Generates a 5‑character random serial ID (Utils::generateSerialIDs).
3. 🧪 Applies another simple cipher using that serial ID (Utils::encryption_algorithm).
4. 💾 Stores everything in data/vault.dat.

Vault format (example):
```text
KEY | ENCRYPTED_VALUE
----------------------
github | 8`uU?yB75(sID8`gV@
```

Here:
- 🔑 KEY: github
- 🔐 ENCRYPTED_VALUE: 8`uU?yB75(s – value encrypted twice
- 🆔 Serial ID: 8`gV@ – 5‑character ID after the literal text "ID"

---

## 🧾 Usage – Main Program

General form:
```bash
./password_vault <KEY> <VALUE> <METHOD>
```

- KEY: word that acts as the logical name for your password (and as encryption key).
- VALUE: password or encrypted value, depending on METHOD.
- METHOD:
  - `ENC` – 🔒 encrypt and store in data/vault.dat
  - `DEC` – 🔓 decrypt a value that has already had the serial‑ID layer removed

### 🔒 Encrypt and Store

```bash
./password_vault github "MySecretPass123!" ENC
```

Output:
- 📂 Creates data/vault.dat if it does not exist.
- ➕ Appends a line for the new entry.
- ✅ Prints: "Encrypted value stored successfully."

### 🔓 Decrypt (after removing serial layer)

The main program expects VALUE to already be decrypted from the serial ID layer.

Steps:
1. Take KEY and the encrypted+serial text from data/vault.dat.
2. Remove the serial‑ID layer with the helper dec program (see below).
3. Pass the result to password_vault with DEC.

Example outline:
```bash
./password_vault github <value_without_serial_layer> DEC
```

If everything is correct, it prints the original password.

---

## 🧩 Usage – dec Helper

The dec helper only reverses the serial‑ID layer used in Utils::encryption_algorithm.

From dec/:
```bash
./run_dec.sh '<ENCRYPTED_PART>' '<SERIAL_ID>'
```

Where both arguments are taken from a line in data/vault.dat.

Using the example line:
```text
github | 8`uU?yB75(sID8`gV@
```

- ENCRYPTED_PART: 8`uU?yB75(s
- SERIAL_ID: 8`gV@

- SERIAL_ID: 8`gV@
 
Run:
```bash
cd dec
./run_dec.sh '8`uU?yB75(s' '8`gV@'
```

This prints the decrypted value for that layer only. Use that output as VALUE with METHOD=DEC in password_vault:
```bash
./password_vault github '<output_from_dec>' DEC
```

Note for zsh users:
- Wrap values in single quotes when they contain backticks, ?, (, etc.

---

## 📁 Files

- 🧠 src/main.cpp – CLI handling, printing help, calling Crypto and Utils.
- 🔐 src/Crypto.cpp – key‑based encrypt/decrypt (first layer).
- 🛠️ src/Utils.cpp – vault file creation, appending entries, serial‑ID cipher, serial generation.
- 📑 include/Crypto.hpp, include/Utils.hpp – headers.
- 💾 data/vault.dat – created automatically on first run.
- 🧩 dec/dec.cpp – tiny tool to undo the serial‑ID cipher.
- 🤖 dec/run_dec.sh – script that builds and runs dec.

---

## 👤 Author

- 👨‍💻 Ayoub Adouay
- 🎓 Student at 1337 (42 Network)
- 🔍 Focused on systems programming and security‑oriented C++.
