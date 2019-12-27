maximum_q=10
def enqueue(queue, value):
    if len(queue)<maximum_q:
        queue.append(value)
        return True
    else:
        return False
def dequeue(queue):
    if len(queue)>0:
        first=queue[0]
        queue.pop(0)
        return first
    else:
        return None
def peek(queue):
    if len(queue)>0:
        return queue[0]
    else:
        return None
def isempty(queue):
    if len(queue)>0:
        return True
    else:
        return False
def multienqueue(queue,items):
    numitems=0
    for item in items:
        if len(items)<0 or len(queue)<maximum_q:
            queue.append(item)
            numitems=numitems+1
    return numitems
def multidequeue(queue,number):
    new=[]
    while True:
        if len(queue)==0 or len(new)>=number:
            break
        else:
            new.append(queue[0])
            queue.pop(0)
    return new
