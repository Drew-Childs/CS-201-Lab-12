#pragma once
// Your name
// Your UMKC Email Address
// Today's date
// CS201L Lab 12

#include <string>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H


class Employee
{
private:
	int employeeID;
	string name;
	double balance;
	double payRate;
	bool employed = true;
public:
	// Constructor
	Employee(int id, string myName);

	// Getter to return the employee ID
	int getEmployeeID() { return employeeID; }

	// Getter to return the current pay rate
	double getPayRate() { return payRate; }

	// Getter to return the current amount of pay earned
	double getBalance() { return balance; }

	// Getter to get Employee's name
	string getName() { return name; }

	// Function to give the raise. It takes in a percent in whole numbers 
	// (ex: 5 for 5%)
	void giveRaise(int rate);

	// Pays the employee
	void pay();

	// Fires the Employee
	void fire();

	// Returns if the Employee is currently employed
	bool isEmployed();

};

#endif