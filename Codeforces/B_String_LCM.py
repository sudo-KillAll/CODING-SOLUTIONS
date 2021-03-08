import math
def getA(s,t):
    
    n,m=len(s),len(t)
    val=(m*n)//(math.gcd(m,n))
    s=s*(val//n)
    t=t*(val//m)
    if(s==t):
        return s
    return -1

for _ in range(int(input())):
    s=input()
    t=input()
    if(len(s)<=len(t)):
        ans=getA(t,s)
    else:
        ans=getA(s,t)
    print(ans)
