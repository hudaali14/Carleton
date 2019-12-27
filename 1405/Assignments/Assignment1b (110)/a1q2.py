from random import *
number= randint(1,100)
print(number)
guess=input("Guess a number between 0-100 ")
far=abs(int(guess)-number)
print("Your guess was", far, "from the number")
	