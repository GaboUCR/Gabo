import string

def contar_palabras(texto):
    puntuacion = string.punctuation + "¡" + "¿"

    # Eliminar los signos de puntuación del texto
    texto_limpio = texto.translate(str.maketrans('', '', puntuacion))

    # Dividir el texto en palabras
    palabras = texto_limpio.split() # El valor por defecto del metodo split es un espacio

    # Crear un diccionario vacío para almacenar las palabras y sus conteos
    conteo = {}

    # Recorrer las palabras
    for palabra in palabras:
        if palabra in conteo:  # Si la palabra ya está en el diccionario, incrementar su conteo
            conteo[palabra] += 1
        else:  # Si la palabra no está en el diccionario, agregarla con un conteo de 1
            conteo[palabra] = 1

    return conteo