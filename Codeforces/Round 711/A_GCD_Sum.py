import math
for _ in range(int(input())):
    n=int(input())
    while(True):
        val = list(str(n))
        cur =0 
        for i in val:
            cur+=int(i)
        
        if(math.gcd(cur,n)>1):
            print(n)
            break
        n+=1