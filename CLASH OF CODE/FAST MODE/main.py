#For a given input number, your program must output the sum of the numbers in the unique prime factorisation of that number.
import math

def esPrimo(n):
    i = 2
    while(i<=math.sqrt(i)):
        if i%n == 0: return False
        i+=1
    return True

n = int(input())

suma = 0

if(n == 1):
    print(1)
else:
    numeroPrimo = 2
    while (numeroPrimo<=n):
        if(esPrimo(numeroPrimo)):
            if n % numeroPrimo == 0:
                n /= numeroPrimo
                suma += numeroPrimo
                numeroPrimo -= 1
        numeroPrimo += 1

print(suma)