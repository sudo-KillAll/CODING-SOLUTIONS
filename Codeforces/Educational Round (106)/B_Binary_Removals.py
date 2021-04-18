def solve():
    s=input()
    arr=[]
    i=1
    while(i<len(s)):
        if(s[i]=='1' and s[i-1]=='1'):
            arr.append(i)
            i+=2
        else:
            i+=1
    #print(arr)
    for i in range(len(arr)):
        if(i==len(arr)-1):
            last = len(s)
        else:
            last = arr[i+1]
        tmp = str(s[arr[i]:last])
        #print(tmp)
        if("00" in tmp):
            return "NO"
    return "YES"


for _ in range(int(input())):
    print(solve())