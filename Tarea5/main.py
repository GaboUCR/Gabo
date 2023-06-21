import os
import requests
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import io
import primer_grafico
import segundo_grafico
import tercer_grafico

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


dataframe2 = segundo_grafico.parsear_segundo_grafico()
segundo_grafico.crear_segundo_grafico(dataframe2)


data = primer_grafico.parsear_primer_grafico()

primer_grafico.crear_primer_grafico(data)


df3 = tercer_grafico.parsear_tercer_grafico()

tercer_grafico.crear_tercer_grafico(df3)



