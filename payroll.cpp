/*
 *Spencer Lefever
 *2-28-2020
 * COSC 220
 * Payroll cpp file used to define prototypes
 */
 
#include "payroll.h"
#include <string>
#include <stdio.h>
#include <iostream>

//Calculate total pay
double PayRoll::calcPay(double wage, double time)
{
 return wage * time;    //Calculates and returns the total pay for an employee   
}

//Set the name and pay rate of the employee

//Function to set the hours worked for any given employee
void PayRoll::setHours(double h)
{
    hours = h;
}

void PayRoll::setName(std::string n)
{
    name = n;
}

void PayRoll::setWage(double w)
{
    wage = w;
}

void PayRoll::printData()
{
     std::cout << name << "\t\t$" << wage << "\t\t" << hours << "\t$" << calcPay(wage,hours) << "\n";
     
}

