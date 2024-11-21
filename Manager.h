#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "WorkOrder.h"
using namespace std;

class Manager {
private:
    WorkOrder* workOrders;
    size_t count;
    size_t capacity;

public:
    Manager(size_t capacity);
    ~Manager();

    bool addWorkOrder(const WorkOrder& wo);
    bool removeWorkOrder(size_t index);
    int searchWorkOrderByPhone(const string& phone) const;
    void displayAllWorkOrders() const;
    bool editWorkOrder(size_t index, int field, const string& newValue);
};

#endif
