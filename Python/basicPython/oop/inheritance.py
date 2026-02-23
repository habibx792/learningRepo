class Animal:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def print(self):
        print("Name : ",self.name)
        print("Age : ",self.age)
    def getName(self):
        return self.name
class Man(Animal):
    def __init__(self, name, age,identityNo,gender):
       super().__init__(name,age)
       self.identityNo=identityNo
       self.gender=gender
    
class Male(Man):
    def __init__(self, name, age, identityNo, gender,IsMarried):
        super().__init__(name, age, identityNo, gender)
        self.isMarried=IsMarried

