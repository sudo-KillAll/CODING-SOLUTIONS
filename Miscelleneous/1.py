for _ in range(int(input())):
    num = input()
    num=num.lstrip("0")
    n=len(num)
    num=int(num)
    y=num
    res=0
    while(num>0):
        x=num%10
        res+=x**n
        num=num//10
    if(res==y):
        print("FEELS GOOD")
    else:
        print("FEELS BAD")
    