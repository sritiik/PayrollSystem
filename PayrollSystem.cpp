#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int id;
    double hourlyRate;
    int hoursWorked;
public:
    Employee(string name, int id, double hourlyRate) : name(name), id(id), hourlyRate(hourlyRate), hoursWorked(0) {}

    int getId() const {
        return id;
    }

    void setHoursWorked(int hours) {
        hoursWorked = hours;
    }

    double calculateSalary() const {
        return hoursWorked * hourlyRate;
    }

    void displayDetails() const {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Total Salary: $" << calculateSalary() << endl;
        cout << "---------------------------" << endl;
    }
};

class PayrollSystem {
private:
    vector<Employee> employees;
public:
    void addEmployee() {
        string name;
        int id;
        double hourlyRate;

        cout << "Enter employee name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter employee ID: ";
        cin >> id;

        cout << "Enter hourly rate: $";
        cin >> hourlyRate;

        employees.push_back(Employee(name, id, hourlyRate));
    }

    void calculateAndDisplaySalary() const {
        for (const Employee &employee : employees) {
            employee.displayDetails();
        }
    }

    void setEmployeeHours(int id, int hours) {
        for (Employee &employee : employees) {
            if (employee.getId() == id) {
                employee.setHoursWorked(hours);
                return;
            }
        }
        cout << "Employee with ID " << id << " not found!" << endl;
    }
};

int main() {
    PayrollSystem payrollSystem;
    int choice;

    do {
        cout << "1. Add Employee\n2. Set Employee Hours\n3. Calculate and Display Salaries\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                payrollSystem.addEmployee();
                break;
            case 2:
                int id, hours;
                cout << "Enter employee ID: ";
                cin >> id;
                cout << "Enter hours worked: ";
                cin >> hours;
                payrollSystem.setEmployeeHours(id, hours);
                break;
            case 3:
                payrollSystem.calculateAndDisplaySalary();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}