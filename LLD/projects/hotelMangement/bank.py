from account import AccountNumber
from projects.hotelMangement.generalInterFace import GeneralMethod
class Bank(GeneralMethod):
    def __init__(self, name, code):
        self.branchName = name
        self.branchCode = code
    def regisAccount(self, holderName, age, id):
        self.AcountList.push(AccountNumber(holderName, age, id))
    def getAccount(self,id):
        for account in self.AcountList:
            if account.person.id == id:
                return account
        return None
    def deposite(self, id, amount):
        if(amount <= 0):
            return False
        account = self.getAccount(id)
        if account:
            account.setBalance(account.balance + amount)
            return True
        return False
    def withdraw(self, id, amount):
        if(amount <= 0):
            return False
        account = self.getAccount(id)
        if account:
            if account.balance >= amount:
                account.setBalance(account.balance - amount)
                return True
        return False
    def transfer(self, from_id, to_id, amount):
        if(amount <= 0):
            return False
        from_account = self.getAccount(from_id)
        to_account = self.getAccount(to_id)
        if from_account and to_account:
            if from_account.balance >= amount:
                from_account.setBalance(from_account.balance - amount)
                to_account.setBalance(to_account.balance + amount)
                return True
        return False
    def printDetails(self):
        print(f"Branch Name: {self.branchName}, Branch Code: {self.branchCode}")
