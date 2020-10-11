
#Desencripcion NO COMPLETADO
c=input().split()
PI="31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"
i=0
for p in c:
    for l in p:
        v=ord(l)-int(PI[i])
        l=v
        i+=1
print(c)
