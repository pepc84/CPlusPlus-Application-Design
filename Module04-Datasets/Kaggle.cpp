
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Data selected from the Kaggle diabetes risk dataset
    int patientId[9] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9
    };

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

    // Display the records
    cout << "Diabetes Risk Dataset" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 9; i++) {
        cout << "Patient ID: " << patientId[i]
             << " | Age: " << age[i]
             << " | Diabetes Risk: " << diabetesRisk[i]
             << endl;
    }

    // Access the first age value through a pointer
    int *agePtr = &age[0];

    cout << endl;
    cout << "First patient's age through pointer: "
         << *agePtr << endl;

    return 0;
}
