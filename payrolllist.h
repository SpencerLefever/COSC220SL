/*
 * Spencer Lefever
 * 2-28-20
 * COSC 220
 * Lab4 Continuation of the payroll
 */

#ifndef PAYROLLLIST_H
#define PAYROLLLIST_H
#include <string>
#include "payroll.h"

class PayRollList
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
  PayRollList()
  {
    head = nullptr;    
  }
  
  //Class destructor
  ~PayRollList()
  {
      for(ListNode *tmp, *cursor = head; cursor; cursor=tmp)
      {
          tmp = cursor ->next;
          delete cursor;
      }
  }
  
  //Copy Constructor
  PayRollList(PayRollList&);
  
  //Overload index operator
  PayRoll* operator[](int);
  
  double calcPay(double, double); //Prototype to calculate the total pay of an employee
  
  //Return length of list (# of items)
  int length();
  
  //Remove the item at the x position
  void remove(int);
  
  //Copy a PayRoll into a specific position
  void assign(int, PayRoll);
  
  //Insert PayRoll into a specified position after the nth spot
  void insert(int, PayRoll);
  
  
  //Function to insert PayRoll elements into the linked list
  //Take name wage and hours worked as arguments
  void insert(std::string, double, double);
  
  //Override of the insert function that takes an employee object
  void insert(PayRoll);
  
  //Function to print the paychecks of the employees takes number of elements in the list
  void printPayChecks();
};

#endif
