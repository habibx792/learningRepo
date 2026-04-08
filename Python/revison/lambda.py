# # x = "hello world my name is ghulam habib i am an architectral engineer and software engineer"
# # upper = lambda x: x.upper()
# # print(upper(x))
# # check = lambda x: "positvit" if x > 0 else "Negative" if x < 0 else "zero"
# # print(check(0))
# from functools import reduce


# evn = lambda x: "even" if x % 2 == 0 else "odd"
# print(evn(3))
# cal = lambda x, y: (x + y, x * y, x / y, x - y)
# print(cal(2, 3))

# num = [
#     1,
#     2,
#     3,
#     343,
#     43,
#     43,
#     23,
#     232,
#     2,
#     32,
#     2,
#     32,
#     24,
#     34,
#     434,
#     343,
#     44,
#     3,
#     43,
#     32,
#     43,
#     34,
#     43,
#     43,
#     434,
#     434,
#     3,
#     43,
#     4343,
#     34,
#     34,
# ]
# # fun = filter(lambda x: x % 2 == 0, num)
# # print(list(fun))
# # env = map(lambda x: x * 2, num)
# # print(list(env))
# sumy = reduce(lambda x, y: x + y, num)
# print(sumy)
print("My favorite colors are", "blue", "green", "red")
my_range_var = range(5)
print("Range:", my_range_var)  # Range: range(0, 5)
print(isinstance("Hello world", str))  # True
print(isinstance(True, bool))  # True
print(isinstance(42, int))  # True
print(isinstance("John Doe", int))  # False
print(isinstance(3, list))
