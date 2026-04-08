num=int(input("Enter a number "))
div=int(input(f"{num} divid by "))
try:
    ans=num/div
    print("ans : ",{ans})
except ZeroDivisionError:
    print("Divided by Zero")