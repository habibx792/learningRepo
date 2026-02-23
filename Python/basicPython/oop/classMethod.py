class Employee:
    raise_amount = 1.05
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        
    @classmethod
    def set_raise_amount(cls, amount):
        cls.raise_amount = amount

print(Employee.raise_amount)
Employee.set_raise_amount(1.10)
print(Employee.raise_amount)