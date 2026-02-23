# A higher-order function that takes another function as an argument
# def fun(f, x):
#     return f(x)

# # A simple function to pass
# def square(x):
#     return x * x
# res = fun(square, 5) # Using apply_function to apply the square function
# print(res)
#a higher order method
def mySumMult(f,x):
    x+=2
    return f(x)
sqr=lambda x:x*x
res=mySumMult(sqr,2)
print(res)