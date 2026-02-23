# for i in range(1,20,3):
#     print(i)
# listy=[1,2,3,4,5,6,]

# def ui():
#     print("========================")

# for i in listy:
#     print(i)
# i=0
# ui()
# while i!=10:
#     print(i)
#     i+=1

from ctypes.wintypes import PINT

from basicPython.function import hel


i=1
while i<=10:
    
    i+=1
    if i==5:
        continue
    print(i)
#in this case else run only when a loop completed not break by break statement 
else:
    print(i)

for i in "Hello world ":
    print(i)