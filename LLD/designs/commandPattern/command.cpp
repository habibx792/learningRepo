#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
};

class Light
{
public:
    void on() { cout << "Light is on" << endl; }
    void off() { cout << "Light is off" << endl; }
};

class Fan
{
public:
    void on()
    {
        cout << "Fan is on" << endl;
    }
    void off()
    {
        cout << "Fan is off" << endl;
    }
};

class LightCommand : public Command
{
private:
    Light *light;

public:
    LightCommand(Light *l) : light(l) {}

    void execute() override { light->on(); }
    void undo() override { light->off(); }
};

class FanCommand : public Command
{
private:
    Fan *fan;

public:
    FanCommand(Fan *f) : fan(f) {}

    void execute() override { fan->on(); }
    void undo() override { fan->off(); }
};

class NoCommand : public Command
{
public:
    void execute() override
    {
        cout << "No command assigned" << endl;
    }
    void undo() override
    {
        cout << "Nothing to undo" << endl;
    }
};

class RemoteControl
{
private:
    static const int NUMBER_OF_BUTTONS = 4;
    vector<Command *> commands;
    vector<bool> buttonPressed;

public:
    RemoteControl() : commands(NUMBER_OF_BUTTONS, nullptr),
                      buttonPressed(NUMBER_OF_BUTTONS, false)
    {

        for (int i = 0; i < NUMBER_OF_BUTTONS; i++)
        {
            commands[i] = new NoCommand();
        }
    }

    ~RemoteControl()
    {

        for (Command *cmd : commands)
        {
            delete cmd;
        }
    }

    void setCommand(int index, Command *command)
    {
        if (index >= 0 && index < NUMBER_OF_BUTTONS)
        {
            delete commands[index];
            commands[index] = command;
            buttonPressed[index] = false;
        }
    }

    void pressButton(int index)
    {
        if (index >= 0 && index < NUMBER_OF_BUTTONS)
        {
            if(buttonPressed[index])
            {
                commands[index]->execute();
              
            }
            else{
                commands[index]->undo();
               
            }
            buttonPressed[index]=!buttonPressed[index];
            
        }
    }

    void undoButton(int index)
    {
        if (index >= 0 && index < NUMBER_OF_BUTTONS && buttonPressed[index])
        {
            commands[index]->undo();
            buttonPressed[index] = false;
        }
    }
};

int main()
{

    Light *livingRoomLight = new Light();
    Fan *ceilingFan = new Fan();

    LightCommand *lightCmd = new LightCommand(livingRoomLight);
    FanCommand *fanCmd = new FanCommand(ceilingFan);

    RemoteControl remote;
    remote.setCommand(0, lightCmd);
    remote.setCommand(1, fanCmd);

    cout << "=== Testing Remote Control ===" << endl;
    remote.pressButton(0);
    remote.pressButton(1);
    remote.pressButton(2);

    cout << "\n=== Testing Undo ===" << endl;
    remote.undoButton(0);
    remote.undoButton(1);

    return 0;
}