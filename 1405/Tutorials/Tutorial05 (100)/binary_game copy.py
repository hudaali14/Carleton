def pow2(number):
    check=0
    add=0
    while number>0:
        if check<number:
            check=2**add
            add= add+1
        elif number==check:
            break
        else:
            check=check-(2**(add-2))
            break
    return check
print(pow2(2))
print(pow2(12))
print(pow2(20))
print(pow2(284))

def decToBin(float):
    output=""
    pow=pow2(float)
    while True:
        if pow< 1:
            break
        if pow<=float:
            output= output+"1"
            float=float-pow
        else:
            output=output+"0"
        pow=pow/2
    return output
print(decToBin(2))
print(decToBin(10))
print(decToBin(16))

from random import*
win=0
while win>=0:
    rand=randint(0,256)
    print("The integer is", rand)
    guess=input("Guess the binary number of this integer: ")
    right=decToBin(rand)
    if right==guess:
        win+=1
        print("You guessed right")
        print("Answer:", right)
    elif guess=="stop":
            break
    else:
        print("Sorry you guessed wrong")
        print("Answer:", right)
print("You won", win, "times")
