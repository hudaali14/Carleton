mylist=[]
x=3
def measure(num):
    mylist.append(num)
    if len(mylist)>x:
            del mylist[0]
    return mylist
print(measure(6))
print(measure(1))
print(measure(3))
print(measure(100))
def avg():
    total=0
    add=0
    for i in range(len(mylist)):
        total= total+mylist[i]
        add= add+1
    average=total//add
    return average
print(avg())
def minimum():
    mini=mylist[0]
    for i in mylist:
        if mini>i:
            mini=i
    return mini
print(minimum())
def maximum():
    maxi=mylist[0]
    for i in mylist:
        if maxi<i:
            maxi=i
    return maxi
print(maximum())
def isdanger():
    if abs(maximum()-minimum())>10:
        return True
    else:
        return False
print(isdanger())
