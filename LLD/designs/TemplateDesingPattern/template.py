from typing import final


class PaymentGateWay:
    def __init__(self):
        pass
    def ProcessPayment(self, amount: float):
        self.validAmount(amount)
        self.checkAccount()
        self.sendBank()
        self.saveToDb()
    def validAmount(self, amount: float):
        if amount <= 0:
            raise ValueError("Invalid amount")
    def checkAccount(self):
        # Implementation for checking account
        pass
    def sendBank(self):
        # Implementation for sending payment to bank
        pass
    def saveToDb(self):
        # Implementation for saving payment to database
        pass
class UPIPayMentGateWay(PaymentGateWay):
    def __call__(self, *args, **kwds):
        return super().__call__(*args, **kwds)
    def checkAccount(self):
        print("Checking UPI account...")
    def saveToDb(self):
        print("Saving UPI payment to database...")
    def sendBank(self):
        print("Sending UPI payment to bank...")
    def validAmount(self, amount: float):
        if amount <= 0:
            raise ValueError("Invalid amount")
class CreditCardPaymentGateway(PaymentGateWay):
    def __call__(self, *args, **kwds):
        return super().__call__(*args, **kwds)
    def checkAccount(self):
        print("Checking credit card account...")
    def saveToDb(self):
        print("Saving credit card payment to database...")
    def sendBank(self):
        print("Sending credit card payment to bank...")
    def validAmount(self, amount: float):
        if amount <= 0:
            raise ValueError("Invalid amount")
gate=UPIPayMentGateWay()
gate2=CreditCardPaymentGateway()
gate.ProcessPayment(100.0)
gate2.ProcessPayment(200.0)