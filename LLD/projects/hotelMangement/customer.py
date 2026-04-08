from person import Person 
class Customer(Person):
    def __init__(self, name, age, customer_id):
        super().__init__(name, age)
        self._customer_id = customer_id
    def getCustomerId(self):
        return self._customer_id