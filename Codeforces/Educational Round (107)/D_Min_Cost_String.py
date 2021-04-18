n,k=[int(i) for i in input().split()]
ans=""
for x in range(k):
    
    ans+=chr(x+97)*2

    for i in range(k):
        for j in range(k):
            tmp = chr(i+97)+chr(j+97)
            #print(tmp)
            if(ans.find(tmp)==-1):
                if(len(ans)>0):
                    #print(ans[-1]+tmp[0])
                    if(ans.find(ans[-1]+tmp[0])==-1):
                        ans+=tmp
    ans=ans[:len(ans)-1]
if(len(ans)>n):
    ans = ans[:n]
elif(len(ans)<n):
    while(len(ans)<n):
        tmp = str(ans)
        tmp[::-1]
        ans+=tmp
        if(len(ans)>n):
            break
    if(len(ans)>n):
        ans = ans[:n]
print(ans)