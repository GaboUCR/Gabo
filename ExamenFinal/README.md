# Examen Final de Estructuras abstractas de datos y algoritmos para ingeniería.

## Como correr la clase calculadora

Ejecute los siguientes comandos en el directorio ExamenFinal.

Compilación:
```console
g++ Calculadora.cpp CalcuTest.cpp -o a.exe
```

Se ejecuta el programa:
```console
./a.exe
```

## pregunta 1 
El paso por valor significa que estamos proporcionando el valor directamente a la función. En este caso, si la función modifica el valor, no se refleja fuera de la función porque la función tiene su propia copia del valor.

El paso por referencia significa que estamos proporcionando la referencia (es decir, la dirección en la memoria) del valor a la función. En este caso, si la función modifica el valor, se refleja fuera de la función porque la función y el llamador están trabajando con la misma ubicación de memoria.

## pregunta 2
La recursividad es un concepto en el que una función se llama a sí misma como parte de su ejecución. Es útil en problemas donde la solución puede ser fácilmente expresada en términos de instancias más pequeñas del mismo problema. Los problemas como el recorrido de árboles, grafos y la resolución de problemas de dividir y conquistar son ejemplos donde se utiliza la recursividad.

## pregunta 3

Las listas son mutables, lo que significa que puedes cambiar su contenido. Las tuplas, en cambio, son inmutables, no puedes cambiar su contenido una vez definido.

Generalmente se utiliza una lista cuando quieres colecciones de elementos que pueden cambiar durante el transcurso del programa. Las tuplas se usan generalmente cuando sabes de antemano lo que va a ser, como los días de la semana, o cuando quieres asegurarte de que los datos no se modifiquen accidentalmente en el transcurso de un programa.

## pregunta 4

La herencia es uno de los principios fundamentales de la programación orientada a objetos. Permite definir una clase en términos de otra clase, lo que facilita la creación y el mantenimiento de una aplicación. La clase cuyos miembros se heredan se conoce como clase base, y la clase que hereda esos miembros se conoce como clase derivada.

## pregunta 5

La comprensión de listas es una forma concisa de crear listas. Simplifica el código y hace que sea más legible.

Por ejemplo, para crear una lista de los primeros diez números cuadrados, puedes hacerlo de la siguiente manera con la comprensión de listas:

```python
squares = [x**2 for x in range(1,11)]
```
Sin la comprensión de listas, tendrías que usar un bucle for, lo que hace que el código sea más largo y menos legible.

## pregunta 6

Las plantillas son una característica de C++ que permite la programación genérica. Permiten a los programadores crear código que puede manejar diferentes tipos de datos sin repetir el código.

Por ejemplo, una función de plantilla que suma dos valores podría verse así:

```c++
template <typename T>
T sum(T a, T b) {
   return a + b;
}
```

## pregunta 7

La sobrecarga de operadores permite redefinir la forma en que funcionan los operadores en tipos de datos definidos por el usuario. Esto puede hacer el código más legible y fácil de entender.

Por ejemplo, podrías sobrecargar el operador + para una clase Vector de la siguiente manera:

```c++
class Vector {
public:
    int x, y;

    Vector operator + (Vector const &obj) {
       Vector res;
       res.x = x + obj.x;
       res.y = y + obj.y;
       return res;
    }
};
```

## pregunta 8

En Python, una función es un bloque de código que realiza una tarea específica y puede ser llamado por su nombre. Un método es similar a una función, pero está asociado a un objeto/clase.

El argumento self es una referencia a la instancia actual de la clase y se utiliza para acceder a las variables que pertenecen a la clase. Se usa en la definición del método pero no se necesita al llamar al método. Por ejemplo:

```python
class MyClass:
    def my_method(self):
        # código aquí
```

Podrías llamar a my_method de la siguiente manera:
```python
obj = MyClass()
obj.my_method()
```
