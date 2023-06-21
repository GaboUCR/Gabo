import os
import requests
import pandas as pd

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


# Uso:
urls = [
    "https://www.bts.gov/sites/bts.dot.gov/files/legacy/publications/omnistats/volume_02_issue_01/csv/figure1.csv"
]
descargar_csv(urls)

# Asegúrate de que la ruta del archivo sea correcta
ruta_archivo = 'figure1.csv'

data = {}
with open(ruta_archivo, 'r') as file:
    for line in file:
        if 'Illegal immigration across U.S. borders' in line:

            line = line.rstrip()[0:len(line) -4]

            print(line)
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

# Imprimir los datos
for key, value in data.items():
    print(f"\n{key}:")
    for k, v in value.items():
        print(f"{k}: {v}")





