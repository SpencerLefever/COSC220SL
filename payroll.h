/*
 *Spencer Lefever
 *2-28-2020
 * COSC 220
 * Payroll header file for class prototypes and objects Lab4
 */
 
#ifndef PAYROLL_H
#define PAYROLL_H
#include <string>
#include <stdio.h>
#include <iostream>

class PayRoll
{
public:
    //Private data members
    std::string name;    //Name of the employee
    double wage;    //Hourly wage of the employee 
    double hours;   //Number of hours the employee works

    //Default constructor
    PayRoll(){}
    
     //Class constructor
	PayRoll(std::string n, double w, double h)
	{
		name = n;
		wage = w;
		hours = h;
	}
    
    //Class prototypes
    double calcPay(double, double); //Calculate the pay for the employee
    
    void printData(); //Function to print employees data 
    
    //Setters
    void setName(std::string);  //Function to set the name of the employees
    void setWage(double);   //Set the wage for the employee
    void setHours(double); //Prototype to set the number of hours worked
 
};



#endif
