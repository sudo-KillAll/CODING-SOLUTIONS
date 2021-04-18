
def recursion(arr,cost,i,j,n):
    if(i>=n-1 and j>=n-1):
        for x in range(n):
            if(arr[x].count(-1)>=2):
                #print("found")
                return 10000000000
        for y in range(n-1,-1,-1):
            cnt=0
            for x in range(n):
                if(arr[x][y]==-1):
                    cnt+=1
            if(cnt>=2):
                #print("found")
                return 10000000000
        return 0
    elif(i>=n-1):
        tmp = list(arr)
        if(arr[i][j]==-1):
            return min(recursion(arr,cost,i,j+1,n),cost[i][j]+recursion(tmp,cost,i,j+1,n))
        else:
            return recursion(arr,cost,i,j+1,n)
    elif(j>=n-1):
        tmp = list(arr)
        if(arr[i][j]==-1):
            return min(recursion(arr,cost,i+1,j,n),cost[i][j]+recursion(tmp,cost,i+1,j,n))
        else:
            return recursion(arr,cost,i+1,j,n)
    else:
        tmp = list(arr)
        if(arr[i][j]==-1):
            v1 = min(recursion(arr,cost,i,j+1,n),cost[i][j]+recursion(tmp,cost,i,j+1,n))
            v2 = min(recursion(arr,cost,i+1,j,n),cost[i][j]+recursion(tmp,cost,i+1,j,n))
            v3 = min(recursion(arr,cost,i+1,j+1,n),cost[i][j]+recursion(tmp,cost,i+1,j+1,n))
        else:
            v1 = recursion(arr,cost,i,j+1,n)
            v2 = recursion(arr,cost,i+1,j,n)
            v3 = recursion(arr,cost,i+1,j+1,n)
        return min(v1,v2,v3)
       

for tst in range(1,int(input())+1):
    n=int(input())
    arr=[]
    for i in range(n):
        tmp = [int(j) for j in input().split()]
        arr.append(tmp)
    
    cost=[]
    
    for i in range(n):
        tmp = [int(j) for j in input().split()]
        cost.append(tmp)
    print(cost)
    row = [int(i) for i in input().split()]
    col = [int(i) for i in input().split()]
    
    print("Case #"+str(tst)+":",recursion(arr,cost,0,0,n))