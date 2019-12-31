number=int(input("Enter a number: "))
divisor=1
sum=0
while divisor<100:
	if number%divisor==0:
		print(divisor)
		sum= sum+divisor
	divisor= divisor+1
print("The sum of the divisors is", sum)

divisor2=1
prime=0
while divisor2<100:
	if number%divisor2==0:
		prime= prime+1
	divisor2=divisor2+1
if prime==2:
	print("The number is prime")
else:
	print("The number is not prime")
		
	