#Conversion farenheit celcius y comparacion
n = int(input())
for i in range(n):
    b, t = [int(j) for j in input().split()]
    con = t *9/5+32
    if con<b:
        print("Higher")
    elif con>b:
        print("Lower")
    else:
        print("Same")
