mylist = [10, 20, 40, 45, 55]
def gallopingsearch(lst,searchvalue):
    start=0
    end=1
    while end<len(lst) and lst[-1]<searchvalue:
        start=end
        end=end*2
	if end>len(lst)-1:
		end=len(lst)-1
    return binarysearch(lst, start, end, searchvalue)
def binarysearch(items, start, end, value):
    while start <= end:
        midindex = int((start+end)/2)
        if items[midindex] == value:
            return True
        if items[midindex] < value:
            start = midindex + 1
        if items[midindex] > value:
            end = midindex - 1
    return False
print(gallopingsearch(mylist, 20))
print(gallopingsearch(mylist, 56))
# def binarysearch(items,start, end, value):
	# if start <= end:
	# 	midindex = int(start+((end-start)/2))	
	# 	if items[midindex] == value:
	# 		return midindex
	# 	if items[midindex] > value:
    #         binarysearch(list,midindex+1,end,value)
	# 	else:
    #         if items[midindex] < value:
	# 		    binarysearch(list,midindex-1,start,value)
	# else:
    #     return False
