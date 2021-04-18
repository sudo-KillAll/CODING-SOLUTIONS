for _ in range(int(input())):
    n=int(input())
    arr=[int(i) for i in input().split()]
    ans=[0]*n
    for i in range(n):
        cnt=0
        for j in range(i-1,-1,-1):
            if(arr[j]>arr[i]):
                break
            if(arr[j]==arr[i]):
                cnt+=1
        for j in range(i+1,n):
            if(arr[j]>arr[i]):
                break
            if(arr[j]==arr[i]):
                cnt+=1
        ans[i]=cnt
    print(*ans)