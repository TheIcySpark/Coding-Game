x,y,c,f=[int(i) for i in input().split()]
o='NESW'
while 1:
    s=''
    r=input()
    if f>y:s+=o[0];f-=1
    if f<y:s+=o[2];f+=1
    if c>x:s+=o[3];c-=1
    if c<x:s+=o[1];c+=1
    print(s)