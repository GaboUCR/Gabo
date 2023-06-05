import csv
import re
from empleado import Empleado

def validar_entrada(entrada, patron):
    """
    Verifica si la entrada cumple con el patrón especificado.

    Parámetros:
    entrada -- el valor a verificar
    patron -- el patrón a comparar con la entrada

    Retorno:
    True si la entrada coincide con el patrón, False en caso contrario.
    """
    return re.match(patron, entrada) is not None

def leer_archivo(nombre_archivo):
    """
    Lee el archivo CSV especificado y retorna una lista de objetos Empleado.

    Parámetros:
    nombre_archivo -- el nombre del archivo a leer

    Retorno:
    Una lista de objetos Empleado.
    """
    empleados = []
    
    try:
        with open(nombre_archivo, 'r') as f:
            lineas = f.readlines()

        for linea in lineas:
            nombre, correo, edad, departamento, salario = map(str.strip, linea.split(','))

            # Si alguna entrada no es válida, se salta la línea actual y se procesa la siguiente
            if not all([validar_entrada(nombre, "^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$"),
                        validar_entrada(correo, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"),
                        validar_entrada(edad, "^[0-9]+$"),
                        validar_entrada(departamento, "^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$"),
                        validar_entrada(salario, "^[0-9]*\\.?[0-9]+$")]):
                continue

            empleados.append(Empleado(nombre, correo, int(edad), departamento, float(salario)))

    except FileNotFoundError:
        raise ValueError (f"No se encontró el archivo {nombre_archivo}")

    return empleados

def main():
    empleados = leer_archivo('../employees.csv')

    while True:
        print("\n0: Salir")
        print("1: Consultar por departamento")
        print("2: Consultar por rango de salario")
        opcion = input("Seleccione una opción: ")

        if opcion == '0':
            break
        elif opcion == '1':
            departamento = input("Ingrese el nombre del departamento: ").strip()
            empleados_departamento = [e for e in empleados if e.departamento.lower() == departamento.lower()]
            for empleado in empleados_departamento:                
                print(empleado)

        elif opcion == '2':
            rango_salario_min = float(input("Ingrese el salario mínimo: ").strip())
            rango_salario_max = float(input("Ingrese el salario máximo: ").strip())
            empleados_salario = [e for e in empleados if rango_salario_min <= e.salario <= rango_salario_max]
            for empleado in empleados_salario:
                print(empleado)
        else:
            print("Opción no válida, intente de nuevo.")

if __name__ == "__main__":
    main()
