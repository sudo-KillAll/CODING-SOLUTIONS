import math
for _ in range(int(input())):
    n=int(input())
    a,b=[],[]
    for i in range(2*n):
        x,y=[int(j) for j in input().split()]
        if(x==0):
            a.append(abs(y))
        else:
            b.append(abs(x))
    
    a.sort()
    b.sort()
    ans=0
    #print()
    #print(a)
   # print(b)
    for i in range(n):
        ans+=math.pow(a[i]*a[i]+b[i]*b[i],1/2)

    print(ans)
