for _ in range(int(input())):
    n=int(input())
    arr=[]
    a,b=-1,-1
    c,d=-1,-1
    for i in range(n):
        x=list(input())
        arr.append(x)
    for i in range(n):
        for j in range(n):
            if(arr[i][j]=='*'):
                if(a==-1):
                    a,b=i,j
                else:
                    c,d=i,j
    if(a==c):
        if(a+1<n):
            arr[a+1][b]='*'
            arr[a+1][d]='*'
        else:
            arr[a-1][b]='*'
            arr[a-1][d]='*'
    elif(b==d):
        if(b+1<n):
            arr[a][b+1]='*'
            arr[c][b+1]='*'
        else:
            arr[a][b-1]='*'
            arr[c][b-1]='*'
    else:
        arr[a][d]='*'
        arr[c][b]='*'
    for i in range(n):
        for j in range(n):
            print(arr[i][j],end="")
        print()