print("""The actor being considered is Channing Tatum
The possible movies are: "Magic Mike", "Step Up", "21 Jump Street", "She's The Man".""")

q1= input("Does Channing have another main co-star? ")
if q1== "yes":
	q2= input("Does the character dance? ")
	if q2== "yes":
		print("The movie you are thinking of is 'Step Up'.")
	else:
		print("The movie you are thinking of is '21 Jump Street'.")
else: 
	q3=input("Is the character on a soccer team? ")
	if q3== "yes":
		print("The movie you are thinking of is 'She's The Man'.")
	else: 
		print("The movie you are thinking of is 'Magic Mike'.")