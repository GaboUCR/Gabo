import os
import requests
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import io
import primer_grafico
import segundo_grafico
import tercer_grafico

def analizar_datos(df1, df2, df3):
    print("\n\n\n\n\nAnálisis de Nivel de preocupación acerca de la inmigración ilegal y riesgo de terrorismo")
    for key in df1:
        print(f"\nPara la variable '{key}':")
        for subkey in df1[key]:
            print(f"El porcentaje que corresponde a '{subkey}' es {df1[key][subkey]}%")

    print("\n\n\n\n\nAnálisis de Modo de transporte antes y después del 11 de septiembre:")
    descriptive_stats = df2.describe()
    mode = df2.mode()
    print("\nValores descriptivos:")
    print(descriptive_stats)
    print("\nModa de cada columna:")
    print(mode)

    print("\n\n\n\n\nAnálisis de Cantidad de minutos de espera en el aeropuerto por persona en función de sus características")
    descriptive_stats = df3.describe()
    mode = df3.mode()
    grouped = df3.groupby('Characteristic').mean()

    print("\nValores descriptivos:")
    print(descriptive_stats)
    print("\nModa de cada columna:")
    print(mode)
    print("\nAgrupación y resumen por característica:")
    print(grouped)

    return None

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

urls = [
    "https://www.bts.gov/sites/bts.dot.gov/files/legacy/publications/omnistats/volume_02_issue_01/csv/figure1.csv",
    "https://www.bts.gov/sites/bts.dot.gov/files/legacy/publications/omnistats/volume_01_issue_02/csv/table2.csv",
    "https://www.bts.gov/sites/bts.dot.gov/files/legacy/publications/airline_passenger_opinions_on_security_screening_procedures/csv/table_02.csv"
]

descargar_csv(urls)

df1 = primer_grafico.parsear_primer_grafico()
df2 = segundo_grafico.parsear_segundo_grafico()
df3 = tercer_grafico.parsear_tercer_grafico()

# El significado de estos datos se explica en la documentación
analizar_datos(df1, df2, df3)

primer_grafico.crear_primer_grafico(df1)
segundo_grafico.crear_segundo_grafico(df2)
tercer_grafico.crear_tercer_grafico(df3)