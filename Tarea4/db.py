# db.py
import re
from empleado import Empleado

def validar_entrada(entrada, patron):
    return bool(re.match(patron, entrada))

def leer_archivo(nombre_archivo):
    empleados = []
    try:
        with open(nombre_archivo, 'r') as f:
            lineas = f.readlines()

        for linea in lineas:
            
            nombre, correo, edad, departamento, salario = map(str.strip, linea.split(','))
            print(f"Nombre: {nombre}, Correo: {correo}, Edad: {edad}, Departamento: {departamento}, Salario: {salario}")
            if not all([validar_entrada(nombre, "^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$"),
                        validar_entrada(correo, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"),
                        validar_entrada(edad, "^[0-9]+$"),
                        validar_entrada(departamento, "^[a-zA-ZáéíóúÁÉÍÓÚñÑ ]+$"),
                        validar_entrada(salario, "^[0-9]*\\.?[0-9]+$")]):
                raise ValueError("Datos inválidos")

            empleados.append(Empleado(nombre, correo, int(edad), departamento, float(salario)))

    except FileNotFoundError:
        raise FileNotFoundError("No existe el archivo")

    return empleados

def buscar_por_departamento(empleados, departamento):
    if not validar_entrada(departamento, "^[a-zA-Z ]+$"):
        raise ValueError("Entrada de departamento inválida.")
    return [empleado for empleado in empleados if empleado.departamento == departamento]

def buscar_por_salario(empleados, salario_minimo, salario_maximo):
    if not all([validar_entrada(str(salario_minimo), "^\\$?[0-9]+(\\.[0-9]+)?$"),
                validar_entrada(str(salario_maximo), "^\\$?[0-9]+(\\.[0-9]+)?$")]):
        raise ValueError("Entrada de salario inválida.")

    return [empleado for empleado in empleados if salario_minimo <= empleado.salario <= salario_maximo]
