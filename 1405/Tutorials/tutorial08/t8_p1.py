def wordcount(phrase):
    d={}
    for word in phrase:
        value= phrase.count(word)
        if word!=" " or word!=".":
            d[word]=value
    return d
print(wordcount("This is a sentence. This is another sentence"))