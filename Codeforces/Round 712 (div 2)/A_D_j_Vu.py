def isPalindrome(s):
    return s == s[::-1]
for _ in range(int(input())):
    s=input()
    if(s.count('a')==len(s)):
        print("NO")
    else:
        n=len(s)
        t1 = s+'a'
        t2 = s[:1]+'a'+s[1:]
        t3 = 'a'+s
        print("YES")
        if(not isPalindrome(t1)):
            print(t1)
        elif(not isPalindrome(t2)):
            print(t2)
        else:
            print(t3)