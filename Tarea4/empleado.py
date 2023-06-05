class Empleado:
    # Constructor de la clase
    def __init__(self, nombre, correo, edad, departamento, salario):
        # Estos son los atributos "privados" de la clase. 
        # La convención en Python es usar un guión bajo antes del nombre para indicar que son privados.
        self._nombre = nombre
        self._correo = correo
        self._edad = edad
        self._departamento = departamento
        self._salario = salario

    # Decorador @property. Este se usa para crear una propiedad que puede ser accesible públicamente
    # Cuando alguien llame a empleado.nombre, Python automáticamente llamará a este método.
    @property
    def nombre(self):
        # Este método simplemente retorna el valor del atributo privado _nombre.
        return self._nombre

    # Decorador @nombre.setter. Este se usa para permitir que la propiedad nombre sea modificada públicamente.
    # Cuando alguien llame a empleado.nombre = "Nuevo nombre", Python automáticamente llamará a este método.
    @nombre.setter
    def nombre(self, nombre):
        # Este método actualiza el valor del atributo privado _nombre.
        self._nombre = nombre

    # Lo mismo se aplica para los atributos restantes.
    @property
    def correo(self):
        return self._correo

    @correo.setter
    def correo(self, correo):
        self._correo = correo

    @property
    def edad(self):
        return self._edad

    @edad.setter
    def edad(self, edad):
        self._edad = edad

    @property
    def departamento(self):
        return self._departamento

    @departamento.setter
    def departamento(self, departamento):
        self._departamento = departamento

    @property
    def salario(self):
        return self._salario

    @salario.setter
    def salario(self, salario):
        self._salario = salario
