#include <iostream>
#include <fstream>
using namespace std;

#ifndef LOGINPROGRAM_LOGINMANAGER_H
#define LOGINPROGRAM_LOGINMANAGER_H


class loginManager {
public:
    loginManager();
    void login();
    string getFile(const char* p_fileName);
    void saveFile(string p_line, const char* p_fileName);

    int encrypt(int p_letter);
    int decrypt(int p_letter);

private:
    string userNameAttempt;
    string passWordAttempt;
    string passWord;        //Grapejuice
    string userName;        //user@email.com
    bool AccessGranted;
};


#endif //LOGINPROGRAM_LOGINMANAGER_H
