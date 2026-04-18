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
class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};
class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Burger" << endl;
    }
};
class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Burger" << endl;
    }
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Burger" << endl;
    }
};
class simpleMeetBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Simple Meat Burger" << endl;
    }
};
class standardMeetBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Meat Burger" << endl;
    }
};
class premiumMeetBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Meat Burger" << endl;
    }
};
class BurgerFactory
{
public:
    virtual Burger *createBurger(string type) = 0;
    virtual ~BurgerFactory() {}
};
class SinghBurgers : public BurgerFactory
{
public:
    Burger *createBurger(string type) override
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "standard")
        {
            return new StandardBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }

        return nullptr;
    }
};
class KingBurger : public BurgerFactory
{
public:
    Burger *createBurger(string type) override
    {
        if (type == "basic")
        {
            return new simpleMeetBurger();
        }
        else if (type == "standard")
        {
            return new standardMeetBurger();
        }
        else if (type == "premium")
        {
            return new premiumMeetBurger();
        }
        return nullptr;

        // Implementation for king burger creation
    }
};
int main()
{
    string type = "basic";
    BurgerFactory *sFac = new SinghBurgers();
    Burger *budoBurg = sFac->createBurger(type);
    budoBurg->prepare();
    BurgerFactory *kFac = new KingBurger();
    Burger *meeto = kFac->createBurger(type);
    meeto->prepare();
    delete budoBurg;
    delete meeto;
    delete sFac;
    delete kFac;

    return 0;
}