#include <iostream>
#include <string>
#include "RecordTools.h"

using namespace std;

int main() {
    int patientId[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int age[9] = {
        47, 53, 47, 41, 57, 58, 42, 42, 57
    };

    string diabetesRisk[9] = {
        "Low",
        "Low",
        "High",
        "Low",
        "Low",
        "Low",
        "Moderate",
        "High",
        "Moderate"
    };

    displayRecords(patientId, age, diabetesRisk, 9);

    int highRiskCount = countHighRisk(diabetesRisk, 9);

    cout << endl;
    cout << "Number of high risk patients: "
         << highRiskCount << endl;

    addRecord();

    return 0;
}
