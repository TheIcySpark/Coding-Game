# Tomar un numero, el resultado es el numero mas cada uno de sus digitos
n = int(input())
copia = str(n)
suma = 0
for digito in copia:
    suma += int(digito)

print(n + suma)