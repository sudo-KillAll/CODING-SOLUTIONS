for _ in range(int(input())):
    a,b,c=[int(i) for i in input().split()]
    t1,t2 = a,b
    a,b = min(a,b),max(a,b)
    x = ""
    for i in range(c-1):
        x+='0'
    x='9'+x
    for i in range(a-c):
        x='1'+x
    y=""
    for i in range(c-1):
        y+='0'
    for i in range(b-c+1):
        y = '1'+y
    if(t1<=t2):
        if(len(x)<=len(y)):
            print(x,y)
        else:
            print(y,x)
    else:
        if(len(x)>len(y)):
            print(x,y)
        else:
            print(y,x)