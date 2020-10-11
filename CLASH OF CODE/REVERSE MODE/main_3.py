# count /\ caracters
n = int(input())
cont=0
for i in range(n):
    line = input()
    cont+=line.count("/\\")
print(cont)
