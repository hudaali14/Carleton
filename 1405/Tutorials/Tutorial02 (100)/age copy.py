name = input("Enter you name: ")
birth_year = input("What year were you born " + name + " ? ")
age = 2018 - int(birth_year)
print("Hello, " + name + "." + " You are now " + str(age) + " years old.")