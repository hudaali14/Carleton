mylist=[1,3,5,3,4,2,7,8,2,9,5,6,9,9,4,5,6,2,1,8,7,6,5]
def countsort(lst):
    d={}
    newlst=[]
    #saves each item and their frequency to dictionary
    for item in lst:
        value=lst.count(item)
        d[item]=value
    #sorts the newlst using only unique values
    for key in d:
        newlst.append(key)
    newlst=sorted(newlst)
    #then appends the value by the number of times it occurs
    for key in d:
        for i in range(1,d[key]-1):
            newlst.append(key)
    #sorts new list
    newlst=sorted(lst)
    return newlst
print(countsort(mylist))