# a=[1,2,4,5,6]
# res=[val**2 for val in a]
# print(res)
# res=[val**2 for val in a if val%2==1]
# print(res)
# c=[(x,y,z) for x in range(0,5) for y in range(0,5) for z in range(0,5)]
# print(c)
mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
res=[val for row in mat for val in row]
print(res)