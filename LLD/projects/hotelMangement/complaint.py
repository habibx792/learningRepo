from person import Person
from projects.hotelMangement import dept
class Complaint:
    def __init__(self, customer, description, departmentName,id):
        self.customer = customer
        self.description = description
        self.dep=dept(departmentName,id)
        self.isResolved = False
    def __str__(self):
        return f"Customer: {self.customer}, Description: {self.description}, Resolved: {self.isResolved}"
    def getComplaint(self):
        return self.customer, self.description
    def getComplainStatus(self):
        return self.isResolved
    def getResolved(self):
        if(not self.isResolved):
            self.dep.calling()
            self.isResolved = True
            print("Complaint resolved.")
    def setResolved(self):
        self.isResolved = True
    