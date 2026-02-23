def method(x):
    for i in x:
        print(i)
listy=[1,2,3,45,5]
method(listy)
# method(1)
def hel(name):
    name="Hi Genetel  "+name
    def greet(name):
        print(name)
    greet(name)
name="Ghulam Habib"
hel(name)
print(name)
def pow(x,pow=2):
    ans=1
    for i in range(pow):
        # print(i)
        ans*=x
    return ans
ans=pow(2,3)
print(ans)
def factorial(x):
    if x==0:
        return 1
    else:
     return   x*factorial(x-1)
ans=factorial(5)
print(ans)
numbers=[1,2,3,4,5]
def sum(listy,i):
    if i>=len(listy):
        return 0
    return sum(listy,i+1)+listy[i-1]
print(sum(numbers,0))
def myFun(*args, **kwargs):
    print("Non-Keyword Arguments (*args):")
    for arg in args:
        print(arg)

    print("\nKeyword Arguments (**kwargs):")
    for key, value in kwargs.items():
        print(f"{key} == {value}")

# Function call with both types of arguments
myFun('Hey', 'Welcome', first='Geeks', mid='for', last='Geeks')
def methoy(*args):
    sum=0
    for arg in args:
        sum+=arg
    return sum
print(methoy(1,2,3,4,5))
def myArga(**kwargs):
    for key,value in kwargs.items():
        print(f"{key} == {value}")
myArga(first='Geeks', mid='for', last='Geeks')


lambdaMethod=lambda x:x*x*x
print(lambdaMethod(3))