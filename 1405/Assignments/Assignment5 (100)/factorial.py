def cachedfactorial(num,cache):
    #base case
    if num==1:
        return 1
    #if its not in the dictionary save it, then calculate the result
    if num not in cache:
        cache[num]=num*(cachedfactorial(num-1,cache))
        return cache[num]
    #if it's already in the dictionsry return that result
    if num in cache:
        return cache[num]
d={}
print(cachedfactorial(5, d))
print(cachedfactorial(7, d))
