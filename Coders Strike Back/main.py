import sys
import math

boost_usado = False

class Vector:
    angulo = 0
    magnitud = 0
    def __init__(self,actual_x, actual_y, magnitud):
        self.magnitud = magnitud
        self.angulo = math.atan(actual_y / actual_x)
    
    def direccion_x(self):
        return self.magnitud * math.cos(self.angulo)
    
    def direccion_y(self):
        return self.magnitud * math.sin(self.angulo)

def enemigo_en_rango(pos_x, pos_y, oponente_x, oponente_y):
    RANGO = 600
    if (oponente_x >= pos_x - RANGO and oponente_x <= pos_x + RANGO) and \
    (oponente_y >= pos_y - RANGO and oponente_y <= pos_y + RANGO):
        return True
    else:
        return False

class Vector_puntos:
    x = 0
    y = 0
    def __init__(self, x, y):
        self.x = x
        self.y = y


def nuevo_proximo_punto(vector_desfase):
    vector_desfase.magnitud = 500
    vector_suma = Vector_puntos(vector_desfase.direccion_x(), \
    vector_desfase.direccion_y())
    
    return vector_suma


def enemigo_cerca(proximo_x, proximo_y, actual_x, actual_y, oponente_x, oponente_y):
    vector_suma = Vector_puntos(0,0)
    MAGNITUD = 600
    vector_desfase = Vector(actual_x, actual_y, MAGNITUD)
    vector_desfase.angulo += 90
    if enemigo_en_rango(actual_x + vector_desfase.direccion_x(), \
    actual_y + vector_desfase.direccion_y(), oponente_x, oponente_y):
        vector_suma = nuevo_proximo_punto(vector_desfase)
        return vector_suma
    
    vector_desfase.angulo -= 180
    if  enemigo_en_rango(actual_x + vector_desfase.direccion_x(), \
    actual_y + vector_desfase.direccion_y(), oponente_x, oponente_y):
        vector_suma = nuevo_proximo_punto(vector_desfase)
        return vector_suma
    
    return vector_suma


while True:
    x, y, next_checkpoint_x, next_checkpoint_y, \
            next_checkpoint_dist, next_checkpoint_angle = \
            [int(i) for i in input().split()]
    opponent_x, opponent_y = [int(i) for i in input().split()]

    if next_checkpoint_angle > 90 or next_checkpoint_angle < -90 or \
        (next_checkpoint_dist <= 4000 and (next_checkpoint_angle > 45 or next_checkpoint_angle < -45)):
        empuje = 0
    elif not boost_usado and next_checkpoint_dist >= 300:
        empuje = "BOOST"
        boost_usado = True
    else:
        empuje = 100
        vector_suma = enemigo_cerca(next_checkpoint_x, next_checkpoint_y, x, y, opponent_x, \
        opponent_y)
        next_checkpoint_x += int(vector_suma.x)
        next_checkpoint_y += int(vector_suma.y)
        print(str(int(vector_suma.x)) + " " + str(int(vector_suma.y)), file = sys.stderr, flush = True)

    print(str(next_checkpoint_x) + " " + str(next_checkpoint_y) + " " + str(empuje))
