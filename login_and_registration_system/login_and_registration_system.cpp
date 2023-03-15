#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct User {
    string username;
    string email;
    string password;
};

// Function to check if a username already exists in the system
bool doesUserExist(string username) {
    ifstream userFile(username + ".txt");
    return userFile.good();
}

// Function to register a new user
void registerUser() {
    User newUser;
    cout << "Enter a username: ";
    cin >> newUser.username;
    if (doesUserExist(newUser.username)) {
        cout << "Error: That username already exists.\n";
        return;
    }
    cout << "Enter a password: ";
    cin >> newUser.password;
    ofstream userFile(newUser.username + ".txt");
    userFile << newUser.username << "\n" << newUser.password << "\n";
    cout << "User registration successful.\n";
}

// Function to log in a user
void loginUser() {
    User existingUser;
    cout << "Enter your username: ";
    cin >> existingUser.username;
    if (!doesUserExist(existingUser.username)) {
        cout << "Error: That username does not exist.\n";
        return;
    }
    cout << "Enter your password: ";
    cin >> existingUser.password;
    ifstream userFile(existingUser.username + ".txt");
    string storedUsername, storedPassword;
    getline(userFile, storedUsername);
    getline(userFile, storedPassword);
    if (existingUser.password != storedPassword) {
        cout << "Error: Incorrect password.\n";
        return;
    }
    cout << "Login successful. Welcome, " << existingUser.username << "!\n";
}

int main() {
    char choice;
    do {
        cout << "User Authentication System\n";
        cout << "--------------------------\n";
        cout << "1. Register new user\n";
        cout << "2. Login\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                registerUser();
                break;
            case '2':
                loginUser();
                break;
            case '3':
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != '3');
    return 0;
}
