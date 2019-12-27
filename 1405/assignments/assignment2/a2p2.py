choc=0
straw=0
van=0
honey=0
total=0
while total==0:
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
 4. Honey-drizzled Lemon Dutchie ($1.99)
 5. No more doughnuts. """)
	if doughnut== "1":
		amount=int(input("""How many Chocolate-dipped Maple Puffs would you like to
purchase? """))
		choc += amount
		total += (float(3.5)*float(amount))
	elif doughnut== "2":
		amount=int(input("""How many Strawberry Twizzle would you like to purchase? """))
		straw += amount
		total += (float(2.25)*float(amount))
	elif doughnut== "3":
		amount=int(input("""How many Vanilla Chai Strudel would you like to purchase? """))
		van += amount
		total +=(float(4.05)*float(amount))
	elif doughnut== "4":
		amount=int(input("""How many Honey-drizzled Lemon Dutchie would you like to purchase? """))
		honey += amount
		total += (float(1.99)*float(amount))
	elif doughnut== "5":
		break
	else:
		print("I'm sorry, that's not a valid selection. Please enter a selection from 1-5.") 
print(name + ",", "Here's your receipt:")
if choc>0:
	choc_print=print(choc, "Chocolate-dipped Maple Puffs")
if straw>0:
	straw_print=print(straw, "Strawberry Twizzle")
if van>0:
	van_print=print(van, "Vanilla Chai Strudel")
if honey>0:
	honey_print=print(honey, "Honey-drizzled Lemon Dutchie")
print("Total cost: $", round(total, 2)) 
print("Thank you have a nice day!")