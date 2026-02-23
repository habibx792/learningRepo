name=input("Enter You Name Plz : \n")
upper=lambda x:x.upper()
print(upper(name))
check = lambda x: "Positive" if x > 0 else "Negative" if x < 0 else "Zero"
print(check(5))   
print(check(-3))  
print(check(0))