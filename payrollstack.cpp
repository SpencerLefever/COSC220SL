/*
 * Spencer Lefever
 * 2-28-20
 * COSC220
 * Lab4 PayRollList cpp file to build all my funcitons that are in payrolllist.h
*/

#include "payroll.h"
#include "payrollstack.h"
#include <iostream>
#include <string>

//Copy constructor
PayRollStack::PayRollStack(PayRollStack& newEmployee)
{
	PayRollStack* newList = new PayRollStack;
	newList = &newEmployee;
}

PayRollStack PayRollStack::operator=(const PayRollStack& p)
{ 
	//Check if pointer is in correct place
	if (this != &p)
	{
		if (this->head)
		{
			delete [] this->head;
		}
		this->head->employee.name = p.head->employee.name;
		this->head->employee.wage = p.head->employee.wage;
		this->head->employee.hours = p.head->employee.hours;
	}
	return *this;
}

void PayRollStack::push(PayRoll p)
{
	ListNode* newNode = new ListNode;
	newNode->employee = p;
	//If list is not empty
	if (head)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		head = newNode;
		newNode->next = nullptr;
		//newNode->next = nullptr;
	}
}

PayRoll PayRollStack::pop()
{
	ListNode* tmp = new ListNode;
	PayRoll poppedEmployee;
	std::cout << "\nPop function called.\n\n";

	//Check if list is empty
	if (head)
	{
		//increment the head and then delete the old head from the list
		tmp = head;
		head = tmp->next;
		poppedEmployee = tmp->employee;
		delete tmp;
		return poppedEmployee;
	}
	else
	{
		std::cout << "The list is empty.\n";
		return poppedEmployee;
	}
}

int PayRollStack::size()
{
	//Number of elements in the lisst
	int n = 0;

	ListNode* cursor = head;
	while (cursor->next)
	{
		cursor = cursor->next;
		n++;
	}
	return n;
}

void PayRollStack::print()
{
	if (head)
	{
		//Cursor used to navigate the stack
		ListNode* cursor = head;
		
		//While loop to print the stack
		while(cursor)
		{
			std::cout << "Name: " << cursor->employee.name << "\nWage: $" << cursor->employee.wage << "\nHours: "
				<< cursor->employee.hours << "\nTotal Pay: $"
				<< cursor->employee.calcPay(cursor->employee.wage, cursor->employee.hours) << "\n";

			//Increment cursor
			cursor = cursor->next;
		}
	}
	else
	{
		std::cout << "The list of employees is empty!\n";
	}
}
