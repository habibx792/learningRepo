class Dog:
    def __init__(self):
        self.name="Tommy"
        self.age=3
        self.color="Red"
        self.height=20.1
        self.speed=10
        self.favouriteFood="Meat"
        self.length=10
    def __int__(self,name,age,color,height,length,speed,favFood):
        self.name=name
        self.age=age
        self.color=color
        self.height=height
        self.length=length
        self.speed=speed
        self.favouriteFood=favFood
    @staticmethod
    def classInfo():
        print("This is Dog class : ")
    def __str__(self):
        return f"""name : {self.name}, age : {self.age} , Color : {self.color} , Height : 
        {self.height} Length {self.length} , Speed : {self.speed}, FavouriteFood : {self.favouriteFood}"""
    def printPersonalDetail(self):
        print("Name : ",self.name)
        print("Age : ",self.age)
        print("Color : ",self.color)
        print("Height : ",self.height)
        print("Length : ",self.length)
        print("Speed : ",self.speed)
        print("Favourite Food : ",self.favouriteFood)
    
