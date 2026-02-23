import select


class Person:
    def __init__(self,name,salary,age):
        self._age=age
        self.__salary=salary
        self.name=name
    @property
    def Salary(self):
        return self.__salary
    @property
    def Age(self):
        return self._age
p=Person(323,"ah",23)
print(p.Age)
print(p.Salary)