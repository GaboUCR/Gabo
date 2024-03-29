# Cómo correr el programa:
Clone este repositorio y ejecute alguno de los siguientes comandos en la raíz.

```console
python main.py
```
O puede utilizar make si lo tiene instalada:

```console
make
```

# Análisis de resultados:

## Gráfico 1: Nivel de preocupación acerca de la inmigración ilegal y riesgo de terrorismo

La gráfica de barras, generada a partir de los datos recogidos después de los ataques del 11 de septiembre, muestra la distribución de las respuestas de los encuestados sobre su nivel de preocupación en dos temas: la inmigración ilegal a través de las fronteras de los Estados Unidos y el riesgo de terrorismo para los estadounidenses que viajan fuera del país. Los datos muestran que un mayor número de personas están muy preocupadas tanto por la inmigración ilegal como por el riesgo de terrorismo.

Esto sugiere que los ataques tuvieron un impacto significativo en la percepción pública del riesgo y la seguridad. Las implicaciones de este hallazgo son múltiples. Por un lado, indica que existe una presión pública considerable para abordar estos problemas de seguridad, lo que puede influir en las políticas y en la asignación de recursos. Por otro lado, estos temores pueden tener consecuencias negativas, como el aumento de la discriminación y la xenofobia, o una mayor aceptación de medidas de seguridad más estrictas que podrían afectar las libertades civiles.

![1](https://github.com/GaboUCR/Gabo/assets/69367406/3e864045-c12b-4cf1-8d5b-5c040ddbcd93)


## Gráfico 2: Modo de transporte antes y después del 11 de septiembre

La gráfica de dispersión indica que ha habido un cambio en los métodos de transporte preferidos por las personas después de los ataques del 11 de septiembre. Se puede observar que el uso del avión ha disminuido después de los ataques, lo que sugiere un aumento en la percepción del riesgo asociado con el viaje aéreo.

Este cambio en la conducta de viaje puede tener implicaciones significativas. Para la industria de la aviación, esto podría significar una disminución en la demanda de vuelos, lo que podría llevar a una reducción en los ingresos. Para el público, este cambio en los patrones de viaje podría implicar más tiempo y recursos invertidos en viajes, si los métodos alternativos son menos eficientes.


![2](https://github.com/GaboUCR/Gabo/assets/69367406/ec2f57fc-3f46-4c3c-91c4-5809fa78e774)

## Gráfico 3: Cantidad de minutos de espera en el aeropuerto por persona en función de sus características

El gráfico de cajas muestra la variación en los tiempos de espera promedio en los aeropuertos en función de las diferentes características de los pasajeros. Es notable que ciertos grupos de pasajeros experimentan tiempos de espera más largos que otros.

Este patrón podría ser el resultado de las medidas de seguridad actuales en los aeropuertos, que podrían estar afectando de manera desigual a diferentes grupos de pasajeros. Si este es el caso, puede plantear problemas de equidad y eficiencia. Por un lado, los largos tiempos de espera pueden ser una molestia para los pasajeros y disuadirlos de viajar en avión. Por otro lado, si los recursos de seguridad se están dirigiendo desproporcionadamente hacia ciertos grupos, esto podría significar que otros grupos están siendo menos examinados, lo que podría tener implicaciones para la seguridad en general.

Muestra que las personas discapacitadas tienen un tiempo de espera significativamente más corto en los aeropuertos en comparación con otros grupos. Esto podría ser el resultado de las políticas y regulaciones destinadas a facilitar su experiencia de viaje, lo que es una noticia alentadora ya que indica que las medidas para ayudar a los viajeros con discapacidades pueden estar teniendo un impacto positivo. Sin embargo, es importante recordar que esto no necesariamente significa que la experiencia de viaje de las personas discapacitadas sea fácil o sin estrés, ya que pueden enfrentar otros desafíos no capturados en este conjunto de datos.

Por otro lado, es preocupante ver que las personas que se identifican como de "otras razas" experimentan tiempos de espera más largos. Este patrón podría estar indicando una discriminación sistemática o sesgos inconscientes en las medidas de seguridad del aeropuerto. Los tiempos de espera más largos pueden ser una fuente de estrés y ansiedad, y podrían llevar a estas personas a evitar o limitar sus viajes aéreos. Esto podría a su vez reforzar la segregación y la desigualdad al limitar su acceso a las oportunidades y experiencias que los viajes aéreos pueden proporcionar.

Estos hallazgos subrayan la importancia de evaluar continuamente las políticas y prácticas de seguridad en los aeropuertos para asegurar que sean justas y equitativas. También destacan la necesidad de más investigación para entender mejor las experiencias de diferentes grupos de pasajeros y cómo pueden ser mejoradas. Las autoridades de aviación y seguridad deben abordar estos problemas de frente para garantizar que todos los viajeros sean tratados de manera equitativa y sin prejuicios.

![3](https://github.com/GaboUCR/Gabo/assets/69367406/472e8df1-fc6b-4807-8b25-5a4900855bc4)


# Análisis de datos:
En esta sección se analizan los datos que se imprimen en la consola al correr el programa.
## Análisis de Cantidad de Minutos de Espera en el Aeropuerto por Persona en función de sus Características
En nuestro análisis, revisamos una serie de características individuales y cómo estas afectaban el tiempo promedio de espera en el aeropuerto. A continuación, presentamos los hallazgos clave:

### Estadísticas Descriptivas:

Las estadísticas descriptivas proporcionan una visión general de la distribución de los tiempos promedio de espera. En nuestro conjunto de datos, vemos que el tiempo promedio de espera en el aeropuerto varía entre 11.4 y 27.3 minutos. El tiempo de espera medio es de 20.1 minutos, y la mayoría de los datos se sitúa entre 18 y 20.9 minutos (esto es lo que nos indican los percentiles 25% y 75%).

### Moda:

La moda nos indica el valor que más veces aparece en cada columna. En nuestro caso, se nota que los valores de moda no son muy útiles para la interpretación, debido a que los valores son mayormente únicos en las columnas de 'Average Minutes' y 'Standard Error'. Sin embargo, en la columna 'Sample Size', el valor de moda es 22, lo que indica que la muestra más pequeña que tenemos para cualquier característica es de 22 individuos.

### Agrupación por Características:

En este análisis, calculamos el tiempo promedio de espera y el error estándar para cada característica. Aquí hay algunas observaciones interesantes:

- Los individuos discapacitados tuvieron el menor tiempo de espera promedio, con 11.4 minutos. Esto podría deberse a las políticas del aeropuerto que dan prioridad a estos individuos.
- Los individuos de 'Otra raza' tuvieron el mayor tiempo promedio de espera, con 27.3 minutos. Esto podría indicar una disparidad en los tiempos de espera que necesita ser investigada más a fondo.
- Las personas con un ingreso familiar de $75K o más tuvieron un tiempo de espera promedio más alto que aquellos con un ingreso menor a $75K. Esto puede sugerir que los vuelos frecuentados por pasajeros de mayor ingreso podrían tener mayores tiempos de espera.
- Los individuos de 18 a 54 años tuvieron un tiempo de espera promedio mayor en comparación con los de 55 años o más.
Es importante mencionar que estos son solo observaciones preliminares y para establecer cualquier relación causal se necesita un análisis más profundo.

## Análisis del Modo de Transporte antes y después del 11 de Septiembre
Hemos analizado cómo cambió el modo de transporte de las personas antes y después de los eventos del 11 de Septiembre. Aquí están los hallazgos principales:

### Estadísticas Descriptivas:

Las estadísticas descriptivas nos dan una visión general de la distribución del modo de transporte. Aquí vemos que el uso promedio de los modos de transporte antes del 11 de septiembre varía entre el 6.9% y el 65.5%. Sin embargo, después del 11 de septiembre, vemos un cambio notable con el uso promedio del modo de transporte que varía entre el 6.9% y el 93.1%. Esto indica que el 11 de septiembre tuvo un impacto significativo en el modo de transporte que la gente eligió.

### Moda:

La moda nos indica los valores más comunes para cada columna. En este caso, la moda nos da una idea de los modos de transporte más utilizados antes y después del 11 de septiembre. Antes del 11 de septiembre, el aire comercial era el modo más popular de transporte. Sin embargo, después del 11 de septiembre, el vehículo personal se convirtió en el modo más utilizado de transporte.

En resumen, a partir de estos datos, podemos concluir que el 11 de septiembre tuvo un impacto significativo en los modos de transporte utilizados por las personas. Específicamente, hubo un cambio notable del aire comercial al uso de vehículos personales. Este cambio puede ser atribuido a una variedad de factores, como las preocupaciones de seguridad o las nuevas regulaciones de viaje introducidas después del 11 de septiembre. Sin embargo, se necesita más análisis para determinar con precisión las razones exactas detrás de este cambio.
