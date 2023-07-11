from Palabras import contar_palabras

def main():
    texto = "¡Hola, mundo! ¿Cómo estás, mundo? ¡Hola, hola, hola!"
    conteo = contar_palabras(texto)
    
    # Imprimir cada palabra y su conteo
    for palabra, frecuencia in conteo.items():
        print(f"'{palabra}': {frecuencia}")

if __name__ == "__main__":
    main()
