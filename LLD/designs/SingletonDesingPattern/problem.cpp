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

class A {
};
class Singleton{
    public:
    Singleton(){
        cout<<"Singleton created . New object created."<<endl;
    }
};
int main() {
    // problem 
    Singleton *s1=new Singleton();
    Singleton *s2=new Singleton();
    if(s1==s2){
        cout<<"Both pointers point to the same object."<<endl;
    }
    else{
        cout<<"Point to different objects."<<endl;
    }

    return 0;
}