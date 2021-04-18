mod = 1000000007
def facMod(n):
    ans = 1
    for i in range(1,n+1):
        ans = (ans*i)%mod
    return ans
n=int(input())
print(facMod(n)-pow(2,n-1,mod))