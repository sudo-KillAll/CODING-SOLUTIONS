for tst in range(int(input())):
    n,m=[int(i) for i in input().split()]
    arr=[]
    for i in range(n):
        tmp=[int(j) for j in input().split()]
        arr.append(tmp)
    ans=0
    #Left
    for i in range(n):
        for j in range(1,m):
            if(abs(arr[i][j]-arr[i][j-1])>1):
                if(arr[i][j]<arr[i][j-1]):
                    ans+=arr[i][j-1]-arr[i][j]-1
                    arr[i][j]=arr[i][j-1]-1
                else:
                    ans+=arr[i][j]-arr[i][j-1]-1
                    arr[i][j-1]=arr[i][j]-1
    
    #Right
    for i in range(n):
        for j in range(m-2,-1,-1):
            if(abs(arr[i][j]-arr[i][j+1])>1):
                if(arr[i][j]<arr[i][j+1]):
                    ans+=arr[i][j+1]-arr[i][j]-1
                    arr[i][j]=arr[i][j+1]-1
                else:
                    ans+=arr[i][j]-arr[i][j+1]-1
                    arr[i][j+1]=arr[i][j]-1

    #Top
    for i in range(1,n):
        for j in range(m):
            if(abs(arr[i][j]-arr[i-1][j])>1):
                if(arr[i][j]<arr[i-1][j]):
                    ans+=arr[i-1][j]-arr[i][j]-1
                    arr[i][j]=arr[i-1][j]-1
                else:
                    ans+=arr[i][j]-arr[i-1][j]-1
                    arr[i-1][j]=arr[i][j]-1

    #bottom
    for i in range(n-2,-1,-1):
        for j in range(m):
            if(abs(arr[i][j]-arr[i+1][j])>1):
                if(arr[i][j]<arr[i+1][j]):
                    ans+=arr[i+1][j]-arr[i][j]-1
                    arr[i][j]=arr[i+1][j]-1
                else:
                    ans+=arr[i][j]-arr[i+1][j]-1
                    arr[i+1][j]=arr[i][j]-1
    print("Case #"+str(tst+1)+":",ans)