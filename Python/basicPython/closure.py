def fun():
    def fun2():
        sum=0
        for i in range(1,11):
            sum+=i
        return sum
    return fun2
allMe=fun()
print(allMe())