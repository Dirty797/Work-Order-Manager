#include "Manager.h"
#include <iostream>
using namespace std;

Manager::Manager(size_t capacity) : count(0), capacity(capacity) {
    workOrders = new WorkOrder[capacity];
}

Manager::~Manager() {
    delete[] workOrders;
}

bool Manager::addWorkOrder(const WorkOrder& wo) {
    if (count >= capacity) {
        return false;
    }
    workOrders[count++] = wo;
    return true;
}

bool Manager::removeWorkOrder(size_t index) {
    if (index >= count) {
        return false;
    }
    for (size_t i = index; i < count - 1; ++i) {
        workOrders[i] = workOrders[i + 1];
    }
    --count;
    return true;
}

int Manager::searchWorkOrderByPhone(const string& phone) const {
    for (size_t i = 0; i < count; ++i) {
        if (workOrders[i].getPhoneNumber() == phone) {
            return i;
        }
    }
    return -1;
}

void Manager::displayAllWorkOrders() const {
    if (count == 0) {
        cout << "No work order so far!" << endl;
        return;
    }
    for (size_t i = 0; i < count; ++i) {
        cout << i << ") ";
        workOrders[i].print();
    }
}

bool Manager::editWorkOrder(size_t index, int field, const string& newValue) {
    if (index >= count) {
        return false;
    }

    switch (field) {
        case 0: workOrders[index].setName(newValue); break;
        case 1: workOrders[index].setDescription(newValue); break;
        case 2: workOrders[index].setDueDate(newValue); break;
        case 3: workOrders[index].setPhoneNumber(newValue); break;
        default: return false;
    }
    return true;
}
