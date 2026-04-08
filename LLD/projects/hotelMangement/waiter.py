from projects.hotelMangement import staff
from staff import Staff
class Waiter(Staff):
    def __init__(self, name, age, id, phoneNumber, employee_id, salary):
        super().__init__(name, age, id, phoneNumber, employee_id, salary)
    def serveOrder(self,roomNumber):
        print(self.getStaffStatus())
        print(f"Serving the order for room {roomNumber}...")
        print("Serving the order...")