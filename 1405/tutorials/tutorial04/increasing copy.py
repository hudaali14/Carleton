current= input("Enter a positive integer or 'q' to quit: ")
if current== "q":
	current=0
count=1
longest=0
while int(current)>0:
	number= input("Enter a positive integer or 'q' to quit: ")
	if number=="q":
		break
	elif int(number)>int(current):
		count= count+1
		current=int(number)
	else:
		if count>longest:
			longest=count
print("Length of longest increasing sequence is", longest)