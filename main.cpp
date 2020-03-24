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
#include "payrolllist.h"

int main()
{
    PayRollList* employeeList = new PayRollList;
    
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
            //Insert the new data into the payroll list
            employeeList->insert(nameInput, wageInput, hourInput);       
        }
	}
    else
    {
        std::cout << "Error creating employeeListLab4.txt\n";
    }
	input.close();
   
    //print pay checks function
	std::cout << "Original list from text file\n";
	employeeList->printPayChecks();

	//Assign new object to 3rd spot in list
	employeeList->assign(2, PayRoll("Joe", .10, 60));
	employeeList->printPayChecks();
	//Delete fourth element
	employeeList->remove(3);
	employeeList->printPayChecks();
	//Insert new object into specific spot in list
	employeeList->insert(3, PayRoll("John", .09, 50));
	employeeList->printPayChecks();
	//Assign new object in the fifth spot
	employeeList->assign(4, PayRoll("John2", .16, 45));
	employeeList->printPayChecks();
	//Delete second element
	employeeList->remove(1);
	employeeList->printPayChecks();
	//Insert new object into specific spot in list
	employeeList->insert(2, PayRoll("Joe2", .13, 55));
	employeeList->printPayChecks();

	delete employeeList;

	system("pause");
	return 0;
        
}
