def obtenerNodo(i, j, ax, ay):
    global cuadricula, ancho, alto
    i += ay
    j += ax
    while i < alto and j < ancho and cuadricula[i][j] != '0':
        i += ay
        j += ax
    return "-1 -1" if i >= alto or j >= ancho else str(j) + ' ' + str(i)

    

ancho = int(input()) 
alto = int(input())
cuadricula = []
for i in range(alto):
    l = input()
    cuadricula.append(l)
i = 0
while i < alto:
    j = 0
    while j < ancho:
        if cuadricula[i][j] == '0':
            print(str(j) + ' ' + str(i) + ' ' + obtenerNodo(i, j, 1, 0) \
                + ' ' + obtenerNodo(i, j, 0, 1))
        j += 1
    i += 1