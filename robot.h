// Universidad de La Laguna Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Inteligencia Artificial
// Curso: 3º
// Practica 1: Buesqueda en estrella
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 24/09/2026
// Archivo: robot.h, declaracion de la clase robot

#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#include "entorno.h"
#include "estado.h"

class Robot {
  public: 
    //Constructor
    Robot(Entorno entorno) : entorno_(entorno) {}

    //Metodos
    int funcionHeuristica(int fila, int columna, int destinoFila, int destinoColumna) const;
    void ejecutarBusqueda();
    void imprimirResultado(const std::vector<Estado*>& camino_encontrado);
    void imprimirIteracion(int iterador, std::priority_queue<Estado*, std::vector<Estado*>, ComparadorEstado>& abiertos, const std::vector<Estado*>& cerrado);
    void imprimirNoResultado(void);

  private: 
    Entorno entorno_; 
    int MovimientoColumna_[4] = {1, -1, 0, 0}; 
    int MovimientoFila_[4] = {0, 0, 1, -1};
};

#endif