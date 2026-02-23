from platform import machine


# class Person:
#     def __init__(self, name):
#         self.name = name

# class Job:
#     def __init__(self, salary):
#         self.salary = salary

# class Employee(Person, Job):  # Inherits from both Person and Job
#     def __init__(self, name, salary):
#         Person.__init__(self, name)
#         Job.__init__(self, salary)

#     def details(self):
#         print(self.name, "earns", self.salary)

# emp = Employee("Jennifer", 50000)
# emp.details()
class Animal:
    def __init__(self):
        self.name="Animal"
        self.age=0
    def getName(self):
        return self.name
class Machine:
    def __init__(self):
        self.name="Machine"
class Dog(Animal):
    def __init__(self):
        super().__init__()
        self.Color="White"
class  HybridDog(Dog,Machine):
    def __init__(self):
        super().__init__()
        self.Speed=10
        self.height=10

mt=HybridDog()
print(mt.getName())
        
