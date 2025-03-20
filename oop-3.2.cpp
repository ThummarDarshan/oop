/*
A software development company was tasked with conducting a performance analysis of recursive
algorithms versus their iterative counterparts. The specific focus was on calculating the sum of
integers in an array, where the array's size and elements were to be provided dynamically by the user.
To facilitate memory management and enable dynamic resizing of the array, the team decided to use
a flexible container for storing the array elements.

The system was designed to first prompt users for the array's size and then request the input of
individual elements. A recursive function was to be implemented to compute the sum by dividing the
problem into smaller sub-problems, recursively summing subsets of the array until reaching the base
case. In addition to the recursive implementation, an iterative version of the function would be
created for comparison.

The main objective of the study was to assess and compare the computational performance and
implementation complexity of both recursive and non-recursive approaches. By evaluating execution
times, memory usage, and code complexity, the team hoped to gain insights into the trade-offs
between recursion and iteration, particularly in terms of efficiency and applicability to real-world
problems.
*/

#include <iostream>
#include <vector>
#include<chrono>
using namespace std;
using namespace chrono;
int total=0;
int addition(vector<int>& number,int z,int y)
{
    if(z==y)
    {
        return total;
    }
    total += number[z];
    addition(number,z+1,y);
}

int main()
{
    int size,sum,Z=0;
    cout << "How many numbers : ";
    cin >> size;

    vector<int> number(size);
    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> number[i];
    }
    auto start = high_resolution_clock::now(); // Start time measurement
    sum = addition(number,Z,size);
    auto stop = high_resolution_clock::now(); // Stop time measurement

    auto duration = duration_cast<microseconds>(stop - start); // Calculate duration

    cout << "The sum is: " << sum << endl;
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
