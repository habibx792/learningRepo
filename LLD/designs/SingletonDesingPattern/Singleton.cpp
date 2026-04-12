#include <iostream>
#include<mutex>
using namespace std;

class A
{
};
class Singleton
{
private:
    static Singleton *instance;
    static mutex mtx;

private:
    Singleton()
    {
        cout << "Singleton created . New object created." << endl;
    }

public:
    static Singleton *getInstance()
    {
       
        //    this does allow to excute multithread to create two obj
            if (instance == NULL)
            {
                lock_guard<mutex> lock(mtx);
                if(instance == NULL)
                {
                    // this is called double lock so safe if two thread reach at same line of code 
                    instance = new Singleton();
                }
            }
        
        return instance;
    }
};
// static varable are declare outside the class in c++
Singleton *Singleton::instance = NULL;
mutex Singleton::mtx;
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