def binSearch(a,l,r,x):
    while(l<r):
        mid=(l+r)//2
        if(a[mid]==x):
            return mid
        if(a[mid]>x):
            r=mid-1
        else:
            l=mid+1
    return l

n,m=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
b=[int(i) for i in input().split()]
a=list(set(a))
a.sort()
b.sort()
ans=0
prev=n
for i in range(m):
    val=0
    res=binSearch(a,0,prev,b[i])
    if(res==0 and prev==n):
        ans+=n
    else:
        ans+=res
    prev=min(prev,res)
    '''for j in range(prev):
        if(a[j]<=b[i]):
            prev=j
            break
        else:
            val+=1
    ans+=val'''
    #print(ans)
print(ans)