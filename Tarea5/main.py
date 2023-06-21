import os
import requests
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import io

def descargar_archivo(url, nombre_archivo):
    try:
        response = requests.get(url)
        response.raise_for_status()
        with open(nombre_archivo, 'wb') as f:
            f.write(response.content)
        print(f'Archivo {nombre_archivo} descargado correctamente')
    except requests.HTTPError as http_err:
        print(f'Error HTTP: {http_err}')
    except Exception as err:
        print(f'Ocurrió un error: {err}')
    
def descargar_csv(urls):
    for url in urls:
        nombre_archivo = os.path.basename(url)
        if nombre_archivo.endswith('.csv'):
            descargar_archivo(url, nombre_archivo)
        else:
            print(f'La url {url} no apunta a un archivo csv')

def parsear_primer_grafico():
    # Asegúrate de que la ruta del archivo sea correcta
    ruta_archivo = 'figure1.csv'

    data = {}
    with open(ruta_archivo, 'r') as file:
        for line in file:
            if 'Illegal immigration across U.S. borders' in line:

                line = line.rstrip()[0:len(line) -4]

                # Dividir la línea en dos partes
                part1, part2 = line.split(',,')
                
                # Procesar la primera parte
                values1 = part1.split(',')
                data['Illegal immigration across U.S. borders'] = {
                    "not_at_all_concerned": float(values1[2]),
                    "somewhat_concerned": float(values1[3]),
                    "very_concerned": float(values1[4])
                }
                
                # Procesar la segunda parte
                values2 = part2.split(',')
                data[values2[1]] = {
                    "not_at_all_concerned": float(values2[2]),
                    "very_concerned": float(values2[3]),
                }
                break
    
    return data

def crear_primer_grafico(data):
    # Preparamos los datos
    labels1 = list(data['Illegal immigration across U.S. borders'].keys())
    values1 = list(data['Illegal immigration across U.S. borders'].values())

    labels2 = list(data['Risk of terrorism against Americans traveling by air outside the U.S.'].keys())
    values2 = list(data['Risk of terrorism against Americans traveling by air outside the U.S.'].values())

    x1 = np.arange(len(labels1))
    x2 = np.arange(len(labels2))

    # Creamos las barras
    width = 0.35  # ancho de las barras
    fig, ax = plt.subplots()

    rects1 = ax.bar(x1, values1, width, label='Illegal immigration')
    rects2 = ax.bar(x2 + len(values1), values2, width, label='Risk of terrorism')

    # Añadimos etiquetas, título y leyenda
    ax.set_ylabel('Scores')
    ax.set_title('Scores by concern')
    ax.set_xticks(np.append(x1, x2 + len(values1)))
    ax.set_xticklabels(labels1 + labels2)
    ax.legend()

    fig.tight_layout()

    # Mostramos el gráfico
    plt.show(block=False)

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



urls = [
    "https://www.bts.gov/sites/bts.dot.gov/files/legacy/publications/omnistats/volume_02_issue_01/csv/figure1.csv",
    "https://www.bts.gov/sites/bts.dot.gov/files/legacy/publications/omnistats/volume_01_issue_02/csv/table2.csv",
    "https://www.bts.gov/sites/bts.dot.gov/files/legacy/publications/airline_passenger_opinions_on_security_screening_procedures/csv/table_02.csv"
]

descargar_csv(urls)


dataframe2 = parsear_segundo_grafico()
crear_segundo_grafico(dataframe2)


data = parsear_primer_grafico()

crear_primer_grafico(data)


df3 = parsear_tercer_grafico()

crear_tercer_grafico(df3)



