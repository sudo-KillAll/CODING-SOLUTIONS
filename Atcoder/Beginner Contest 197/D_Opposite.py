import math
n=int(input())
a,b=[int(i) for i in input().split()]
c,d=[int(i) for i in input().split()]

x,y=(a+c)/2,(b+d)/2

dist = pow((x-a)*(x-a)+(y-b)*(y-b),1/2)

angle = 360/n
angleNew = (180-angle)/2

k = (dist*math.sin(math.radians(angle)))/(math.sin(math.radians(angleNew)))

val = (k*k-dist*dist-(a*a-x*x)+(b*b-y*y))/2

xNew = x-a
yNew = y-b



