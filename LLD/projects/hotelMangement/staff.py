from employee import Employee 
class Staff(Employee):
    def __init__(self, name, age, id, phoneNumber, employee_id, salary):
        super().__init__(name, age, id, phoneNumber, employee_id, salary)
        self.isFree=True
    def getStaffStatus(self):
        return self.isFree
    def working(self):
        if(self.isFree):
            print("Staff is working.")
            self.isFree=False
    