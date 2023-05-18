# Definir el compilador
CXX = g++

# Definir archivos a compilar
OBJ = empleado.cpp db.cpp

# Objetivo por defecto
all: doxy program run

# Compilar y enlazar el programa principal
program: $(OBJ)
	$(CXX) -o program.exe $(OBJ)

# Ejecutar el programa
run: program # Esta linea asegura que el target program se ejecuta antes que el target run
	./program.exe

doxy: 
	doxygen Doxyfile

# Regla para limpiar archivos objeto y ejecutables
clean:
	rm -f $(OBJ) $(TEST_OBJ) program.exe
