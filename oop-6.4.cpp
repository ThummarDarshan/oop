/*
A software development team is working on an advanced simulation system that involves hierarchical
object management. The system includes a base class that defines general behavior and derived
classes that introduce specialized functionality, including dynamic resource allocation. During testing,
the team encounters unexpected memory leaks when deleting objects through base class pointers,
raising concerns about proper resource management.
To investigate the issue, the team examines how object destruction works in an inheritance hierarchy.
They create a base class that serves as a foundation for derived classes, but they notice that when a
Base* pointer is used to delete a Derived object, the destructor of the derived class is not invoked.
This results in dynamically allocated resources remaining in memory, causing resource leakage.
To resolve this problem, the team explores the concept of virtual destructors. By marking the base
class destructor as virtual, they ensure that the destructor of the derived class is correctly called when
deleting an object through a base class pointer. This guarantees proper deallocation of dynamically
allocated resources, preventing memory leaks.
Since the project requires manual memory management, the team uses raw pointers and the new and
delete operators to allocate and release resources.
*/

#include <iostream>
using namespace std;

// Base class
class Base {
public:
    // Virtual destructor to ensure proper destruction of derived class objects
    virtual ~Base() {
        cout << "Base class destructor called" << endl;
    }

    virtual void display() {
        cout << "Base class display" << endl;
    }
};

// Derived class
class Derived : public Base {
private:
    int* data;  // Simulating dynamic memory allocation in derived class

public:
    // Constructor
    Derived(int val) {
        data = new int(val);  // Dynamically allocate memory
        cout << "Derived class constructor called" << endl;
    }

    // Destructor
    ~Derived() override {
        delete data;  // Properly deallocate the dynamically allocated memory
        cout << "Derived class destructor called" << endl;
    }

    // Override display function
    void display() override {
        cout << "Derived class display: " << *data << endl;
    }
};

int main() {
    // Creating a derived class object using a base class pointer
    Base* obj = new Derived(100);  // Polymorphic behavior

    // Display function will call the derived class version
    obj->display();

    // Deleting the object through base class pointer
    delete obj;  // Properly calls both the derived and base class destructors

    return 0;
}
