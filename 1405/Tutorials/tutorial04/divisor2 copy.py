number=int(input("Enter a number: "))
sum=0
for divisor in range (1, 100):
	if number%divisor==0:
		print(divisor)
		sum= sum+divisor
print("The sum of the divisors is", sum)

prime=0
for divisor2 in range (1, 100):
	if number%divisor2==0:
		prime=prime +1
	divisor= divisor+1
if prime==2:
	print("The number is prime")
else:
	print("the number is not prime")	
