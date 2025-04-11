

/*  

    THIS CODE IS BOTH CODE OF OOP-2.2-I AND OOP-2.2-II
 
A university managing academic data for its students. The administration seeks to digitize the records
of student performance, including personal and academic details. The system must store each
student's roll number, name, and marks in three subjects. Additionally, it should provide
functionalities to calculate and display the average marks for performance analysis.

The institution's IT team proposed a solution where student records could be initialized in two ways:
either with default values for testing purposes or by accepting specific input details for each student.
Once initialized, the system would allow for viewing comprehensive student details, including their
roll number, name, marks, and calculated average. This functionality was designed to help faculty and
administrators track individual student performance efficiently.

To simulate real-world usage, the team decided to create multiple student records. They planned to
populate the system with a mix of students initialized using both default and specific values. The
system's ability to accurately calculate averages and display detailed student information was to be
tested with this data.
*/


#include <iostream>
using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    int marks[3];
    float average;

    // Default constructor
    Student()
    {
        rollNumber = 0;
        name = "Default Student";
        marks[0] = 0;
        marks[1] = 0;
        marks[2] = 0;
        calculateAverage();
    }

    // Parameterized constructor
    Student(int r, string n, int m1, int m2, int m3)
    {
        rollNumber = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateAverage();
    }


    void calculateAverage()
    {
        average = (marks[0] + marks[1] + marks[2]) / 3.0;
    }


    void display()
    {
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Name: " << name << "\n";
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << "\n";
        cout << "Average Marks: " << average << "\n\n";
    }
};

int main()
{

    Student s1;
    Student s2(101, "Dhruvin", 95, 80, 90);
    Student s3(102, "Prince", 98, 92, 85);

    s1.display();
    s2.display();
    s3.display();

    return 0;
}
