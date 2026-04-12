#include <iostream>
using namespace std;

class A
{
};
class Singleton
{
private:
    static Singleton *instance;
   
private:
    Singleton()
    {
        cout << "Singleton created . New object created." << endl;
    }
public:
    static Singleton *getInstance()
    {
        return instance;
    }
};
// static varable are declare outside the class in c++
Singleton *Singleton::instance = new Singleton(); 
int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    if (s1 == s2)
    {
        cout << "Both objects point to the same object." << endl;
    }
    else
    {
        cout << "Both objects point to different objects." << endl;
    }
    return 0;
}