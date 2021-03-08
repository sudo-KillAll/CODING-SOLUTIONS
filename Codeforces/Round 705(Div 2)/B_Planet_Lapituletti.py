valid = ['0','1','2','5','8']
for _ in range(int(input())):
    h,m=[int(i) for i in input().split()]
    s=input()
    H,M=s[:2],s[3:]
    currentHour,currentMin = int(H)%h,int(M)
    arr=[]
    test=[]
    found = False  
    while(True):        
         
        while(currentMin<m):
            ch,cm = str(currentHour),str(currentMin)
            while(len(ch)!=2):
                ch='0'+ch
            while(len(cm)!=2):
                cm='0'+cm
            t1,t2=ch,cm

            if(ch[0] in valid and ch[1] in valid and cm[0] in valid and cm[1] in valid):
                ch=ch[::-1]
                cm=cm[::-1]
                for i in range(2):
                    if(ch[i]=='2'):
                        ch=ch[:i]+'5'+ch[i+1:]
                    elif(ch[i]=='5'):
                        ch=ch[:i]+'2'+ch[i+1:]
                    if(cm[i]=='2'):
                        cm=cm[:i]+'5'+cm[i+1:]
                    elif(cm[i]=='5'):
                        cm=cm[:i]+'2'+cm[i+1:]
                #cm=cm[::-1]
                if(int(ch)<m and int(cm)<h):
                    found=True
                    print(t1+":"+t2)
                    break
                    arr.append([t1,t2])
                    test.append(t1)
            currentMin+=1
        currentHour=(currentHour+1)%h
        currentMin=0
        if(found):
            break
    if(not found):
        print("00:00")


            

            