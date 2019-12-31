operation=input("""(A)ddition
(S)ubtration
(M)ultiplication
(D)ivision (Long)
Please select an operation from the list above: """)
if operation !="A" and operation !="S" and operation !="M" and operation !="D":
	print("This program does not support the operation", "'", operation, "'")
	operation=input("""(A)ddition
(S)ubtration
(M)ultiplication
(D)ivision (Long)
Please select an operation from the list above: """)
num1= int(input("Please provide the 1st integer: "))
num2= int(input("Please provide the 2nd integer: "))
if operation== "A":
	print(num1, "+", num2, "=", num1+num2)
elif operation== "S":
	print(num1, "-", num2, "=", num1-num2)
elif operation== "M":
	print(num1, "*", num2, "=", num1*num2)
else:
	operation== "D"
	print(num1, "/", num2, "=", num1//num2, "with a remainder", num1%num2)
