/*
 *Spencer Lefever
 *2-28-2020
 * COSC 220
 * main cpp file for lab4
 */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "payroll.h"
#include "payrollstack.h"

int main()
{
    PayRollStack* employeeStack = new PayRollStack;
    
    std::fstream input;
    
    double hourInput;
    
    double wageInput;
    
    std::string nameInput;
    
    //Open the file
    input.open("employeeListLab4.txt");

	if (input.is_open())
	{
		while(!(input.eof()))
        {       
            getline(input, nameInput);  //Gets the name from the file
            input >> wageInput; //Gets the wage from the file
            //Clear keyboard buffer
            input >> hourInput; //Gets the hours from the file
            input.ignore(100, '\n');
            
			//Set the three inputs to a payroll object and pass it to the push function
			PayRoll newEmployee(nameInput, wageInput, hourInput);
			
			employeeStack->push(newEmployee);
        }
	}
    else
    {
        std::cout << "Error creating employeeListLab4.txt\n";
    }
	input.close();
   
	//Pop and print to test the function
	employeeStack->print();

    employeeStack->pop();

	employeeStack->pop();

	employeeStack->print();

	//Pop the rest of the employees
	//For loop used only for hard coded example
	for (int i = 1; i < 5; i++)
	{
		employeeStack->pop();
	}

	system("pause");
	return 0;
        
}
