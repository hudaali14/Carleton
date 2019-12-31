sentence="hello there"
def reverse(phrase):
    if len(phrase)==1:
        return phrase
    newphrase=phrase[-1]+reverse(phrase[:-1])
    return newphrase
print(reverse(sentence))