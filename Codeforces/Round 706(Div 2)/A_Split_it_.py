def check(s,n,k):
    i,j=0,n-1
    cnt=0
    if(k==0):
        return "YES"
    while(i<=j):
        if(s[i]==s[j]):
            cnt+=1
        else:
            break
        i+=1
        j-=1
    if(cnt>k):
        return "YES"
    return "NO"
for _ in range(int(input())):
    n,k=[int(i) for i in input().split()]
    s=input()
    print(check(s,n,k))
    print(min(2,3,4,5))