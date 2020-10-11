#Contar 1 en binario del numero
x=int(input())
cont=0
while x>=1:
    if x%2!=0:
        cont+=1
    x=int(x/2)
print(cont)