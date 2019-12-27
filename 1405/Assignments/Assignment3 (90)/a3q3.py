mylist = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'] 
def slice(list, start, end):
    new_list=[]
    if start not in range(len(list)) or end not in range(len(list)):
        return new_list
    else:
        for i in range(start,(end+1)):
            new_list.append(list[i])
    return new_list
#examples
print(slice(mylist,0,9))
print(slice(mylist,3,4))
print(slice(mylist,4,3))
print(slice(mylist,3,8))
print(slice(mylist,4,4))
print(slice(mylist,3,10))
print(slice(mylist,10,4))
