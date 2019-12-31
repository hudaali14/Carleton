myfile= open(input("Enter file name: "), "r")
count=0
passes=0
fails=0
highest=0
lowest=50
avg=0
add=0
for line in myfile:
    #get name
    if count%6==0:
        name=line
        count+=1
        #add counts number of students to use for average
        add+=1
        continue
    #get last name
    elif count%6==1:
        last=line
        count+=1
        continue
    #get student ID
    elif count%6==2:
        num=int(line)
        count+=1
        continue
    #get assignment grade
    elif count%6==3:
        assignment=int(line)
        count+=1
        continue
    #get midterm grad
    elif count%6==4:
        midterm=int(line)
        count+=1
        continue
    #get exam grade
    elif count%6==5:
        exam=int(line)
        count+=1
    #get students grade
    grade=(((25/100)*assignment)+((25/100)*midterm)+((50/100)*exam))
    if grade>=50 and exam>=50:
        #save passes
        passes+=1
        #adds grade to average
        avg+=grade
        #saves student with the highest grade
        if grade>highest:
            highest=grade
            highest_name=name
            highest_last=last
    else:
        #saves fails
        fails+=1
        #add grade to average
        avg+=grade
        #saves student with lowest grade
        if grade<lowest:
            lowest=grade
            lowest_name=name
            lowest_last=last
#calculates average
average=avg/add
#prints final outcome
print("Number of Passes: ", passes)
print("Number of Fails: ", fails)
print("Average Final Grade: ", average)
print("The Highest Grade: ", highest_name.strip(), highest_last.strip(), "-", highest)
print("The Lowest Grade: ", lowest_name.strip(), lowest_last.strip(), "-", lowest)
myfile.close()