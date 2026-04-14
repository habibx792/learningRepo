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
class Character {
public:
    virtual string GetAbilities()const = 0;
    virtual ~Character() = default;
};
class Mario:public Character{
    string GetAbilities()const override{
        return "Mario";
    }
};
class CharacterDecorator:public Character{
public:
    CharacterDecorator(Character* character):character_(character){}

    
private:
protected:
    Character *character_;
};
class FireMario:public CharacterDecorator{
public:
    FireMario(Character* character):CharacterDecorator(character){}
    string GetAbilities()const override{
        return character_->GetAbilities() + " with Fire";
    }
};
class HeightUp:public CharacterDecorator{
public:
    HeightUp(Character* character):CharacterDecorator(character){}
    string GetAbilities()const override{
        return character_->GetAbilities() + " with Height Up";
    }
};
class GunPower:public CharacterDecorator{
public:
    GunPower(Character* character):CharacterDecorator(character){}
    string GetAbilities()const override{
        return character_->GetAbilities() + " with Gun Power";
    }
};
class StartPower:public CharacterDecorator{
public:
    StartPower(Character* character):CharacterDecorator(character){}
    string GetAbilities()const override{
        return character_->GetAbilities() + " with Start Power";
    }
};


int main() {
    Character *mario=new Mario();
    mario=new HeightUp(mario);
    cout<<"After Height Up: " << mario->GetAbilities() << endl;
    mario=new FireMario(mario);
    cout<<"After Fire Mario: " << mario->GetAbilities() << endl;
    mario=new StartPower(mario);
    cout<<"After Start Power: " << mario->GetAbilities() << endl;
    mario=new GunPower(mario);
    cout<<"After Gun Power: " << mario->GetAbilities() << endl;


    return 0;
}