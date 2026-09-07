#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

vector<string> records;

void addRecord() {
    string name;

    cout << "\nEnter the name of the record: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    records.push_back(name);

    cout << "Record added successfully!" << endl;
}

void viewRecords() {
    cout << "\n=== RECORDS ===" << endl;

    if (records.empty()) {
        cout << "No records found." << endl;
        return;
    }

    for (int i = 0; i < records.size(); i++) {
        cout << i + 1 << ". " << records[i] << endl;
    }
}

void searchRecords() {
    string search;

    cout << "\nEnter a name to search for: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, search);

    bool found = false;

    for (string record : records) {
        if (record == search) {
            cout << "Found: " << record << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Record not found." << endl;
    }
}

void editRecord() {
    if (records.empty()) {
        cout << "\nNo records to edit." << endl;
        return;
    }

    viewRecords();

    int number;

    cout << "\nEnter the record number to edit: ";
    cin >> number;

    if (cin.fail()) {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (number < 1 || number > records.size()) {
        cout << "Invalid record number." << endl;
        return;
    }

    string newName;

    cout << "Enter the new name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newName);

    records[number - 1] = newName;

    cout << "Record updated successfully!" << endl;
}

void deleteRecord() {
    if (records.empty()) {
        cout << "\nNo records to delete." << endl;
        return;
    }

    viewRecords();

    int number;

    cout << "\nEnter the record number to delete: ";
    cin >> number;

    if (cin.fail()) {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (number < 1 || number > records.size()) {
        cout << "Invalid record number." << endl;
        return;
    }

    records.erase(records.begin() + (number - 1));

    cout << "Record deleted successfully!" << endl;
}

int main() {
    int choice = 0;

    while (choice != 6) {
        cout << "\n=== MY APPLICATION ===" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. View Records" << endl;
        cout << "3. Search" << endl;
        cout << "4. Edit Record" << endl;
        cout << "5. Delete Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";

        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addRecord();
                break;

            case 2:
                viewRecords();
                break;

            case 3:
                searchRecords();
                break;

            case 4:
                editRecord();
                break;

            case 5:
                deleteRecord();
                break;

            case 6:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
