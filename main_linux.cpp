#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <cstring>

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
    string command = "echo \"" + password + "\" | xclip -selection clipboard";
    int result = system(command.c_str());
    if (result != 0) {
        cerr << "Failed to copy password to clipboard." << endl;
        return 1;
    } else {
        cout << "Password has been copied to the clipboard." << endl;
    }

    cin.ignore();
    return 0;
}
