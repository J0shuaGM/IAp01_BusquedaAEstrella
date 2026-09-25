// Universidad de La Laguna Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Inteligencia Artificial
// Curso: 3º
// Practica 1: Buesqueda en estrella
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 24/09/2026
// Archivo: robot.h, definicion de la clase objeto robot

#include "robot.h"

int Robot::funcionHeuristica(int fila, int columna, int destinoFila, int destinoColumna) const {
  return 2 * (std::abs(destinoFila - fila) + std::abs(destinoColumna - columna));
}