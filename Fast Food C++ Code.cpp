#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <limits>
using namespace std;

// Function Declarations
void clearScreen();
int login();
void mainPage();
void callExit();
void addCustomer();
void addEmployee();
void viewCustomers();
void viewEmployees();
void editCustomer();
void editEmployee();
void deleteCustomer();
void deleteEmployee();
void saveCustomerRecord(const string& name, const string& address, const string& order, const string& specialRequest);
void saveEmployeeRecord(const string& employeeID, const string& name, const string& position, const string& assignedShift);

void clearScreen() {
    system("cls");
}

int login() {
    clearScreen();
    string username, password;
    int attempts = 0;
    const int max_attempts = 3;
    const string correct_username = "pakistan";
    const string correct_password = "1234";

    while (attempts < max_attempts) {
        password.clear();
        cout << "\n\n\n\n\n\n";
        cout << "\t\t\t\t    ----------------------------------\n";
        cout << "\t\t\t\t    |  FAST FOOD MANAGEMENT SYSTEM |\n";
        cout << "\t\t\t\t    ----------------------------------\n";
        cout << "\n\n";
        cout << "\t\t\t\t\tUsername: ";
        cin >> username;
        cout << "\t\t\t\t\tPassword: ";

        char ch;
        while ((ch = _getch()) != '\r') {
            if (ch == '\b' && !password.empty()) {
                cout << "\b \b";
                password.erase(password.length() - 1);  // FIXED
            }
            else if (ch != '\b' && ch != '\r') {
                cout << "*";
                password += ch;
            }
        }

        if (username == correct_username && password == correct_password) {
            cout << "\n\n";
            cout << "\t\t\t\tYou have successfully logged into the system!\n\n";
            system("pause");
            return 1;
        }
        else {
            attempts++;
            cout << "\n\n\n\n\n\n";
            cout << "\t\t\t\tNo. of attempts remaining: " << max_attempts - attempts << "\n\n";
            system("pause");
            clearScreen();
        }
    }
    return 0;
}

void mainPage() {
    clearScreen();
    cout << "\t\t\t\t\t\t" << __DATE__ << endl;
    cout << "\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\t\t\t\t    |  FAST FOOD MANAGEMENT SYSTEM |\n";
    cout << "\t\t\t\t    ------------------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\tPrepared By  : Maisam taqi\n";
    cout << "\t\t\t\tSubject      : Programming Fundamentals\n";
    cout << "\t\t\t\tProject Title: Fast Food Management System\n";
    cout << "\t\t\t\tProfessor Name:Waqar Hussain\n";
    cout << "\t\t\t\tGovernment College University Faislabad Chiniot Campus\n";
    cout << "\n\n";
    system("pause");
}

void callExit() {
    clearScreen();
    cout << "\n\n\n\n\n";
    cout << "\n\tTaking You Out of The System\n";
    cout << "\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\tYou are out of the System.\n";
    cout << "\t\t\t\t\tThank You!\n";
    exit(0);
}

void saveCustomerRecord(const string& name, const string& address, const string& order, const string& specialRequest) {
    ofstream file("customer_orders.txt", ios::app);
    if (file.is_open()) {
        file << "Name: " << name << "\n";
        file << "Address: " << address << "\n";
        file << "Order: " << order << "\n";
        file << "Special Request: " << specialRequest << "\n";
        file << "----------------------------\n";
        file.close();
        cout << "Customer details saved successfully." << endl;
    }
    else {
        cout << "Error: Unable to open file!" << endl;
    }
}

void saveEmployeeRecord(const string& employeeID, const string& name, const string& position, const string& assignedShift) {
    ofstream file("employee_records.txt", ios::app);
    if (file.is_open()) {
        file << "ID: " << employeeID << "\n";
        file << "Name: " << name << "\n";
        file << "Position: " << position << "\n";
        file << "Shift: " << assignedShift << "\n";
        file << "----------------------------\n";
        file.close();
        cout << "Employee details saved successfully." << endl;
    }
    else {
        cout << "Error: Unable to open file!" << endl;
    }
}

void addCustomer() {
    clearScreen();
    string name, address, order, specialRequest;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter the name of the customer: ";
    getline(cin, name);
    cout << "Enter the address of the customer: ";
    getline(cin, address);
    cout << "Enter the order (Burger, Fries, Drink, etc.): ";
    getline(cin, order);
    cout << "Enter any special requests: ";
    getline(cin, specialRequest);
    saveCustomerRecord(name, address, order, specialRequest);
}

void addEmployee() {
    clearScreen();
    string employeeID, name, position, assignedShift;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Employee ID: ";
    getline(cin, employeeID);
    cout << "Enter Employee Name: ";
    getline(cin, name);
    cout << "Enter Employee Position: ";
    getline(cin, position);
    cout << "Enter Assigned Shift: ";
    getline(cin, assignedShift);
    saveEmployeeRecord(employeeID, name, position, assignedShift);
}

void viewCustomers() {
    clearScreen();
    ifstream file("customer_orders.txt");
    string line;
    if (file.is_open()) {
        cout << "Customer Orders:\n";
        cout << "-----------------------------------\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Error: Unable to open customer orders file!" << endl;
    }
}

void viewEmployees() {
    clearScreen();
    ifstream file("employee_records.txt");
    string line;
    if (file.is_open()) {
        cout << "Employee Records:\n";
        cout << "-----------------------------------\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Error: Unable to open employee records file!" << endl;
    }
}

void editCustomer() {
    clearScreen();
    string name, line;
    cout << "Enter the name of the customer to edit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    ifstream file("customer_orders.txt");
    ofstream tempFile("temp_customer_orders.txt");
    bool found = false;

    while (getline(file, line)) {
        if (line.find("Name: " + name) != string::npos) {
            found = true;
            cout << "Editing details for customer: " << name << endl;
            string newName, newAddress, newOrder, newSpecialRequest;
            cout << "Enter new name: ";
            getline(cin, newName);
            cout << "Enter new address: ";
            getline(cin, newAddress);
            cout << "Enter new order (e.g., Burger, Fries): ";
            getline(cin, newOrder);
            cout << "Enter new special requests: ";
            getline(cin, newSpecialRequest);

            tempFile << "Name: " << newName << "\n";
            tempFile << "Address: " << newAddress << "\n";
            tempFile << "Order: " << newOrder << "\n";
            tempFile << "Special Request: " << newSpecialRequest << "\n";
            tempFile << "----------------------------\n";

            for (int i = 0; i < 4; i++) {
                getline(file, line);
            }
            continue;
        }
        tempFile << line << "\n";
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("customer_orders.txt");
        rename("temp_customer_orders.txt", "customer_orders.txt");
        cout << "Customer details updated successfully." << endl;
    }
    else {
        remove("temp_customer_orders.txt");
        cout << "Customer not found!" << endl;
    }
}

void editEmployee() {
    clearScreen();
    string employeeID, line;
    cout << "Enter the Employee ID to edit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, employeeID);

    ifstream file("employee_records.txt");
    ofstream tempFile("temp_employee_records.txt");
    bool found = false;

    while (getline(file, line)) {
        if (line.find("ID: " + employeeID) != string::npos) {
            found = true;
            cout << "Editing details for Employee ID: " << employeeID << endl;
            string newEmployeeID, newName, newPosition, newAssignedShift;
            cout << "Enter new Employee ID: ";
            getline(cin, newEmployeeID);
            cout << "Enter new Name: ";
            getline(cin, newName);
            cout << "Enter new Position: ";
            getline(cin, newPosition);
            cout << "Enter new Assigned Shift: ";
            getline(cin, newAssignedShift);

            tempFile << "ID: " << newEmployeeID << "\n";
            tempFile << "Name: " << newName << "\n";
            tempFile << "Position: " << newPosition << "\n";
            tempFile << "Shift: " << newAssignedShift << "\n";
            tempFile << "----------------------------\n";

            for (int i = 0; i < 4; i++) {
                getline(file, line);
            }
            continue;
        }
        tempFile << line << "\n";
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("employee_records.txt");
        rename("temp_employee_records.txt", "employee_records.txt");
        cout << "Employee details updated successfully." << endl;
    }
    else {
        remove("temp_employee_records.txt");
        cout << "Employee not found!" << endl;
    }
}

void deleteCustomer() {
    clearScreen();
    string name, line;
    cout << "Enter the name of the customer to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    ifstream file("customer_orders.txt");
    ofstream tempFile("temp_customer_orders.txt");
    bool found = false;
    bool skipNextLines = false;
    int linesToSkip = 0;

    while (getline(file, line)) {
        if (line.find("Name: " + name) != string::npos) {
            found = true;
            skipNextLines = true;
            linesToSkip = 4;
            continue;
        }

        if (skipNextLines) {
            if (linesToSkip > 0) {
                linesToSkip--;
                continue;
            }
            if (line == "----------------------------") {
                skipNextLines = false;
                continue;
            }
        }
        tempFile << line << "\n";
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("customer_orders.txt");
        rename("temp_customer_orders.txt", "customer_orders.txt");
        cout << "Customer deleted successfully." << endl;
    }
    else {
        remove("temp_customer_orders.txt");
        cout << "Customer not found!" << endl;
    }
}

void deleteEmployee() {
    clearScreen();
    string employeeID, line;
    cout << "Enter the Employee ID to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, employeeID);

    ifstream file("employee_records.txt");
    ofstream tempFile("temp_employee_records.txt");
    bool found = false;
    bool skipNextLines = false;
    int linesToSkip = 0;

    while (getline(file, line)) {
        if (line.find("ID: " + employeeID) != string::npos) {
            found = true;
            skipNextLines = true;
            linesToSkip = 4;
            continue;
        }

        if (skipNextLines) {
            if (linesToSkip > 0) {
                linesToSkip--;
                continue;
            }
            if (line == "----------------------------") {
                skipNextLines = false;
                continue;
            }
        }
        tempFile << line << "\n";
    }

    file.close();
    tempFile.close();

    if (found) {
        remove("employee_records.txt");
        rename("temp_employee_records.txt", "employee_records.txt");
        cout << "Employee deleted successfully." << endl;
    }
    else {
        remove("temp_employee_records.txt");
        cout << "Employee not found!" << endl;
    }
}

int main() {
    cout << __DATE__ << endl;
    mainPage();

    if (login()) {
        char choice;
        do {
            clearScreen();
            cout << "Fast Food Management System\n";
            cout << "=========================\n";
            cout << "1. Add Customer\n";
            cout << "2. Add Employee\n";
            cout << "3. View Customers\n";
            cout << "4. View Employees\n";
            cout << "5. Edit Customer\n";
            cout << "6. Edit Employee\n";
            cout << "7. Delete Customer\n";
            cout << "8. Delete Employee\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case '1': addCustomer(); break;
                case '2': addEmployee(); break;
                case '3': viewCustomers(); break;
                case '4': viewEmployees(); break;
                case '5': editCustomer(); break;
                case '6': editEmployee(); break;
                case '7': deleteCustomer(); break;
                case '8': deleteEmployee(); break;
                case '9': callExit(); break;
                default: cout << "Invalid choice! Try again.\n";
            }
            cout << "\nPress any key to return to menu...\n";
            system("pause");
        } while (choice != '9');
    }
    callExit();
    return 0;
}
