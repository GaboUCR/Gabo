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
    return bool(re.match(patron, entrada))


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
            nombre, correo, edad, departamento, \
                salario = map(str.strip, linea.split(','))
            print(
                f"Nombre: {nombre}, Correo: {correo}, Edad: {edad}, \
                    Departamento: {departamento}, Salario: {salario}"
            )
            if not all([
                validar_entrada(nombre, "^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$"),
                validar_entrada(correo, "^[a-zA-Z0-9._%+-]+@\
                                [a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"),
                validar_entrada(edad, "^[0-9]+$"),
                validar_entrada(departamento, "^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$"),
                validar_entrada(salario, "^[0-9]*\\.?[0-9]+$")
            ]):
                continue

            empleados.append(Empleado(nombre, correo, int(edad),
                             departamento, float(salario)))

    except FileNotFoundError:
        raise FileNotFoundError("No existe el archivo")

    return empleados


def buscar_por_departamento(empleados, departamento):
    """
    Filtra los empleados por departamento.

    Parámetros:
    empleados -- lista de empleados
    departamento -- nombre del departamento

    Retorno:
    Una lista de empleados que pertenecen al departamento.
    """
    if not validar_entrada(departamento, "^[a-zA-Z ]+$"):
        raise ValueError("Entrada de departamento inválida.")
    return [empleado for empleado in empleados
            if empleado.departamento == departamento]


def buscar_por_salario(empleados, salario_minimo, salario_maximo):
    """
    Filtra los empleados por rango de salario.

    Parámetros:
    empleados -- lista de empleados
    salario_minimo -- salario mínimo
    salario_maximo -- salario máximo

    Retorno:
    Una lista de empleados cuyo salario está en el rango especificado.
    """
    if not all([
        validar_entrada(str(salario_minimo), "^\\$?[0-9]+(\\.[0-9]+)?$"),
        validar_entrada(str(salario_maximo), "^\\$?[0-9]+(\\.[0-9]+)?$")
    ]):
        raise ValueError("Entrada de salario inválida.")

    return [empleado for empleado in empleados
            if salario_minimo <= empleado.salario <= salario_maximo]
