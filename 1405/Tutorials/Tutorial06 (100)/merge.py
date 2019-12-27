my_list=[1,3,5]
mylist=[2,4,6,8,10]
def merge(lst1, lst2):
    new=[]
    full=lst1+lst2
    for i in range(len(full)):
        mini=min(full)
        full.remove(mini)
        new.append(mini)
    return print(new)
merge(my_list,mylist)

