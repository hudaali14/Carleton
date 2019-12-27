def push(stack,value):
    return stack.append(value)
def pop(stack):
    if len(stack)==0:
        return None
    else:
        return stack.pop()
def isempty(stack):
    if len(stack)==0:
        return True
    else:
        return False
def peak(stack):
    if len(stack)>0:
        return stack[-1]