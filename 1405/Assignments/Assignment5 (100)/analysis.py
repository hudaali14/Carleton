lst=[]
d={}
lst2=[]
d2={}
def load(filein):
    #clears each list and dictionary before each load
    lst.clear()
    lst2.clear()
    d.clear()
    d2.clear()
    #opens file and splits file
    myfile=open(filein,"r").read()
    words=myfile.split(" ")
    #saves each word to a list and dictionary
    for word in words:
        lst.append(word)
        value=lst.count(word)
        d[word]=value
    #saves each letter to a list and dictionary
    phrase="".join(lst)
    for letter in phrase:
        lst2.append(letter)
        value=phrase.count(letter)
        d2[letter]=value
def commonword(newlst):
    temp={}
    highest={}
    count=0
    #checks if lst is empty 
    if lst==[]:
        return None
    #checks if the items in newlst are in the lst. If they are it saves it to a dictionary
    for item in newlst:
        if item in d:
            temp[item]=d[item]
        else:
            #counts the number of items each item in the newlst isn't present in the lst
            count+=1
    #if these two number are equal, then none of the words in the newlst are present in the loaded text
    if len(newlst)==count:
        return None
    #calculates the maximum value of the dictionary 
    maximum=max(temp.values())
    #checks if this maximum value is present in another item in the list, if it is it saves it to a new dictionary
    for key in temp:
        if temp[key]==maximum:
            highest[key]=temp[key]
    #return the dictionary containing all the items with maximum values
    return highest
def commonletter(newlst):
    highest={}
    temp={}
    count=0
    #checks if lst is empty
    if lst==[]:
        return None
    #checks if the items in newlst are in the lst. If they are it saves it to a dictionary
    for item in newlst:
        if item in d2:
            temp[item]=d2[item]
        else:
            #counts the number of items each item in the newlst isn't present in the lst
            count+=1
    #if these two number are equal, then none of the words in the newlst are present in the loaded text
    if len(newlst)==count:
        return None
    #calculates the maximum value of the dictionary
    maximum=max(temp.values())
    #checks if this maximum value is present in another item in the list, if it is it saves it to a new dictionary
    for key in temp:
        if temp[key]==maximum:
            highest[key]=temp[key]
    #return the dictionary containing all the items with maximum values
    return highest
def commonpair(word):
    follow={}
    highest={}
    if word not in d:
        return None
    else:
        #calculates the frequency of the word in lst
        value=lst.count(word)
        #if the value only appears once and it present at the end of the list then no words follow it
        if value==1 and word==lst[len(lst)-1]:
            return None
    #iterates through the list
    for i in range(len(lst)-1):
        #if the word is at index i
        if word==lst[i]:
            #if the word following is not in the dictionary, then save it with a value of one
            if lst[i+1] not in follow:
                follow[lst[i+1]]=1
            #if it is in the dictionary then just up the value by 1
            else:
                follow[lst[i+1]]+=1
    #calculates the maximum value of the dictionary
    maximum=max(follow.values())
    #checks if this maximum value is present in another item in the list, if it is it saves it to a new dictionary
    for key in follow:
        if follow[key]==maximum:
            highest[key]=follow[key]
    #return the dictionary containing all the items with maximum values
    return highest
def countall():
    return len(lst)
def countunique():
    return len(d.keys())

