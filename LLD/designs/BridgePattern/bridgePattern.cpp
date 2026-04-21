#include <iostream>

using namespace std;

class A
{
};
class Engine
{
public:
    virtual void start() = 0;
    virtual ~Engine() {};
};
class PetrolEngine : public Engine
{
    
public:
    PetrolEngine() {}
    void start() override
    {
        cout << "petrol Engine starting with ignition" << endl;
    }
};
class DieselEngine : public Engine
{
public:
    DieselEngine() {}

    void start() override
    {
        cout << "Diesel Engine starting with compression ignition" << endl;
    }
};
class ElectricEngine : public Engine
{
public:
    ElectricEngine() {}
    void start() override
    {
        cout << "Electric Engine starting with electric motor" << endl;
    }
};
class Car{
    protected:
    Engine * eng;
    public:

    virtual void drive()=0;
    Car(Engine * e) : eng(e) {}
};
class Sedan:public Car{
    public:
    Sedan(Engine * e) : Car(e) {} 
    void drive()override{
        cout<<"Driving Sedan: ";
        eng->start();
    }

};
class Suv:public Car{
    public:
    Suv(Engine * e) : Car(e) {} 
    void drive()override{
        cout<<"Driving Suv: ";
        eng->start();
    }
};
class Tesla:public Car{
    public:
    Tesla(Engine * e) : Car(e) {}
    void drive() override {
        cout << "Driving Tesla: ";
        eng->start();
    }
};
class Lambergini:public Car{
    public:
    Lambergini(Engine * e) : Car(e) {}
    void drive() override {
        cout << "Driving Lambergini: ";
        eng->start();
    }
};
int main()
{
    Engine * petroEngine= new PetrolEngine();
    Engine * dieselEngine= new DieselEngine();
    Engine * electricEngine= new ElectricEngine();
    Car * sedan = new Sedan(petroEngine);
    Car * sedan2= new Sedan(dieselEngine);
    Car * suv = new Suv(dieselEngine);
    Car * suv2=new Suv(electricEngine);
    

    Car * tesla = new Tesla(electricEngine);
    Car *tesla2=new Tesla(electricEngine);
    Car * lambergini = new Lambergini(petroEngine);
    Car * lambergini2=new Lambergini(electricEngine);
    sedan->drive();
    sedan2->drive();
    suv->drive();
    suv2->drive();
    tesla->drive();
    tesla2->drive();
    lambergini->drive();
    lambergini2->drive();
    delete petroEngine;
    delete dieselEngine;
    delete electricEngine;
    delete sedan;
    delete suv;
    delete tesla;
    delete lambergini;


    return 0;
}