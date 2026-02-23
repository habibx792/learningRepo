from collections import Counter
arr=[1,1,2,3,3,4,5,6,4,3,3,2,1,2,3,1,2]
cnt=Counter(arr)
print(cnt) 
ctr1 = Counter([1, 2, 2, 3, 3, 3]) # From a list
ctr2 = Counter({1: 2, 2: 3, 3: 1}) # From a dictionary
ctr3 = Counter('hello') # From a string

print(ctr1)
print(ctr2)
print(ctr3)
ctr = Counter([1, 2, 2, 3,  3])
common = ctr.most_common(3)
print(common)