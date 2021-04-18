s = "aabacadaea"
ans = 0
for i in range(len(s)-1):
    for j in range(i+1,len(s)-1):
        if(s[i]==s[j] and s[i+1]==s[j+1]):
            print(i,j)
            ans+=1
print(ans)