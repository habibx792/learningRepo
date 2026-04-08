class Item:
    def __init__(self, name, price):
        self.name = name
        self.price = price
    def getPrice(self):
        return self.price
    def getName(self):
        return self.name
class Menu:
    def __init__(self):
        self.items = []
    def add_item(self, item):
        self.items.append(item)
    def remove_item(self, item):
        self.items.remove(item)
    def render(self):
        for item in self.items:
            print(item.name, item.price)