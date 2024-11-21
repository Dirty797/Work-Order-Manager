#include <iostream>
#include <string>
#include "Manager.h"
using namespace std;

int main() {
    Manager manager(10);
    int choice;

    do {
        cout << "---Main Menu---" << endl;
        cout << "1. Add a new work order" << endl;
        cout << "2. Remove a work order" << endl;
        cout << "3. Search for a work order by contact number" << endl;
        cout << "4. Display all work orders" << endl;
        cout << "5. Edit a work order" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                cout << "Enter the name: ";
                string name;
                getline(cin, name);

                cout << "Enter the description: ";
                string description;
                getline(cin, description);

                cout << "Enter the due date (e.g. 08/25): ";
                string dueDate;
                getline(cin, dueDate);

                cout << "Enter the phone number (e.g. 8504733483): ";
                string phoneNumber;
                getline(cin, phoneNumber);

                WorkOrder wo(name, description, dueDate, phoneNumber);
                if (manager.addWorkOrder(wo)) {
                    cout << "Work order added successfully!" << endl;
                } else {
                    cout << "Work order could not be added. Manager is full." << endl;
                }
                break;
            }
            case 2: {
                manager.displayAllWorkOrders();
                cout << "Enter the index of the work order you wish to remove: ";
                size_t index;
                cin >> index;
                cin.ignore();
                if (manager.removeWorkOrder(index)) {
                    cout << "Work order removed successfully!" << endl;
                } else {
                    cout << "Invalid work order index." << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter the phone number (e.g. 8504733483): ";
                string phoneNumber;
                getline(cin, phoneNumber);

                int index = manager.searchWorkOrderByPhone(phoneNumber);
                if (index != -1) {
                    cout << "Work order found at index: " << index << endl;
                    manager.displayAllWorkOrders();
                } else {
                    cout << "Work order not found." << endl;
                }
                break;
            }
            case 4:
                manager.displayAllWorkOrders();
                break;
            case 5: {
                manager.displayAllWorkOrders();
                cout << "Enter the index of the work order you wish to edit: ";
                size_t index;
                cin >> index;
                cin.ignore();

                cout << "---Edit work order---" << endl;
                cout << "0. Name" << endl;
                cout << "1. Description" << endl;
                cout << "2. Due date" << endl;
                cout << "3. Phone number" << endl;
                cout << "Enter your choice of category to edit: ";
                int editChoice;
                cin >> editChoice;
                cin.ignore();
                cout << "Enter the new value: ";
                string newValue;
                getline(cin, newValue);

                if (manager.editWorkOrder(index, editChoice, newValue)) {
                    cout << "Work order edited successfully!" << endl;
                } else {
                    cout << "Invalid edit operation." << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
