#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

string generate_password(int length) {
    
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

    string password = "";
    srand(time(0));  
    for (int i = 0; i < length; i++) {
        password += characters[rand() % characters.length()];
    }

    return password;
}

int main() {
    
    int length;
    cout << "Enter the desired password length: ";
    cin >> length;
    
    string password = generate_password(length);
    
    cout << "Password generated: " << password << endl;

    // copy to clipboard
    if (OpenClipboard(NULL)) {
        EmptyClipboard();
        HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, password.size() + 1);
        if (hg) {
            char* ch = (char*)GlobalLock(hg);
            memcpy(ch, password.c_str(), password.size() + 1);
            GlobalUnlock(hg);
            if (SetClipboardData(CF_TEXT, hg) == NULL) {
                cout << "Failed to copy password to clipboard." << endl;
            } else {
                cout << "Password has been copied to the clipboard." << endl;
            }
        } else {
            cout << "Failed to allocate memory." << endl;
        }
        CloseClipboard();
    } else {
        cout << "Failed to open clipboard." << endl;
    }

    cin.ignore(); //clean the buffer
    cin.get();
    return 0;
}
