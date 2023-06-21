import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import io

def parsear_segundo_grafico():

    # Leer el archivo en líneas
    nombre_archivo = "table2.csv"
    # Leer el archivo en líneas
    with open(nombre_archivo, 'r') as archivo:
        lineas = archivo.readlines()

    # Reescribir el archivo con el encabezado corregido
    with open(nombre_archivo, 'w') as archivo:
        # Corregir el encabezado
        lineas[0] = "Modo,Modo antes del 11 de Septiembre,Modo despues del 11 de Septiembre\n"
        # Escribir las líneas de vuelta en el archivo
        archivo.writelines(lineas)
    
    # Ahora, leer el archivo CSV limpiado en un DataFrame
    df = pd.read_csv(nombre_archivo)
    
    # Reemplazar '-' con NaN
    df = df.replace('-', np.nan)
    
    # Convertir las cadenas de porcentaje en flotantes
    for columna in df.columns[1:]:
        df[columna] = df[columna].str.rstrip('%').astype('float') / 100.0
        
    # Manejo especial para "Tren" y "Otro"
    for i, fila in df.iterrows():
        if pd.isna(df.at[i, "Modo despues del 11 de Septiembre"]):
            df.at[i, "Modo despues del 11 de Septiembre"] = df.at[i, "Modo antes del 11 de Septiembre"]
            
    return df

def crear_segundo_grafico(df):
    """
    Esta función crea un gráfico de dispersión a partir de un DataFrame.
    :param df: El DataFrame a graficar.
    """
    plt.figure(figsize=(10, 6))
    plt.scatter(df['Modo'], df['Modo antes del 11 de Septiembre'], color='blue', label='Antes del 11 de Septiembre')
    plt.scatter(df['Modo'], df['Modo despues del 11 de Septiembre'], color='red', label='Después del 11 de Septiembre')
    plt.legend()
    plt.xlabel('Modo de transporte')
    plt.ylabel('Porcentaje')
    plt.title('Modo de transporte antes y después del 11 de Septiembre')
    plt.grid(True)
    plt.show(block=False)
