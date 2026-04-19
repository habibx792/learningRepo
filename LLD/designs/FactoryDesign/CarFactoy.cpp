#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
class Car
{
protected:
    int wheel;

public:
    virtual void printInfo() = 0;
};
class TwoWheelerCar : public Car
{
private:
public:
    TwoWheelerCar()
    {
        wheel = 2;
    }
    void printInfo()
    {
        cout << "This is a two-wheeler car with " << wheel << " wheels." << endl;
    }
};
class FourWheelerCar : public Car
{
public:
    FourWheelerCar()
    {
        wheel = 4;
    }
    void printInfo()
    {
        cout << "This is a four-wheeler car with " << wheel << " wheels." << endl;
    }
};
class CarFactory
{
public:
    virtual Car *CreateCar() = 0;
};
class TwoWheelerFactory : public CarFactory
{
public:
    Car *CreateCar()
    {
        return new TwoWheelerCar();
    }
};
class FourWheelerFactory : public CarFactory
{
public:
    Car *CreateCar()
    {
        return new FourWheelerCar();
    }
};
class Person
{
    Car *car;

public:
    Person()
    {
        car = nullptr;
    }
    Person(Car *car)
    {
        this->car = car;
    }

public:
    void printPersonCarInfo()
    {
        car->printInfo();
    }
    void BuyCar(Car *car)
    {
        this->car = car;
        // Implementation for buying items
    }
};
int main()
{
    CarFactory *twoCar = new TwoWheelerFactory();
    CarFactory *fourWheel = new FourWheelerFactory();
    Car *car1 = twoCar->CreateCar();
    Car *car2 = fourWheel->CreateCar();
    Person p;
    p.BuyCar(car2);
    p.printPersonCarInfo();

 
    return 0;
}