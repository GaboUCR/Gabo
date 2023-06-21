import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import io

def parsear_tercer_grafico ():

    nombre_archivo = "table_02.csv"
    # Leer el archivo de texto
    with open(nombre_archivo, 'r') as archivo:
        lineas = archivo.readlines()

    # Tomar solo las líneas relevantes y limpiarlas
    lineas_relevantes = [lineas[2]]  # La primera línea relevante es la cuarta línea
    indices_relevantes = [5, 3, 6, 8, 9, 11, 12, 14, 15, 17, 18, 20, 21]  # Los índices de las otras líneas relevantes
    for indice in indices_relevantes:
        # Limpieza de las líneas: eliminar las comas extras al final de la línea
        linea_limpiada = lineas[indice].rstrip(",\n")
        lineas_relevantes.append(linea_limpiada)

    # Unir las líneas relevantes en un solo texto y leerlo como un DataFrame de pandas
    texto_relevante = "\n".join(lineas_relevantes)
    df = pd.read_csv(io.StringIO(texto_relevante))

    return df

def crear_tercer_grafico(df):

    fig, ax = plt.subplots(figsize=(10, 6))
    df.boxplot(column='Average Minutes', by='Characteristic', ax=ax)
    plt.xticks(rotation=45)  # rotar las etiquetas del eje x 45 grados
    plt.title('Cantidad de minutos de espera en el aeropuerto por persona en funcion de sus caracteristicas')
    plt.suptitle('')  # Elimina el título automático
    plt.xlabel('Caracteristicas')
    plt.ylabel('Minutos promedio')
    plt.tight_layout()  # Ajusta automáticamente el layout para que todo se vea bien
    plt.show()
