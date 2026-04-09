from person import Person
from employee import Employee
from complaint import Complaint
from projects.hotelMangement import person
class Manager(Employee):
    def __init__(self, name, age, id, phone_number, employee_id, salary):
        super().__init__(name, age, id, phone_number, employee_id, salary)
        self.complaintList = []   # list to store complaints
    def getAComplain(self,p):
        self.complaintList.append(self,p)
    def printDetails(self):
        for complaint in self.complaintList:
            print(complaint)