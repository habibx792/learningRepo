from mimetypes import init
from typing import Self


class Employee:
    pass
class Person:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def print(self):
        print("Name : ",self.name)
        print("Age : ",self.age)

p=Person("ali",30)
p.print()