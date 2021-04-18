for _ in range(int(input())):
    x,r,m=[int(i) for i in input().split()]
    r*=60
    m*=60
    #print(x+(m-x)//2)
    if(r>m):
        print("NO")
    # elif(r<=x):
    #     print()
    elif((m+x)//2>=r):
        print("YES")
    else:
        print("NO")
