from abc import abstractmethod
from projects.hotelMangement.generalInterFace import generalMethod
from projects.hotelMangement.bank import Bank
class Person(generalMethod):
    def __init__(self, name, age, id,phoneNumber):
        self.bank=Bank("HBL", "12345")
        self._name = name
        self._age = age
        self._id = id
        self._phoneNumber = phoneNumber

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
    def phoneNumber(self):
        return self._phoneNumber
    @phoneNumber.setter
    def phoneNumber(self, value):
        self._phoneNumber = value
    @property
    def id(self):
        return self._id
    @id.setter
    def id(self, value):
        self._id = value
    def creatBankAccount(self):
        self.bank.regisAccount(self.name,self.age,self.id)
    def getBank(self):
        return self.bank