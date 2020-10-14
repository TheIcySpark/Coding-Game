class Caja:
    posicion = ""
    lados = ""

tam_tablero, id_jugador, puntos_jugador, puntos_oponente, numero_cajas = 0, 0, 0, 0, 0

def lectura_inicial():
    tam_tablero = int(input())
    id_jugador = input()



def lectura_turno():
    puntos_jugador, puntos_oponente = [int(i) for i in input().split()]
    numero_cajas= int(input())
    for i in range(numero_cajas):
        box, sides = input().split()


lectura_inicial()
while True:
    lectura_turno()
