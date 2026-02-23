number=str(3232)
print(type(number))
number=int(number)
print(type(number))
desc='''              Hello world  my name is Ghulam habib
                    i am software engirneer at ntu       dfasdf                         '''
print(desc)
sent="i \'m \\software engineer \t hey \n i am boy"
print(sent)
sent ="NAME"
print(sent.lower())
sent=sent.upper()
print(sent)
desc=desc.title()
print(desc)
desc=desc.replace("Hello","Bello")
print(desc)
lenDesc=len(desc)
print(lenDesc)
desc=desc.lstrip()
lenDesc=len(desc)
print(lenDesc)
print("Coffee ".ljust(10,'.')+"$1".rjust(10,"."))
name="ali is ali hassan"
ch =name[1]
print(name[1])
print(ch)
print(name[3:9])
print(name.startswith("a"))
print(name.startswith("l"))
price=int(300)
print(price)

compNumber=5+4j
print(compNumber)
print(compNumber.real)
print(compNumber.imag)

gpa=-323.3323
print(abs(gpa))
print(abs(round(gpa,1)))