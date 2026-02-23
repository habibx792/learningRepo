class Person:
    def __init__(self):
        pass
    def __init__(self,name,age,id,gender):
        self.name=name
        self.age=age
        self.id=id
        self.gender=gender
    def __setAge(self,age):
        self.age=age
    def printName(self,age):
        print(self.name)
        if self.age<18:
            self.__setAge(age)
            print(age)
    @property
    def Age(self):
        return self.age
p=Person("Ghulam Habib",10,2323,"Male")
p.printName(32)
print(p.Age)