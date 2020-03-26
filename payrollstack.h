/*
 * Spencer Lefever
 * 2-28-20
 * COSC 220
 * Lab4 Continuation of the payroll
 */

#ifndef PAYROLLSTACK_H
#define PAYROLLSTACK_H
#include <string>
#include "payroll.h"

class PayRollStack
{
private:
	struct ListNode
	{
		PayRoll employee;
		ListNode* next;
	};

	ListNode* head;

public:
	//Class constructor
	PayRollStack()
	{
		head = nullptr;
	}

	//Class destructor
	~PayRollStack()
	{
		for (ListNode *tmp, *cursor = head; cursor; cursor = tmp)
		{
			tmp = cursor->next;
			delete cursor;
		}
	}

	//Copy Constructor
	PayRollStack(PayRollStack&);

	//Overloaded = operator for PayRollSatcks
	PayRollStack operator=(const PayRollStack&);

	//Pushes object to top of stack which is the head
	void push(PayRoll);

	//Reutrns payroll object(employee) most recently pushed (head)
	PayRoll pop();

	//Return size of the stack
	int size();

	void print();
};
#endif
