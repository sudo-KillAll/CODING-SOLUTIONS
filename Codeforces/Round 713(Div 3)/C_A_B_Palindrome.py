def solve(s,a,b):

    for i in s:
        if(i=='0'):
            a-=1
        elif(i=='1'):
            b-=1
    n = len(s)
    for i in range(n//2):
        if(s[i]!='?' and s[n-i-1]!='?'):
            if(s[i]!=s[n-i-1]):
                print("-1")
                return
        elif(s[i]!='?' or s[n-i-1]!='?'):
            if(s[i]=='0'):
                if(a>0):
                    s[n-i-1]='0'
                    a-=1
                else:
                    print("-1")
                    return
            elif(s[i]=='1'):
                if(b>0):
                    s[n-i-1]='1'
                    b-=1
                else:
                    print("-1")
                    return
            elif(s[n-i-1]=='0'):
                if(a>0):
                    s[i]='0'
                    a-=1
                else:
                    print("-1")
                    return
            elif(s[n-i-1]=='1'):
                if(b>0):
                    s[i]='1'
                    b-=1
                else:
                    print("-1")
                    return
    for i in range(n//2):
        if(s[i]=='?'):
            if(a>=2):
                s[i]='0'
                s[n-i-1]='0'
                a-=2
            elif(b>=2):
                s[i]='1'
                s[n-i-1]='1'
                b-=2
            else:
                print("-1")
                return
    if(n%2!=0):
        if(s[n//2]=='?'):
            if(a>0):
                s[n//2]='0'
                a-=1
            elif(b>0):
                s[n//2]='1'
                b-=1
            else:
                print("-1")
                return
    if(a>0 or b>0):
        print("-1")
        return
    for i in s:
        print(i,end="")
    print()
for _ in range(int(input())):
    a,b=[int(i) for i in input().split()]
    s=list(input())
    solve(s,a,b)