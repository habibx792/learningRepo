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
        cout << "Preparing Basic Burger with sauce, lemon onion " << endl;
    }
};
class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Burger with sauce, lettuce, tomato " << endl;
    }
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Burger with sauce, lettuce, tomato, cheese " << endl;
    }
};
class SimpleMeetBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Simple Meat Burger" << endl;
    }
};
class StandardMeetBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Meat Burger" << endl;
    }
};
class PremiumMeetBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Meat Burger" << endl;
    }
};
class GarlicBread
{
public:
    virtual void prepare() = 0;
    virtual ~GarlicBread() {}
};
class BasicGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Garlic Bread, with onion " << endl;
    }
};
class StandardBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Garlic Bread, with onion, garlic " << endl;
    }
};
class PremiumBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Garlic Bread, with onion, garlic, cheese " << endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *createBurger(string type) = 0;
    virtual GarlicBread *createGarlicBread(string type) = 0;
    virtual ~BurgerFactory() {}
};
class SinglyBurgerFactory : public BurgerFactory
{
public:
    Burger *createBurger(string type)override
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
    GarlicBread *createGarlicBread(string type)override
    {
        if (type == "basic")
        {
            return new BasicGarlicBread();
        }
        else if (type == "standard")
        {
            return new StandardBread();
        }
        else if (type == "premium")
        {
            return new PremiumBread();
        }
        return nullptr;
    }
};
class KingFactory : public BurgerFactory
{
public:
    Burger *createBurger(string type) override
    {
        if (type == "basic")
        {
            return new SimpleMeetBurger();
        }
        else if (type == "standard")
        {
            return new StandardMeetBurger();
        }
        else if (type == "premium")
        {
            return new PremiumMeetBurger();
        }
        return nullptr;
    }
    GarlicBread *createGarlicBread(string type) override
    {
        // Implementation for creating garlic bread in KingFactory
        if (type == "basic")
        {
            return new BasicGarlicBread();
        }
        else if (type == "standard")
        {
            return new StandardBread();
        }
        else if (type == "premium")
        {
            return new PremiumBread();
        }
        return nullptr;
    }
};
int main()
{

    string type = "basic";
    BurgerFactory *factory = new SinglyBurgerFactory();
    Burger *burger = factory->createBurger(type);
     type="standard";
    GarlicBread *bread = factory->createGarlicBread(type);
    if (burger)
    {
        burger->prepare();
        delete burger;
    }
    if (bread)
    {
        bread->prepare();
        delete bread;
    }
    BurgerFactory *kFactory = new KingFactory();
    Burger * kBurger= kFactory->createBurger("basic");
    GarlicBread *kBread = kFactory->createGarlicBread("standard");
    if (kBurger)
    {
        kBurger->prepare();
        delete kBurger;
    }
    if (kBread)
    {
        kBread->prepare();
        delete kBread;
    }

    delete factory;
    delete kFactory;
    return 0;
}