#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Handles admin-only menu access
void adminAction(string role) {
    if (role != "admin") {
        cout << "WOAH THERE BUDDY! ADMIN ONLY!\n";
    }
    else {
        cout << "Welcome to the ADMIN menu.\n";
    }
}

// Handles user menu access for users and admins
void userAction(string role) {
    if (role == "user" || role == "admin") {
        cout << "Welcome to the USER menu.\n";
    }
}

// Number of positions each letter is shifted in the cipher
const int SHIFT = 3;

// Encrypts a message by shifting letters forward
string encryptMessage(string text) {
    for (int i = 0; i < (int)text.length(); i++) {
        char c = text[i];

        if (isalpha(static_cast<unsigned char>(c))) {
            char base = islower(static_cast<unsigned char>(c)) ? 'a' : 'A';
            c = (c - base + SHIFT) % 26 + base;
        }

        text[i] = c;
    }

    return text;
}

// Decrypts a message by shifting letters backward
string decryptMessage(string text) {
    for (int i = 0; i < (int)text.length(); i++) {
        char c = text[i];

        if (isalpha(static_cast<unsigned char>(c))) {
            char base = islower(static_cast<unsigned char>(c)) ? 'a' : 'A';
            c = (c - base - SHIFT + 26) % 26 + base;
        }

        text[i] = c;
    }

    return text;
}

// Displays the encryption/decryption menu
void cryptoMenu() {
    int option;
    string message;

    while (true) {
        cout << "\n--- Message Encryption Menu ---\n";
        cout << "1) Encrypt Message\n";
        cout << "2) Decrypt Message\n";
        cout << "3) Back\n";
        cout << "Choice: ";

        cin >> option;
        cin.ignore();

        if (option == 1) {
            cout << "Enter message to encrypt: ";
            getline(cin, message);

            string encrypted = encryptMessage(message);
            cout << "Encrypted Message: " << encrypted << endl;
        }
        else if (option == 2) {
            cout << "Enter message to decrypt: ";
            getline(cin, message);

            string decrypted = decryptMessage(message);
            cout << "Decrypted Message: " << decrypted << endl;
        }
        else if (option == 3) {
            break;
        }
        else {
            cout << "WRONG.\n";
        }
    }
}

// Program entry point and login/menu controller
int main() {
    string username;
    string password;
    string role;
    int choice;

    cout << "CIA Log In Screen\n";

    while (true) {
        cout << "Enter username (or type exit): ";
        getline(cin, username);

        if (username == "exit") {
            cout << "Later!\n";
            break;
        }

        cout << "Enter password: ";
        getline(cin, password);

        // Checks username and password to assign roles
        if (username == "Chubbs" && password == "12345") {
            role = "admin";
        }
        else if (username == "Cook" && password == "12354") {
            role = "user";
        }
        else if (username == "Norm" && password == "12354") {
            role = "user";
        }
        else {
            cout << "HACKER DETECTED! RELEASE THE HOUNDS!\n\n";
            continue;
        }

        cout << "Welcome Agent. Your role is: " << role << endl;

        bool loggedIn = true;

        // Runs the main menu until the user logs out
        while (loggedIn) {
            cout << "\nChoose an option:\n";
            cout << "1) Admin Menu\n";
            cout << "2) User Menu\n";
            cout << "3) Encrypt / Decrypt Message\n";
            cout << "4) Logout\n";
            cout << "Enter choice: ";

            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                adminAction(role);
            }
            else if (choice == 2) {
                userAction(role);
            }
            else if (choice == 3) {
                if (role == "user" || role == "admin") {
                    cryptoMenu();
                }
            }
            else if (choice == 4) {
                cout << "Have a good day Sweetie!\n\n";
                loggedIn = false;
            }
            else {
                cout << "WRONG.\n";
            }
        }
    }

    return 0;
}
