def multiply(num1, num2):
    if num1=0 or num2=0
        return 0
    if num1==1:
        return num2
    result=num2+multiply(num1-1,num2)
    return result
print(multiply(4,5))
print(multiply(10,7))
print(multiply(11,2))