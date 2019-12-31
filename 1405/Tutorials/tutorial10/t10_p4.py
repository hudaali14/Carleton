mylist1=[1, 3, 5, 7, 9]
mylist2=[2, 4, 6, 8, 10]
def merge(lst1, lst2):
    if lst1!=[] and lst2!=[]:
        if lst1[0]>lst2[0]:
            lst1,lst2=lst2,lst1
        return [lst1[0]]+merge(lst1[1:],lst2)
    return lst1+lst2
print(merge(mylist1,mylist2))

def merge(lst1, lst2):
    lst=[]
    if lst1[0]>lst2[0]:
        return lst.append(lst1[0])
    sort=[lst2[0]]+merge(lst1[1:],lst2[1:])
    return sort

