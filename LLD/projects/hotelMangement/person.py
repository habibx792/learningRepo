from abc import abstractmethod
from projects.hotelMangement.generalInterFace import generalMethod
class Person(generalMethod):
    def __init__(self, name, age, id):
        self._name = name
        self._age = age
        self._id = id
    def printDetails(self):
        print(f"Name: {self._name}, Age: {self._age}, ID: {self._id}")
    @property
    def name(self):
        return self._name
    @name.setter
    def name(self, value):
        self._name = value
    @property
    def age(self):
        return self._age
    @age.setter
    def age(self, value):
        self._age = value
    @property
    def id(self):
        return self._id
    @id.setter
    def id(self, value):
        self._id = value