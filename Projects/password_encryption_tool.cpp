#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt a password using Caesar cipher
string encrypt(const string& password, int shift) {
    string encrypted = password;
    for (char& c : encrypted) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + shift) % 26 + base;
        }
    }
    return encrypted;
}

// Function to decrypt a password using Caesar cipher
string decrypt(const string& encryptedPassword, int shift) {
    string decrypted = encryptedPassword;
    for (char& c : decrypted) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base - shift + 26) % 26 + base;
        }
    }
    return decrypted;
}

// Function to save encrypted password to a file
void saveEncryptedPassword(const string& filename, const string& encryptedPassword) {
    ofstream file(filename);
    if (file.is_open()) {
        file << encryptedPassword;
        file.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to load encrypted password from a file
string loadEncryptedPassword(const string& filename) {
    ifstream file(filename);
    string encryptedPassword;
    if (file.is_open()) {
        getline(file, encryptedPassword);
        file.close();
    } else {
        cout << "Unable to open file for reading." << endl;
    }
    return encryptedPassword;
}

int main() {
    cout << "Password Encryption Tool" << endl;

    while (true) {
        cout << "1. Encrypt Password" << endl;
        cout << "2. Decrypt Password" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 3) {
            break;
        }

        string password;
        int shift;
        string filename = "encrypted_password.txt";

        switch (choice) {
            case 1: {
                cout << "Enter password to encrypt: ";
                cin.ignore();
                getline(cin, password);
                cout << "Enter shift value (e.g., 3 for Caesar cipher): ";
                cin >> shift;

                string encryptedPassword = encrypt(password, shift);
                saveEncryptedPassword(filename, encryptedPassword);

                cout << "Encrypted password saved to " << filename << endl;
                break;
            }
            case 2: {
                cout << "Enter shift value used for encryption: ";
                cin >> shift;

                string encryptedPassword = loadEncryptedPassword(filename);
                if (encryptedPassword.empty()) {
                    cout << "No encrypted password found." << endl;
                    break;
                }

                string decryptedPassword = decrypt(encryptedPassword, shift);
                cout << "Decrypted password: " << decryptedPassword << endl;
                break;
            }
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    }

    return 0;
}
