def solve():
    s=input()
    c1,c2 = s.count("AB"),s.count("BA")
    if(c1==0 or c2==0):
        return "NO"
    else:
        ind = s.find("AB")
        if(s[ind+2:].find("BA")):
            print("Not here 1")
            return "YES"
        ind = s.find("BA")
        if(s[ind+2:].find("AB")):
            print("Not here 2")
            return "YES"
        return "NO"
print(solve())