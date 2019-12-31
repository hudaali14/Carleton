mylist = [1, 3, 5, 9, 10, 10, 10, 10, 10, 15, 20, 25, 30]
def findstart(lst,value):
    start=0
    end=len(lst)-1
    while start<=end:
        midindex = int(((start+end)/2))
        if lst[midindex]==value and lst[midindex-1]!=value:
            return midindex
        if lst[midindex]==value and lst[midindex-1]==value:
            end=midindex-1
        if lst[midindex] < value:
            start = midindex + 1
        if lst[midindex] > value:
            end = midindex - 1
    return False
print("The first index is:", findstart(mylist, 10))
#     for midindex in range(midindex):
#         if lst[midindex]==value and lst[midindex-1]!=value:
#             return midindex


def findend(lst,value):
    start=0
    end=len(lst)-1
    while start<=end:
        midindex = int(((start+end)/2))
        if lst[midindex]==value and lst[midindex+1]!=value:
            return midindex
        if lst[midindex]==value and lst[midindex+1]==value:
            start=midindex+1
        if lst[midindex] < value:
            start = midindex + 1
        if lst[midindex] > value:
            end = midindex - 1
    return False
#     start=0
#     end=len(lst)-1
#     midindex = int((start+end)/2)
#     for midindex in range(midindex,end):
#         if lst[midindex]==value and lst[midindex+1]!=value:
#             return midindex
print("The last index is:", findend(mylist, 10))

def count(lst, value):
    if value in lst:
        start= findstart(lst, value)
        end= findend(lst, value)
        total=(end-start)+1
        return total
    else:
        print("Sorry value is not in list")
print("The total occurence of the value is:", count(mylist, 35))