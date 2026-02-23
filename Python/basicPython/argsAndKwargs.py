def sum(*args):
    ans=0
    for num in args:
        ans+=num
    return ans
print(sum(1,2,3,4,5,6,7,8,9,10))

def introduce(**kwargs):
    for k, v in kwargs.items():
        print(k, ":", v)
introduce(Science=32, Math=323)