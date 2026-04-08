class car:
    def __init__(self,name,brand,model,engine):
        self.name=name
        self.brand=brand
        self.model=model
        self.engine=engine
    def printDetail(self):
        print(self.engine)
        print(self.model)
        print(self.name)
        print(self.brand)
totata=car("Civic","Honda",2012,"V8")
totata.printDetail()
        