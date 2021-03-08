for _ in range(int(input())):
    n,k=[int(i) for i in input().split()]
    arr=[int(i) for i in input().split()]
    bucket=[0]*n
    for i in range(n+1):
        while(arr[i]!=0):
            for j in bucket:
                if(j!=k):
                    j+=arr