import sys
class Posicion:
    x = 0
    y = 0
    def __init__(self):
        pass

class Rango:
    ini = 0
    fin = 0
    def __init__(self):
        pass

posicion_actual, posicion_anterior, posicion_auxiliar = Posicion(), Posicion(), Posicion()
rango_vertical, rango_horizontal = Rango(), Rango()
primer_ciclo = True
pista_bomba, pista_bomba_anterior = '', ''


def inicializacion():
    global rango_horizontal, rango_vertical, posicion_actual, posicion_anterior
    rango_horizontal.fin, rango_vertical.fin = [int(i)-1 for i in input().split()]
    n = int(input())
    posicion_actual.x, posicion_actual.y = [int(i) for i in input().split()]
    posicion_anterior.x, posicion_anterior.y = posicion_actual.x, posicion_actual.y


def binaria(rango, posA, posB):
    nueva_posA = 0
    m = int((rango.ini + rango.fin) / 2)
    divisible = 1 if (rango.ini + rango.fin) % 2 == 0 else 0
    if pista_bomba == 'UNKNOWN':
        nueva_posA = rango.fin - posA + rango.ini
    elif pista_bomba == 'SAME':
        nueva_posA = m
        rango.ini = rango.fin = nueva_posA
    elif pista_bomba == 'WARMER':
        if posB < posA:
            rango.ini = m + 1
        else:
            rango.fin = m
            if divisible: rango.fin -= 1
        nueva_posA = rango.fin - posA + rango.ini
    elif pista_bomba == 'COLDER':
        if posB > posA: 
            rango.ini = m + 1
        else:
            rango.fin = m
            if divisible: rango.fin -= 1
        nueva_posA = rango.ini
    if nueva_posA == posA and rango.ini != rango.fin: nueva_posA -= 1
    print(str(rango.ini) + " " + str(rango.fin) + " " + pista_bomba, file = sys.stderr, flush = True)
    return nueva_posA

def actualizar():
    global primer_ciclo, posicion_actual, posicion_anterior, posicion_auxiliar
    if primer_ciclo:
        primer_ciclo = False
        posicion_auxiliar.x, posicion_auxiliar.y = posicion_actual.x, posicion_actual.y
    else:
        posicion_anterior.x, posicion_anterior.y = posicion_auxiliar.x, posicion_auxiliar.y
        posicion_auxiliar.x, posicion_auxiliar.y = posicion_actual.x, posicion_actual.y


inicializacion()
while True:
    pista_bomba = input()
    if pista_bomba_anterior == 'COLDER': pista_bomba = 'UNKNOWN'
    pista_bomba_anterior = pista_bomba
    if rango_horizontal.ini != rango_horizontal.fin:
        print('Horizontal', file = sys.stderr, flush = True)
        posicion_actual.x = binaria(rango_horizontal, posicion_actual.x, posicion_anterior.x)
        if rango_horizontal.ini == rango_horizontal.fin:
            pista_bomba = 'UNKNOWN'
            pista_bomba_anterior = 'UNKNOWN'
    if rango_horizontal.ini == rango_horizontal.fin:
        print('VERTICAL', file = sys.stderr, flush = True)
        posicion_actual.y = binaria(rango_vertical, posicion_actual.y, posicion_anterior.y)
    actualizar()
    print(str(posicion_actual.x) + ' ' + str(posicion_actual.y))


