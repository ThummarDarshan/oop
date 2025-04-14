
/*
A team of engineers was tasked with developing a program to calculate and manage the areas of 
multiple circles for a design project. To achieve this, they devised a solution using a structured, object
oriented approach. At the foundation of their solution was a base class that represented a generic 
shape, responsible for storing and managing the radius of the circle. Building upon this, a specialized 
class for circles was created to extend functionality by introducing a method for calculating the area 
of a circle based on its radius. Using this framework, the team designed a system to handle multiple 
circles, ensuring that the process of storing, calculating, and displaying the areas was efficient and 
adaptable. They explored two different approaches for managing the collection of circles—one 
focusing on flexibility and dynamic handling, while the other used a more static structure. By 
implementing and comparing these methods, the engineers gained insights into the benefits of using 
efficient techniques for organizing and processing geometric data, enhancing their problem-solving 
capabilities.
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class FuelType
{

    protected:

        string fuel;

    public:

        FuelType(const string& fuelType) : fuel(fuelType) {}

    void showFuelType() const
    {
        cout << "Fuel Type: " << fuel << endl;
    }
};

class Brand
{
protected:

    string brandName;

public:
    Brand(const string& brand) : brandName(brand) {}

    void showBrandName() const
    {
        cout << "Brand: " << brandName << endl;
    }
};

class Car : public FuelType, public Brand
{
    private:
        string model;
    public:

        Car(const string& fuelType, const string& brand, const string& modelName)
        : FuelType(fuelType), Brand(brand), model(modelName) {}

    void displayDetails() const //i use const bcz i don`t chage value
    {
        showFuelType();
        showBrandName();
        cout << "Model: " << model << endl;
    }
};

int main()
{

    queue<Car> carQueue;


    carQueue.push(Car("Petrol", "Toyota", "Fortuner"));
    carQueue.push(Car("Diesel", "BMW", "330i M Sports"));
    carQueue.push(Car("Electric", "Mahindra", "BE 6"));


    while (!carQueue.empty())
    {
        Car currentCar = carQueue.front();
        carQueue.pop();
        currentCar.displayDetails();
        cout << "----------------------" << endl;
    }

    return 0;
}
