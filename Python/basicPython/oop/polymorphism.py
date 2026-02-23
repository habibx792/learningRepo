from ast import AnnAssign


class Animal:
    def sound(self):
        return "Some Generic Sound"
class Dog(Animal):
    def sound(self):
        return "Dog Bark"
class Cat(Animal):
    def sound(self):
        return "Meow"
class Man(Animal):
    def sound(self):
        return "Speek"
class Donkey(Animal):
    def sound(self):return "Dhoncho Dhoncho"
