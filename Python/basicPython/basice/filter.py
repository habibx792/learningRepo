array=[1,2,3,4,5,6,7,8,10,12,1,3,14,111111111111114]
def isEven(n):
    return n%2==0
res=filter(isEven,array)
print(list(res))