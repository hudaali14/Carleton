the_string='{"fname":"dave","lname":"mckenney","position":"instructor"}'
def jsontolist(my_string):
    lst=[]
    my_string=my_string.strip("{")
    my_string=my_string.strip("}")
    pairs=my_string.split(",")
    for pair in pairs:
        lst.append([pair])
    return lst
print(jsontolist(the_string))