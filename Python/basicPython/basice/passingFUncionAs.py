def greet(name):
    return f"Welcome : {name}"
def fun1(fun2,name):
    return fun2(name)
print(fun1(greet,"ALi"))

def main():
    def fun1():
        return "I am return fron method"
    return fun1
fun1=main()
print(fun1())
def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

# Storing functions in a dictionary
d = {
    "add": add,
    "subtract": subtract
}

# Calling functions from the dictionary
print(d["add"](5, 3))       
print(d["subtract"](5, 3))