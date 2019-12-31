stock=[12, 14, 6, 10, 16]
def minimum():
    mini=stock[0]
    for i in stock:
        if mini>i:
            mini=i
    return mini
def maximum():
    maxi=stock[0]
    for i in stock:
        if maxi<i:
            maxi=i
    return maxi
for i in stock:
    price=max(stock)
    profit=i-price
    if profit<
        prof