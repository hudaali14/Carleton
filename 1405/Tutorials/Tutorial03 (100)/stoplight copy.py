color=input("What color is the traffic light? ")
distance= float(input("What is the distance from the intersection? "))
speed= float(input("What is the speed of the car in meters per second? "))
if (color== "yellow" and distance== speed*5) or (color== "red" and distance== speed*2) or (color== "green"):
	print("Go")
else:
	print("Stop")
	