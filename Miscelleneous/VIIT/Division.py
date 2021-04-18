for _ in range(int(input())):
    k =int(input())
    a,b=[int(i) for i in input().split()]
    val = str(a/b)
    val = val[val.find(".")+1:]
    s = 0
    for i in range(k):
        s+=int(val[i])
    print(s)