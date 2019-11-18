#include <iostream>
#include <fstream>
#include "loginManager.h"
using namespace std;

loginManager::loginManager() {
    AccessGranted = false;
}

// User Log in
void loginManager::login() {
    cout << "Please Enter your Username and Password" << endl;
    cout << "Username: ";
    cin >> userNameAttempt;

    userName = getFile("/Users/daviddang/Documents/LoginProgram/users.dat");

    if (userNameAttempt == userName) {
        cout << "Password: ";
        cin >> passWordAttempt;

        passWord = getFile("/Users/daviddang/Documents/LoginProgram/pswds.dat");

        if (passWordAttempt == passWord) {
            cout << "\nWelcome Back!";
            cin.get();
        }
        else {
            cout << "\nYour Username or Password is incorrect, please try again." << endl;
            login();
        }
    }
    else {
        cout << "\nYour Username or Password is incorrect, please try again." << endl;
        login();
    }
}

string loginManager::getFile(const char* p_fileName) {
    string line;
    fstream file;

    int encryptedChar;

    file.open(p_fileName, ios::in);
    while(1) {
        file >> encryptedChar;
        if(encryptedChar == 0) {
            file.close();
            return line;
        }
        line += (char)decrypt(encryptedChar);
    }
}

void loginManager::saveFile(string p_line, const char* p_fileName) {
    fstream file;
    file.open(p_fileName, ios::out);

    for(int i = 0; i < p_line.length(); i++) {
        file << encrypt(p_line[i]);
        file << "\n";
    }

    file << "0";
    file.close();
}

//encryption
int loginManager::encrypt(int p_letter) {
    return p_letter + 3;
}

int loginManager::decrypt(int p_letter) {
    return p_letter - 3;
}