mylist2=[[2,15],[1,10],[8,9],[7,4],[1,20],[2,4]]
import math
def combsort(input):
    gap=len(input)
    shrink=1.3
    sorted=False
    while sorted==False:
        gap=int(gap//shrink)
        if gap>1:
            sorted=False
        else:
            gap=1
            sorted=True
        i=0
        while i+gap<len(input):
            distance1=math.sqrt(((input[i][0])**2)+((input[i][1])**2))
            distance2=math.sqrt(((input[i+1][0])**2)+((input[i+1][1])**2))
            if distance2<distance1:
                input[i],input[i+1]=input[i+1],input[i]
                sorted=False
            i=i+1
combsort(mylist2)
print(mylist2)

