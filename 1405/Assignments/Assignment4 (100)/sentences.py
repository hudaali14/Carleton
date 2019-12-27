def startwords(string):
    lst=[]
    sentences=string.split(".")
    for sentence in sentences:
        words=sentence.split(" ")
        for word in words:
            if word in lst:
                break
            elif word!="":
                lst.append(word)
                break
    return lst

def endwords(string):
    lst=[]
    sentences=string.split(" ")
    for sentence in sentences:
        if sentence.find(".")>1:
            end=sentence.strip(".")
            if end not in lst:
                lst.append(end)
    return lst
