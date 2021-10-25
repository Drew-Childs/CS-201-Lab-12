// Your name
// Your UMKC Email Address
// Today's date
// CS201L Lab 12

#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee(int id, string myName) {		//creates new employee object
	employeeID = id;
	name = myName;
	payRate = 10;
	balance = 0;
}

void Employee::giveRaise(int rate) {			//increases pay for given employee
	payRate += (payRate * (rate * 0.01));
}

void Employee::pay() {		//pays all employees
	balance += payRate;
}

void Employee::fire() {		//fires an employee
	payRate = 0;
	employed = false;
}

bool Employee::isEmployed() {		//returns if the employee is employed or not
	return employed;
}