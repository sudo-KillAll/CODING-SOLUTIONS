for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    a.sort()
    b.sort()
    if(n==1):
        print(a[0]+b[0])
        continue
    print(min(a[-2]+b[-1],a[-1]+b[-2]))