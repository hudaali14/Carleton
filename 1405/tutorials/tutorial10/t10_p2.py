newlst=[2, 8, 3, 1, 5, 6, 4, 9, 11, 10]
def insertionsort(lst):
    for i in range(1, len(lst)):
        j=i
        while j>0 and lst[j-1]>lst[j]:
            lst[j-1], lst[j]=lst[j], lst[j-1]
            j=j-1
    return lst
print(insertionsort(newlst))