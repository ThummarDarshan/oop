/*
A growing organization sought to enhance its payroll process to improve accuracy and efficiency in
calculating employee salaries. The goal was to manage details such as the employee's name, basic
salary, and bonus amount. While most employees would receive a default bonus, there was a need
for flexibility to provide customized bonuses for exceptional performers or those in specialized roles.

To ensure real-time computation of each employee's total salary, the system would dynamically
calculate the total salary by adding the basic salary and the bonus. An inline function was chosen for
this task, allowing the system to compute the total salary instantly during processing. The system was
designed to initialize employee records using a constructor, where the bonus could either be set to a
default value or adjusted according to specific employee criteria.

As the organization expanded, managing employee records efficiently became a key consideration.
The solution involved storing employee details dynamically, ensuring the system could handle a
growing number of records while maintaining scalability and flexibility. Each employee record would
include their personal details, basic salary, and bonus information,
*/

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Employee
{
    char Name[20];
    int Basic_Salary;
    int Bonus;

public:
    void Display()
    {
        cout << Name << endl
             << Basic_Salary << endl
             << Bonus << endl
             <<"Total Salary is  : $ "
             << Calculate_salary() << endl;
             cout<<"\n";
    }
    int Calculate_salary()
    {
        return Basic_Salary + Bonus;
    }
    Employee()
    {
        strcpy(Name, "");
        Basic_Salary = 0;
        Bonus = 0;
    }

    Employee(char name[], int basic_salary, int bonus)
    {
        strcpy(Name, name);
        Basic_Salary = basic_salary;
        Bonus = bonus;
    }
};

int main()
{
    vector<Employee> Emp1, Emp2, Emp3;
    Emp1.push_back(Employee("ABC", 5000, 500));
    Emp2.push_back(Employee("XYZ", 1000, 100));
    Emp3.push_back(Employee("PQR", 10000, 1000));

        Emp1[0].Display();

    for (auto &i: Emp2)
    {
        i.Display();
    }
    for (auto &i : Emp3)
    {
        i.Display();
    }
}
