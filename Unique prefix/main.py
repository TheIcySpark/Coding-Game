class Palabra:
    palabra = ""
    posicion = 0
    prefijo  = ""
    
    def __init__(self, palabra, posicion):
        self.palabra = palabra
        self.posicion = posicion
        self.prefijo = ""

    def __repr__(self):
        return repr((self.palabra, self.posicion))


palabras = []
n = 0

def keyPalabra(palabra):
    return palabra

def keyPosicion(posicion):
    return posicion

def lectura():
    n = int(input())
    for i in range(n):
        p = input()
        palabra = Palabra(p, i)
        palabras.append(palabra)

def imprimirPrefijos():
    for palabra in palabras:
        print(palabra.prefijo)

def obtenerMinimoPrefijo():
    i = 0
    while i < len(palabras):
        anterior = True
        siguiente = True
        if i == 0: anterior = False
        if i == len(palabras)-1: siguiente = False
        j = 0
        if siguiente and palabras[i].palabra == palabras[i + 1].palabra:
            k = i + 1
            prefijo = ""
            while k < len(palabras) and palabras[k].palabra == palabras[k - 1].palabra:
                k += 1
            if not (k == len(palabras)):
                k -= 1
                while j < len(palabras[k].palabra):
                    prefijo += palabras[k].palabra[j]
                    if siguiente:
                        if j < len(palabras[k+1].palabra):
                            if not (palabras[k+1].palabra[j] == palabras[k].palabra[j]):
                                siguiente = False
                        else: 
                            siguiente = False
                    if not siguiente:
                        break
                    j += 1
            else:
                k -= 1
                prefijo = palabras[k].palabra
            while i <= k:
                palabras[i].prefijo = prefijo
                i += 1
        else:
            while j < len(palabras[i].palabra):
                palabras[i].prefijo += palabras[i].palabra[j]
                if anterior:
                    if j < len(palabras[i-1].palabra):
                        if not (palabras[i-1].palabra[j] == palabras[i].palabra[j]):
                            anterior = False
                    else: 
                        anterior = False
                if siguiente:
                    if j < len(palabras[i+1].palabra):
                        if not (palabras[i+1].palabra[j] == palabras[i].palabra[j]):
                            siguiente = False
                    else: 
                        siguiente = False
                if not anterior and not siguiente:
                    break
                j += 1
            i += 1
            
        

lectura()
palabras = sorted(palabras, key = lambda Palabra: Palabra.palabra, reverse = True)
obtenerMinimoPrefijo()
palabras = sorted(palabras, key = lambda Palabra: Palabra.posicion)
imprimirPrefijos()