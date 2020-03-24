/*
 * Spencer Lefever
 * 2-28-20
 * COSC220
 * Lab4 PayRollList cpp file to build all my funcitons that are in payrolllist.h
*/

#include "payroll.h"
#include "payrolllist.h"
#include <iostream>
#include <string>

//Copy constructor
PayRollList::PayRollList(PayRollList& newEmployee)
{
	PayRollList* newList = new PayRollList;
	newList = &newEmployee;
}

//Overload index operator
PayRoll* PayRollList::operator[](int n)
{
	int i = 0;
	ListNode* cursor = head;
		if (n > length())
		{
			std::cout << "Index does not exist in list!\n";
			return nullptr;
		}

		while (cursor->next)
		{
			if (i = n)
			{
				return &(cursor->employee);
			}
			cursor = cursor->next;
			i++;
		}
	
}

void PayRollList::insert(std::string name, double wage, double hours)
{
    //Dynamically allocate a new node to the linked list
	ListNode* newNode = new ListNode;
    
    //Set the pointer to the next element equal to null because 
    //the new node is being added to the end of the list
    newNode ->next = nullptr;
    
    //Set the value of the new node equal to the parameters
    newNode->employee.setName(name);
    newNode->employee.setWage(wage);
    newNode->employee.setHours(hours);
    
    //List is populated
    if (head)
    {
        ListNode* cursor = head;
        //Allign cursor in the correct spot
        while(cursor->next)
        {
			if (wage < cursor->next->employee.wage)
			{
				break;
			}
            cursor = cursor->next;
        }
		//If cursor at end of list append list
		if (!(cursor->next))
		{
			cursor->next = newNode;
		}
		else
		{
			newNode->next = cursor->next;
			cursor->next = newNode;
		}
    }
    else
    {
        //List is empty
        head = newNode;
    }
}

//Calculate and return total pay
double PayRollList::calcPay(double wage, double time)
{
 return wage * time;    //Calculates and returns the total pay for an employee   
}

void PayRollList::insert(PayRoll employee)
{
    //Call the other insert function
    insert(employee.name, employee.wage, employee.hours);
}

void PayRollList::insert(int n, PayRoll employee)
{
	std::cout << "\nInserting " << employee.name << " at spot " << n + 1 << "\n";
	ListNode* newNode = new ListNode;

	newNode->next = nullptr;

	newNode->employee = employee;

	int i = 1;
	if (head)
	{
		ListNode* cursor = head;
		ListNode* tmp = nullptr;
		while (cursor->next)
		{
			if (i == n)
			{
				break;
			}
			cursor = cursor->next;
			i++;
		}
		//If cursor at end of list at to the end of the list
		if (!(cursor))
		{
			cursor->next = newNode;
		}
		else
		{
			tmp = cursor->next;
			cursor->next = newNode;
			newNode->next = tmp;
		}
	}
	else
	{
		head = newNode;
	}
}

//Finds the length of the linked list of employee objects
int PayRollList::length()
{
    //Number of elements in the lisst
    int n = 0;
    
    ListNode* cursor = head;
    while(cursor)
    {
        cursor = cursor->next;
        n++;
    }
    return n;
}

void PayRollList::remove(int x)
{
	std::cout << "\nRemoving employee " << x+1 << "\n";
	int i = 1;
	ListNode* cursor = head;
	ListNode* tmp;
	//Return if list is empty
	if (!head)
	{
		return;
	}
	else
	{
		while (cursor->next)
		{
			if (x == i) { break; }	//Break loop if index is met
			//Increment cursor and i
			cursor = cursor->next;
			i++;
		}
		tmp = cursor->next;
		cursor->next = tmp->next;
		delete tmp;
	}
}

void PayRollList::assign(int x, PayRoll employee)
{
	std::cout << "\nAssigning " << employee.name << " to spot " << x+1 << "\n";
	int i = 1;
	ListNode* cursor = head;
	
	ListNode* tmp = nullptr;

	ListNode* newNode = new ListNode;

	newNode->next = nullptr;

	//Assign employee passed in to the new node
	newNode->employee = employee;
	//Return if list is empty
	if (!head)
	{
		return;
	}
	else
	{
		while (cursor->next)
		{
			if (x == i) { break; }	//Break loop if index is met
			//Increment cursor and i
			cursor = cursor->next;
			i++;
		}
		if (cursor->next == nullptr)
		{
			cursor->next = newNode;
		}
		else
		{
			//Assign tmp
			tmp = cursor->next;
			
			cursor->next = newNode;
			newNode->next = tmp->next;
			delete tmp;	//Delete tmp

		}
	}
}

//Prints the linked list of employees
void PayRollList::printPayChecks()
{
    //Header for the print pay checks function
    std::cout << "\n\nName\t\tPay\n\n";
    
    //Loop to print all the employee information
    ListNode* cursor = head;
    while(cursor)
	{
        std::cout << cursor->employee.name << "\t\t$"
        << calcPay(cursor->employee.wage, cursor->employee.hours)<< "\n";
        cursor = cursor->next;
    }
}
