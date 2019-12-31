mylist=[["fname","dave"],["lname","mckenney"],["position", "instructor"]]
def listtojson(jsonlist):
    d = {}
    for index in jsonlist:
        d[index[0]] = index[1]
    return d
print(listtojson(mylist))
