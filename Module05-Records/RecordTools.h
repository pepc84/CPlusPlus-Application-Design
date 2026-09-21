#ifndef RECORDTOOLS_H
#define RECORDTOOLS_H

#include <iostream>
#include <string>

using namespace std;

void displayRecords(
    int patientId[],
    int age[],
    string diabetesRisk[],
    int size
) {
    cout << "Diabetes Risk Dataset" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << "Patient ID: " << patientId[i]
             << " | Age: " << age[i]
             << " | Diabetes Risk: " << diabetesRisk[i]
             << endl;
    }
}

int countHighRisk(
    string diabetesRisk[],
    int size
) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (diabetesRisk[i] == "High") {
            count++;
        }
    }

    return count;
}

void addRecord() {
    int patientId;
    int age;
    string risk;

    cout << endl;
    cout << "Add a new record" << endl;

    cout << "Patient ID: ";
    cin >> patientId;

    cout << "Age: ";
    cin >> age;

    cout << "Diabetes Risk: ";
    cin >> risk;

    cout << "Record added: "
         << patientId << ", "
         << age << ", "
         << risk << endl;
}

#endif
