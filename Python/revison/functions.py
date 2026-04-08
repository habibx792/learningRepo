from cProfile import label


def myFunc(v):
    print(v + 2)

    def fun():
        print(v + 3)

    fun()


myFunc(30)


# def cube(x):
#     return x * x * x


# print(cube(3))
cube = lambda x: x * x * x
print(cube(3))


# def fun():
#     s += " GFG"  # Error: Python thinks s is local
#     print(s)


# s = "I love GeeksforGeeks"
# fun()


# def fun():
#     global s
#     s += " GFG"  # Modify global variable
#     print(s)
#     s = "Look for GeeksforGeeks Python Section"
#     print(s)
# s = "Python is great!"


# fun()
# print(s)
def printy():
    global num
    num += 32
    print(num)


num = 323
printy()
print(num)
