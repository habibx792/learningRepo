import sys
import random
from enum import Enum
class RPS(Enum):
    Rock=1
    Paper=2
    Scissor=3
print(RPS(2))
print(RPS(2))
print(RPS(2))
# print(RPS.Rock.value())
print("====================Rock Paper Ceaser=============================\n")
print("1 for paper \n 2 for rock \n3 for  scciror ")
choice=int(input("Enter Choice : \n"))
if choice<1|choice>3:
    sys.exit("You Muster ener 1,2,3")
computerChoice=random.choice("123")
computerChoice=int(computerChoice)
print("======================")
print
print("you choce : ",str(RPS(choice)))
print("Computer choice ",RPS(computerChoice))
if choice==1 and computerChoice==3:
    print("You win")
elif choice==2 and computerChoice==1:
    print("You Win")
elif choice==3 and computerChoice==2:
    print("!n😂Computer Win")
elif choice==computerChoice:
    print("Draw")
else:
    print("computer win")
