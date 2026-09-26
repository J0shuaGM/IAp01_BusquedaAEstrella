# Universidad de La Laguna
# Escuela Superior de Ingenieria y Tecnologia
# Grado en Ingenieria Informatica
# Asignatura: Inteligencia Artificial
# Curso: 3º
# Practica 1: Buesqueda en estrella
# Autor: Joshua Gomez Marrero
# Correo: alu0101477398@ull.edu.es
# Fecha: 24/09/2026
# Archivo: Makefile

# Nombre del archivo de salida
TARGET = busqueda

# Lista de archivos fuente(.cc)
SOURCES = cliente.cc entorno.cc tools.cc robot.cc

# Dependencias de los archivos fuente 
DEPENDENCIES = entorno.h tools.h robot.h estado.h

# Opciones de compilación
CXX = g++
CXXFLAGS = -std=c++17

# Regla para compilar el programa
$(TARGET): $(SOURCES) $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) *.o

# Regla por defecto
default: $(TARGET)