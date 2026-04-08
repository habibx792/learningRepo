from ast import List, Try


class Listy:
    def __init__(self, data):
        self.lisy = data
    def __iter__(self):
        self.i = 0
        return self

    def __next__(self):
        if self.i>=len(self.lisy):
            raise StopIteration
        value=self.lisy[self.i]
        self.i+=1
        return value
li = Listy([1,2,3,4,6])
it = iter(li)

while True:
    try:
        print(next(li))
    except StopIteration:
        break