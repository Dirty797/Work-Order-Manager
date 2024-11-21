#ifndef WORKORDER_H
#define WORKORDER_H
#include <string>
#include <iostream>
using namespace std;

class WorkOrder {
private:
    string name;
    string description;
    string dueDate;
    string phoneNumber;

public:
    WorkOrder() {}
    WorkOrder(const string& name, const string& desc, const string& due, const string& phone);

    void setName(const string& name);
    void setDescription(const string& desc);
    void setDueDate(const string& due);
    void setPhoneNumber(const string& phone);

    string getName() const;
    string getDescription() const;
    string getDueDate() const;
    string getPhoneNumber() const;

    void print() const;
};

#endif
