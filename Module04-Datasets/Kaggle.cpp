
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    // Data selected from the Kaggle air quality dataset
    double pm25[9];
    double co2[9];
    double temperature[9];

    ifstream file("air_quality_dataset.csv");
    string line;
    string value;

    if (!file.is_open()) {
        cout << "Error opening CSV file." << endl;
        return 1;
    }

    // Extract the records from the CSV
    getline(file, line);

    for (int i = 0; i < 9; i++) {
        getline(file, line);
        stringstream ss(line);

        for (int j = 0; j < 10; j++) {
            getline(ss, value, ',');

            if (j == 0) {
                pm25[i] = stod(value);
            }
            else if (j == 7) {
                co2[i] = stod(value);
            }
            else if (j == 9) {
                temperature[i] = stod(value);
            }
        }
    }

    file.close();

    // Display the records
    cout << "Air Quality Dataset" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 9; i++) {
        cout << "PM2.5: " << pm25[i]
             << " | CO2: " << co2[i]
             << " | Temperature: " << temperature[i]
             << endl;
    }

    // Access the first CO2 value through a pointer
    double *co2Ptr = &co2[0];

    cout << endl;
    cout << "First record's CO2 through pointer: "
         << *co2Ptr << endl;

    return 0;
}
