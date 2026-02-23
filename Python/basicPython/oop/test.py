from graphlib import TopologicalSorter

from construct import car
from dog import Dog
from polymorphism import Animal,Dog,Man,Cat,Donkey
from tool import Tool,Pen,Eraser,Mobile,Pc,Comb
from inheritance import Animal,Man,Male
# hondy=car()
# # hondy.print()
# moti=Dog()
# moti.printPersonalDetail()
# Dog.classInfo()
# print(moti)
# animals=[Dog(),Man(),Cat(),Donkey()]
# for animal in animals:
#     print(animal.sound())

# tools=[Tool(),Pen(),Eraser(),Mobile(),Pc(),Comb()]
# for tool in tools:
#     print(tool.use())
animal=[Animal("Dog",10),Man("ALi",12,23232,"Male"),Male("Habib",22,2323,"Male",False)]
for ani in animal:
    print(ani.name)
