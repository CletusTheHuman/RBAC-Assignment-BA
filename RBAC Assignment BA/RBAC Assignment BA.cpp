#include <iostream>
#include <string>

using namespace std;

void adminAction(string role) {
    if (role != "admin") {
        cout << "WOAH THERE BUDDY! ADMIN ONLY!\n";
    }
    else {
        cout << "Welcome to the ADMIN menu.\n";
    }
}

// Admin is allowed to access user features
void userAction(string role) {
    if (role == "user" || role == "admin") {
        cout << "Welcome to the USER menu.\n";
    }
}

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

        // Login check with username and password
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

        while (loggedIn) {

            cout << "\nChoose an option:\n";
            cout << "1) Admin Menu\n";
            cout << "2) User Menu\n";
            cout << "3) Logout\n";
            cout << "Enter choice: ";
            cin >> choice;

            cin.ignore(); // clears leftover enter key

            if (choice == 1) {
                adminAction(role);
            }
            else if (choice == 2) {
                userAction(role);
            }
            else if (choice == 3) {
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
