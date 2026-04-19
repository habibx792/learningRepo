from http import client


class Car:
    def printInfo(self):
        pass
class TwoWheelCar(Car):
    def __init__(self):
        self.wheel_count = 2
    def printInfo(self):
        print(f"This is a two-wheel car with {self.wheel_count} wheels.")
class FourWheelCar(Car):
    def __init__(self):
        self.wheel_count = 4
    def printInfo(self):
        print(f"This is a four-wheel car with {self.wheel_count} wheels.")
class CarFactory:
    def CreateCar(self):
        pass
class TwoWheelCarFactory(CarFactory):
    def CreateCar(self):
        return TwoWheelCar()
class FourWheelCarFactory(CarFactory):
    def CreateCar(self):
        return FourWheelCar()
class Client:
    def __init__(self,CarType,Factory):
        self.car_type = CarType
        self.factory = Factory
    def printInfo(self):
        self.car_type.printInfo()

car=TwoWheelCar()
car=FourWheelCar()
ali=Client(car, TwoWheelCarFactory())
ali.printInfo()