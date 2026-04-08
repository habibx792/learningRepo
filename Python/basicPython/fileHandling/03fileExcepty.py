try:
    file = open("geek.txt", "r")
    content = file.read()
    print(content)
finally:
    file.close()