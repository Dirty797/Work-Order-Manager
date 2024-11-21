#include "WorkOrder.h"
using namespace std;

WorkOrder::WorkOrder(const string& name, const string& desc, const string& due, const string& phone)
    : name(name), description(desc), dueDate(due), phoneNumber(phone) {}

void WorkOrder::setName(const string& name) { this->name = name; }
void WorkOrder::setDescription(const string& desc) { description = desc; }
void WorkOrder::setDueDate(const string& due) { dueDate = due; }
void WorkOrder::setPhoneNumber(const string& phone) { phoneNumber = phone; }

string WorkOrder::getName() const { return name; }
string WorkOrder::getDescription() const { return description; }
string WorkOrder::getDueDate() const { return dueDate; }
string WorkOrder::getPhoneNumber() const { return phoneNumber; }

void WorkOrder::print() const {
    cout << "Name: " << name
         << " | Work order: " << description 
         << " | Due date: " << dueDate 
         << " | Contact #: " << phoneNumber << endl;
}
