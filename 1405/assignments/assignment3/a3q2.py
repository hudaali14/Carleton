def ismultiple(a,b):
    if b%a==0:
        return True
    else:
        return False
def commonmultiple(a,b,c):
    if ismultiple(a,c)== True and ismultiple(b,c)== True:
        return True
    else:
        return False
#examples
print(commonmultiple(6,13,3))
print(commonmultiple(3,2,42))
print(commonmultiple(4,5,45))
print(commonmultiple(2,100,100))

num1=int(input("Enter a number: "))
num2=int(input("Enter a number: "))
for i in range(1,101):
    if commonmultiple(num1,num2,i)== True:
        print(i)