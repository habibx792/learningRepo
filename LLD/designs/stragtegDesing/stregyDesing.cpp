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
// algo rigthms
class TalkAble
{
public:
    TalkAble()
    {
    }
    virtual void Talk() = 0;
};
class WalkAble
{
public:
    WalkAble()
    {
    }
    virtual void Walk() = 0;
};
class FlyAble
{
public:
    FlyAble()
    {
    }
    virtual void Fly() = 0;
};
class NormalTalkAble : public TalkAble
{
public:
    NormalTalkAble()
    {
    }
    void Talk() override
    {
        cout << "Talking normally" << endl;
    }
};
class NotTalkAble : public TalkAble
{
public:
    NotTalkAble()
    {
    }
    void Talk() override
    {
        cout << "Cannot talk" << endl;
    }
};
class NormalWalkAble : public WalkAble
{
public:
    NormalWalkAble()
    {
    }
    void Walk() override
    {
        cout << "Walking on two legs" << endl;
    }
};
class NotWalkAble : public WalkAble
{
public:
    NotWalkAble()
    {
    }
    void Walk() override
    {
        cout << "Cannot walk" << endl;
    }
};
class NormalFlyAble : public FlyAble
{
public:
    NormalFlyAble()
    {
    }
    void Fly() override
    {
        cout << "Flying with wings" << endl;
    }
};
class NotFlyAble : public FlyAble
{
public:
    NotFlyAble()
    {
    }
    void Fly() override
    {
        cout << "Cannot fly" << endl;
    }
};
class Robot
{
    string RobId;
    string name;
    FlyAble *flyingBehavior;
    WalkAble *walkingBehavior;
    TalkAble *talkingBehavior;

public:
    Robot(string name, string id, FlyAble *p, WalkAble *wk, TalkAble *tal) : RobId(id)
    {
        this->flyingBehavior = p;
        this->walkingBehavior = wk;
        this->talkingBehavior = tal;
        this->name = name;
    }
    void printInfo()
    {
        cout << "Robot: " << this->name << " (ID: " << this->RobId << ")" << endl;
    }

    virtual void fly()
    {
        flyingBehavior->Fly();
    }
    virtual void walk()
    {
        walkingBehavior->Walk();
    }
    virtual void talk()
    {
        talkingBehavior->Talk();
    }
};
class UI
{

public:
    UI()
    {
    }
    static void LinerDraw()
    {
        cout << "===========================================";
    }
    static void spaceDraw(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << " ";
        }
    }
    static void newLineDraw(int n = 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << endl;
        }
    }
};

int main()
{
    FlyAble *flyingBehavior = new NormalFlyAble();
    WalkAble *walkingBehavior = new NormalWalkAble();
    TalkAble *talkingBehavior = new NormalTalkAble();

    UI::LinerDraw();
    Robot robot("Wiliaam X", "Robot1", flyingBehavior, walkingBehavior, talkingBehavior);
    robot.printInfo();
    robot.talk();
    robot.talk();
    robot.fly();
    UI::newLineDraw(3);
    FlyAble *dogFlyingBehavior = new NotFlyAble();
    WalkAble *dogWalkingBehavior = new NormalWalkAble();
    TalkAble *dogTalkingBehavior = new NormalTalkAble();
    Robot dog("Willy", "Dog1", dogFlyingBehavior, dogWalkingBehavior, dogTalkingBehavior);
    dog.printInfo();
    dog.fly();
    dog.walk();
    dog.talk();

    return 0;
}