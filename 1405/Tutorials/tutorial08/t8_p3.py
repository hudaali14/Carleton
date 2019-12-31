my_string='{"fname":"dave","lname":"mckenney","position":"instructor"}'
def jsontodictionary(string):
    d={}
    string=string.strip("{")
    string=string.strip("}")
    string=string.replace('"',"")
    string=string.split(",")
    lst=[]
    count=0
    for i in string:
        lst.append(i.split(":"))
        d[lst[count][0]]=lst[count][1]
        count+=1
    return d
print(jsontodictionary(my_string))


# def getvalue(jsonlist, key):
#     value= jsonlist.get()
#     return value
# print(getvalue(my_string,"position"))

# def setvalue(dictionary, oldkey, newvalue):
#     pairs=[]
#     for key in dictionary:
#         dictionary[oldkey]=newvalue
#         pairs.append([key,dictionary[key]])
#     return pairs
# print(setvalue(my_string,"position", "president"))