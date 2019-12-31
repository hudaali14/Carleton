price=0
while price==0:
	name=input("""Welcome, to Dino's International Doughnut Shoppe!
Please enter your name to begin: """)
	if name== "":
		print("Sorry that is not a vaild response. Please enter name.")
	else:
		break
while name != "":
	doughnut=input("""Please select a doughnut from the following menu:
 1. Chocolate-dipped Maple Puff ($3.50 each)
 2. Strawberry Twizzler ($2.25 each)
 3. Vanilla Chai Strudel ($4.05 each)
 4. Honey-drizzled Lemon Dutchie ($1.99) """)
	if doughnut== "1":
		amount=input("""How many Chocolate-dipped Maple Puffs would you like to
purchase? """)
		price= float(3.5)*float(amount)
		print(name + ",", "here is your  receipt:")
		print(amount, "Chocolate-dipped Maple Puffs.")
		print("Total Cost: $", round(price,2))
		print("Thank you, have a nice day!")
		break
	elif doughnut== "2":
		amount=input("""How many Strawberry Twizzle would you like to purchase? """)
		price= float(2.25)*float(amount)
		print(name, ", here is your receipt:")
		print(amount, "Strawberry Twizzler.")
		print("Total Cost: $", round(price,2))
		print("Thank you, have a nice day!")
		break
	elif doughnut== "3":
		amount=input("""How many Vanilla Chai Strudel would you like to purchase? """)
		price=float(4.05)*float(amount)
		print(name, ", here is your receipt:")
		print(amount, "Vanilla Chai Strudel.")
		print("Total Cost: $", round(price,2))
		print("Thank you, have a nice day!")
		break
	elif doughnut== "4":
		amount=input("""How many Honey-drizzled Lemon Dutchie would you like to purchase? """)
		price= float(1.99)*float(amount)
		print(name, ", here is your receipt:")
		print(amount, "Honey-drizzled Lemon Dutchie.")
		print("Total Cost: $", round(price, 2))
		print("Thank you, have a nice day!")
		break
	else:
		print("I'm sorry, that's not a valid selection. Please enter a selection from 1-4.")
