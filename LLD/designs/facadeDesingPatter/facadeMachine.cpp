#include <iostream>
using namespace std;

class PowerSupply
{
    bool isOn = false;

public:
    void turnOn()
    {
        cout << "Power supply turned on\n";
        isOn = true;
    }
    void turnOff()
    {
        cout << "Power supply turned off\n";
        isOn = false;
    }
    bool getStatus() { return isOn; }
};

class CoolingSystem
{
    bool isRunning = false;

public:
    void startCooling()
    {
        cout << "Cooling system started\n";
        isRunning = true;
    }
    void stopCooling()
    {
        cout << "Cooling system stopped\n";
        isRunning = false;
    }
    bool getStatus() { return isRunning; }
};

class OilSystem
{
    bool isPumping = false;

public:
    void startOilPump()
    {
        cout << "Oil pump started\n";
        isPumping = true;
    }
    void stopOilPump()
    {
        cout << "Oil pump stopped\n";
        isPumping = false;
    }
    bool getStatus() { return isPumping; }
};

class EngineSystem
{
    bool isRunning = false;

public:
    void startEngine()
    {
        cout << "Engine started\n";
        isRunning = true;
    }
    void stopEngine()
    {
        cout << "Engine stopped\n";
        isRunning = false;
    }
    bool getStatus() { return isRunning; }
};

class ElectricWireSystem
{
    bool isFit = false;

public:
    void runWires()
    {
        cout << "Electric wires running\n";
        isFit = true;
    }
    void stopWires()
    {
        cout << "Electric wires stopped\n";
        isFit = false;
    }
    bool getStatus() { return isFit; }
};

class Facade
{
    PowerSupply power;
    CoolingSystem cooling;
    OilSystem oil;
    ElectricWireSystem wires;
    EngineSystem engine;

public:
    void turnOnMachine()
    {
        if (!power.getStatus())
            power.turnOn();
        if (!oil.getStatus())
            oil.startOilPump();
        if (!cooling.getStatus())
            cooling.startCooling();
        if (!wires.getStatus())
            wires.runWires();
        if (!engine.getStatus())
            engine.startEngine();
    }

    void turnOffMachine()
    {
        if (engine.getStatus())
            engine.stopEngine();
        if (wires.getStatus())
            wires.stopWires();
        if (cooling.getStatus())
            cooling.stopCooling();
        if (oil.getStatus())
            oil.stopOilPump();
        if (power.getStatus())
            power.turnOff();
    }
};

int main()
{
    Facade facade;
    facade.turnOnMachine();
    cout << "------\n";
    facade.turnOffMachine();

    return 0;
}