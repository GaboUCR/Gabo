import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import io

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
    ax.set_xticklabels(labels1 + labels2, rotation=45) # Hemos añadido aquí "rotation='vertical'"
    ax.legend()

    fig.tight_layout()

    # Mostramos el gráfico
    plt.show(block=False)

