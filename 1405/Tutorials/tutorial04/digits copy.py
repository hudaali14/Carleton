number= int(input("Enter an integer: "))
count=0
while number>0:
	number= number//10
	count=count+1
print("There are", count, "digits in that number")