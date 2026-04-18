#include <iostream>
using namespace std;

class A {
};
class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger() {}
};
class BasicBurger : public Burger {
    public:
    void prepare() override {
        cout << "Preparing Basic Burger" << endl;
    }
};
class StandardBurger:public Burger{
    public:
    void prepare() override {
        cout << "Preparing Standard Burger" << endl;
    }
};
class PremiumBurger:public Burger{
    public:
    void prepare() override {
        cout << "Preparing Premium Burger" << endl;
    }

};
class BurgerFactory{
    public:
    Burger* prepareBurger(const std::string& type) {
        if (type == "basic") {
            return new BasicBurger();
        } else if (type == "standard") {
            return new StandardBurger();
        } else if (type == "premium") {
            return new PremiumBurger();
        }
        return nullptr;
    }
};
int main() {
    BurgerFactory *burgFactor=new BurgerFactory();
    Burger *burger = burgFactor->prepareBurger("basic");
    burger->prepare();

    delete burger;
    delete burgFactor;
    return 0;
}