// Drew Childs
// wacmk9@mail.umkc.edu
// 4/16/20
// CS201L Lab 12
#include <iostream>
#include <vector>
#include <fstream>
#include "Employee.h"
using namespace std;

int main() {
	string cmd, first, last;		//creating variables and vectors
	int id, raise;
	vector<Employee> emp_list;
	
	ifstream in("input.txt");		//opening files
	ofstream out("output.txt");

	while (in.good()) {		//this loop reads data from the in file
		in >> cmd;
		if (cmd == "NEW") {		//condition for new employee
			in >> id >> first >> last;
			emp_list.push_back(Employee(id, first + last));
		}
		else if (cmd == "RAISE") {		//condition to give employee raise
			in >> id >> raise;
			for (int i = 0; i < emp_list.size(); i++) {
				if (id == emp_list[i].getEmployeeID()) {
					emp_list[i].giveRaise(raise);
				}
			}
		}
		else if (cmd == "PAY") {		//condition to pay all employees
			for (int i = 0; i < emp_list.size(); i++) {
				emp_list[i].pay();
			}
		}
		else if (cmd == "FIRE") {		//condition to fire an employee
			in >> id;
			for (int i = 0; i < emp_list.size(); i++) {
				if (id == emp_list[i].getEmployeeID()) {
					emp_list[i].fire();
				}
			}
		}
	}

	for (int i = 0; i < emp_list.size(); i++) {			//outputs data to out file
		out << emp_list[i].getName() << ", ID Number " << emp_list[i].getEmployeeID() << ":" << endl;
		
		if (emp_list[i].isEmployed()) {
			out << "Current pay rate: $" << emp_list[i].getPayRate() << endl;		
		}
		else {
			out << "Not employed with the company." << endl;
		}

		out << "Pay earned to date: " << emp_list[i].getBalance() << endl << endl;
	}

	in.close();		//closing files
	out.close();
}