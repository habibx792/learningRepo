
from projects.hotelMangement.employee import Employee
class Cleaner(Employee):
    def __init__(self, name, age,id,phoneNumber, employee_id, salary):
        super().__init__(name, age, id, phoneNumber, employee_id, salary)
    def cleanRoom(self):
        print("Cleaning the room...")