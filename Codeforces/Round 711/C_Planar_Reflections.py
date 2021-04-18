mod = 1000000007
for _ in range(int(input())):
    n,k=[int(i) for i in input().split()]
    if(k==1):
        print("1")
        continue
    if(n==1):
        print("2")
        continue
    ans = 2
    for i in range(1,n+1):
        for j in range(1,k+1):
            ans = (ans+j*(k-j)//2)%mod
    print(ans)
