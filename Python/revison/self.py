class Car:
    def __init__(self, brand, model):
        self.brand = brand  # Set instance attribute
        self.model = model  # Set instance attribute

    def display(self):
        return self.brand, self.model


# Create an instance of Car
car1 = Car("Toyota", "Corolla")
# Call the display method
print(car1.display())
