/*
A financial analytics company is working on a system that processes large volumes of sorted numerical
data from different sources. The challenge is to efficiently combine two independently sorted datasets
into a single, fully sorted dataset while ensuring optimal memory management. Since the size of the
datasets varies dynamically based on incoming data streams, the solution must be flexible and manage
memory efficiently without relying on built-in container libraries.
To achieve this, the development team needs to implement a mechanism that accepts two sorted
arrays of different sizes and merges them into a new dynamically allocated array while maintaining
the sorted order. The system should read input values specifying the sizes of both datasets, followed
by the elements of each array. After merging, the final sorted array should be displayed as output.
Efficient memory handling is crucial in this implementation, requiring the use of new and delete
operators for dynamic allocation and deallocation of memory.
*/

#include <iostream>

using namespace std;

int* mergeSortedArrays(int* ptr1, int size1, int* ptr2, int size2, int* mergedSizePtr) {
    *mergedSizePtr = size1 + size2;

    int* mergedPtr = new int[*mergedSizePtr];

    int* p1 = ptr1;
    int* p2 = ptr2;
    int* pm = mergedPtr;

    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (*p1 < *p2) {
            *pm = *p1;
            p1++;
            i++;
        } else {
            *pm = *p2;
            p2++;
            j++;
        }
        pm++;
    }

    while (i < size1) {
        *pm = *p1;
        pm++;
        p1++;
        i++;
    }

    while (j < size2) {
        *pm = *p2;
        pm++;
        p2++;
        j++;
    }

    return mergedPtr;
}

int main() {
    int size1, size2;

    cout << "Enter size of first sorted array: ";
    cin >> size1;
    int* arr1 = new int[size1];

    cout << "Enter " << size1 << " sorted elements for array 1:\n";
    for (int i = 0; i < size1; ++i)
        cin >> *(arr1 + i);

    cout << "Enter size of second sorted array: ";
    cin >> size2;
    int* arr2 = new int[size2];

    cout << "Enter " << size2 << " sorted elements for array 2:\n";
    for (int i = 0; i < size2; ++i)
        cin >> *(arr2 + i);

    int mergedSize = 0;
    int* mergedArr = mergeSortedArrays(arr1, size1, arr2, size2, &mergedSize);

    cout << "Merged Sorted Array:\n";
    for (int i = 0; i < mergedSize; ++i)
        cout << *(mergedArr + i) << " ";
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;

    return 0;
}
