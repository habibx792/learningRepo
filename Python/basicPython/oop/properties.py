class Person:
    def __init__(self,name,age,id,gender):
        self.name=name
        self.age=age
        self.id=id
        self.gender=gender
    def __init__(self):
        pass
    @property
    def Name(self):
        return self.name
    @Name.setter
    def Name(self,name):
        self.name=name
p=Person()
p.Name="Habib"
print(p.Name)
        