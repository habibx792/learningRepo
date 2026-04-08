# Function modifies the first element of list
def myFun(x):
    x[0] = 20


lst = [10, 11, 12, 13]
print(lst)
myFun(lst)
print(lst)  # list is modified


# Function tries to modify an integer
def myFun2(x):
    x = 20


a = 10
print(a)
myFun2(a)
print(a) 
