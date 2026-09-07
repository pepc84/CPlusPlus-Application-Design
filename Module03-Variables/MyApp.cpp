#include <iostream>
#include <string>
using namespace std;

int main() {
    // Application information
    string userName = "pepc84";
    string applicationName = "My Record Manager";
    double version = 1.0;

    // Additional variables
    int recordCount = 0;
    char status = 'A';
    bool applicationActive = true;

    // Welcome screen
    cout << "==============================" << endl;
    cout << "     WELCOME TO MY APP" << endl;
    cout << "==============================" << endl;

    cout << "User: " << userName << endl;
    cout << "Application: " << applicationName << endl;
    cout << "Version: " << version << endl;
    cout << "Records: " << recordCount << endl;
    cout << "Status: " << status << endl;
    cout << "Active: " << applicationActive << endl;

    return 0;
}
