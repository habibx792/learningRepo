# li = [100, 200, 300]
# it = iter(li)

# # Iterate until StopIteration is raised
# while True:
#     try:
#         print(next(it))
#     except StopIteration:
#         print("End of iteration")
#         break
text="hello world this is big text from randomly file from dp world and i am learning pythog"
it=iter(text)
while True:
        try:
            print(next(it))
        except StopIteration:
             print("End")
             break