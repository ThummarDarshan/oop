/*
In a rapidly growing software development firm, a team of engineers is tasked with building a
lightweight, custom memory management system for handling dynamic datasets. The existing
framework lacks flexibility in managing arrays, often leading to inefficient memory usage and
performance bottlenecks. To address this, the engineers need to develop a solution that allows
seamless insertion and deletion of elements while ensuring efficient memory utilization.
The primary challenge is to design a structure that supports adding new data points dynamically at
the end of the dataset and removing specific elements based on their position. Since the system
operates in a resource-constrained environment, using standard template libraries is not an option,
and direct dynamic memory management must be implemented using pointers. The solution should
ensure that memory is allocated and deallocated appropriately to prevent leaks and unnecessary
overhead.
The development team must carefully decide on the structure of their implementation, defining how
data will be stored, accessed, and modified efficiently. They need to outline the appropriate class
design, determine essential data members, and define necessary member functions to handle the
operations effectively.
*/

#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;        // Pointer to the dynamic array
    int size;         // Current number of elements
    int capacity;     // Total allocated size

    void resize() {
        // Double the capacity
        int newCapacity = capacity * 2;
        int* newData = new int[newCapacity];

        // Copy old data to new array
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        // Delete old array
        delete[] data;

        // Update pointer and capacity
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 2) {
        capacity = initialCapacity;
        size = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void insert(int value) {
        if (size == capacity) {
            resize();
        }
        data[size++] = value;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index for removal." << endl;
            return;
        }

        // Shift elements left
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    void display() const {
        cout << "[ ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            cout << "Invalid index for get." << endl;
            return -1; // Error value
        }
        return data[index];
    }
};

int main() {
    DynamicArray arr;

    // Insert some values
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    cout << "After insertions: ";
    arr.display();

    // Remove an element
    arr.remove(1); // Remove the element at index 1 (value 20)

    cout << "After removal: ";
    arr.display();

    cout << "Current size: " << arr.getSize() << endl;
    cout << "Current capacity: " << arr.getCapacity() << endl;

    return 0;
}

