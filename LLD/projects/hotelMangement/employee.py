from person import Person
class Employee(Person):
    def __init__(self, name, age, id, empId, salary):
        super().__init__(name, age, id)
        self._empId = empId
        self._salary = salary
    @property
    def empId(self):
        return self._empId
    @empId.setter
    def empId(self, value):
        self._empId = value
    @property
    def salary(self):
        return self._salary
    @salary.setter
    def salary(self, value):
        self._salary = value