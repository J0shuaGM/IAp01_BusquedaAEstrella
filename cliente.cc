// Universidad de La Laguna Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Inteligencia Artificial
// Curso: 3º
// Practica 1: Buesqueda en estrella
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 24/09/2026
// Archivo: cliente.cc

#include <iostream>

#include "tools.h"
#include "robot.h"
#include "estado.h"

int main(int argc, char *argv[]) {
  Usage(argc, argv); 
  std::string nombre_fichero = argv[1]; 
  std::ifstream entrada(nombre_fichero); 
  if(!entrada.is_open()) {
    std::cerr << "El fichero de entrada no se ha podido abrir" << std::endl;
    exit(EXIT_FAILURE);
  }
  Entorno entorno(entrada); 
  entrada.close();
  Robot robot(entorno);
  robot.ejecutarBusqueda();
  return 0; 
}