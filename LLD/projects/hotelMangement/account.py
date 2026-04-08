import random

from person import Person
from generalInterFace import generalMethod
class AccountNumber:
    def __init__(self,holderName,age,id):
        self.person=Person(holderName,age,id)
        self.accountNumber=random.randint(100000, 999999)
        self.balance=0
    @property
    def balance(self):
        return self.balance
    @balance.setter
    def balance(self, amount):
        if(amount>0 and isinstance(amount, (int, float))):
            self.balance = amount
    def setBalance(self, amount):
        if(amount>0 and isinstance(amount, (int, float))):
            self.balance = amount
    