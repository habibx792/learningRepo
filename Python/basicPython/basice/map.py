


from functools import reduce


carNum=[1,2,3,4,5,6,7,8]
DoubleCar=map(lambda x:x*2,carNum)
print(list(DoubleCar))

carNum = [1, 2, 3, 4, 5, 6, 7, 8]
sumNum = sum(carNum)
print(sumNum)  

ans=reduce(lambda x,y:x+y,carNum)
print(ans)