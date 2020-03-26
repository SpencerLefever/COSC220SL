lab5: main.o payroll.o payrollstack.o
    g++ -std=c++11 main.o payroll.o payrollstack.o -o lab5
    
main.o: main.cpp
    g++ -std=c++11 -c main.cpp
    
payrollstack.o: payrollstack.cpp
    g++ -std=c++11 -c payrollstack.cpp

payroll.o: payroll.cpp 
    g++ -std=c++11 -c payroll.cpp
    
