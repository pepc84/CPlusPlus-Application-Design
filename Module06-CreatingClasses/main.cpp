#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double salary;

public:
    Employee(string employeeName, int employeeId, double employeeSalary) {
        name = employeeName;
        id = employeeId;
        salary = employeeSalary;
    }

    void displayEmployee() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: $" << salary << endl;
    }

    string getName() {
        return name;
    }

    void setSalary(double newSalary) {
        salary = newSalary;
    }
};

int main() {
    Employee employee1("Marcus Bennett", 1001, 55000);
    Employee employee2("Emily Carter", 1002, 62000);

    employee1.displayEmployee();
    cout << endl;
    employee2.displayEmployee();

    return 0;
}
