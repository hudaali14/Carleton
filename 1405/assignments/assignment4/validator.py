import mystack
def isvalid(statement):
    thestack=[]
    count=0
    for item in statement:
        if item=="(" or item=="[" or item=="{":
            mystack.push(thestack,item)
            count+=1
        else:
            if item==")":
                if mystack.peak(thestack)=="(":
                    mystack.pop(thestack)
                    count+=1
            elif item=="]":
                if mystack.peak(thestack)=="[":
                    mystack.pop(thestack)
                    count+=1
            elif item=="}":
                if mystack.peak(thestack)=="{":
                    mystack.pop(thestack)
                    count+=1
    length=statement.count("(")+statement.count(")")+statement.count("[")+statement.count("]")+statement.count("{")+statement.count("}")
    if len(thestack)==0 and count==length: 
        return True
    else:
        return False
    
    
    
    
    # left1=statement.count("(")
    # right1=statement.count(")")
    # left2=statement.count("[")
    # right2=statement.count("]")
    # left3=statement.count("{")
    # right3=statement.count("}")
    # if left1==right1 and left2==right2 and left3==right3:
    #    return True
    # else:
    #     return False
