import sys

class Caja:
    posicion = ""
    lados = ""
    def __init__(self, posicion, lados):
        self.posicion = posicion
        self.lados = lados

tam_tablero, id_jugador, puntos_jugador, puntos_oponente, numero_cajas = 0, 0, 0, 0, 0
cajas = []

def lectura_inicial():
    tam_tablero = int(input())
    id_jugador = input()



def lectura_turno():
    global cajas
    puntos_jugador, puntos_oponente = [int(i) for i in input().split()]
    numero_cajas= int(input())
    cajas = []
    for i in range(numero_cajas):
        posicion, lados = input().split()
        caja = Caja(posicion, lados)
        cajas.append(caja)

def hacer_jugada():
    global cajas
    if len(cajas[-1].lados) == 1:
        print(str(cajas[-1].posicion) + " " + str(cajas[-1].lados))
    else:
        print(str(cajas[0].posicion) + " " + str(cajas[0].lados[0]))

lectura_inicial()
while True:
    lectura_turno()
    cajas = sorted(cajas, key = lambda Caja: len(Caja.lados), reverse = True)
    hacer_jugada()
