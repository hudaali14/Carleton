my_string='{"fname":"dave","lname":"mckenney","position":"instructor"}'
def setvalue(dictionary, oldkey, newvalue):
    pairs=[]
    for key in dictionary:
        dictionary[oldkey]=newvalue
        pairs.append([key,dictionary[key]])
    return pairs
print(setvalue(my_string,"position", "president"))