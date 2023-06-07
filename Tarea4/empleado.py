class Empleado:
    """
    Clase que representa a un empleado.
    """

    def __init__(self, nombre, correo, edad, departamento, salario):
        """
        Constructor de la clase Empleado.

        Parámetros:
        nombre -- nombre del empleado
        correo -- correo del empleado
        edad -- edad del empleado
        departamento -- departamento del empleado
        salario -- salario del empleado
        """
        self._nombre = nombre
        self._correo = correo
        self._edad = edad
        self._departamento = departamento
        self._salario = salario

    def __str__(self):
        """
        Representación de cadena de un objeto Empleado.

        Retorno:
        Un string que representa al empleado.
        """
        return (
            f"Empleado:\n"
            f"\tNombre: {self.nombre}\n"
            f"\tCorreo: {self.correo}\n"
            f"\tEdad: {self.edad}\n"
            f"\tDepartamento: {self.departamento}\n"
            f"\tSalario: {self.salario}\n"
        )

    @property
    def nombre(self):
        """
        Getter del nombre del empleado.

        Retorno:
        El nombre del empleado.
        """
        return self._nombre

    @nombre.setter
    def nombre(self, nombre):
        """
        Setter del nombre del empleado.

        Parámetro:
        nombre -- el nuevo nombre del empleado
        """
        self._nombre = nombre

    @property
    def correo(self):
        """
        Getter del correo del empleado.

        Retorno:
        El correo del empleado.
        """
        return self._correo

    @correo.setter
    def correo(self, correo):
        """
        Setter del correo del empleado.

        Parámetro:
        correo -- el nuevo correo del empleado
        """
        self._correo = correo

    @property
    def edad(self):
        """
        Getter de la edad del empleado.

        Retorno:
        La edad del empleado.
        """
        return self._edad

    @edad.setter
    def edad(self, edad):
        """
        Setter de la edad del empleado.

        Parámetro:
        edad -- la nueva edad del empleado
        """
        self._edad = edad

    @property
    def departamento(self):
        """
        Getter del departamento del empleado.

        Retorno:
        El departamento del empleado.
        """
        return self._departamento

    @departamento.setter
    def departamento(self, departamento):
        """
        Setter del departamento del empleado.

        Parámetro:
        departamento -- el nuevo departamento del empleado
        """
        self._departamento = departamento

    @property
    def salario(self):
        """
        Getter del salario del empleado.

        Retorno:
        El salario del empleado.
        """
        return self._salario

    @salario.setter
    def salario(self, salario):
        """
        Setter del salario del empleado.

        Parámetro:
        salario -- el nuevo salario del empleado
        """
        self._salario = salario
