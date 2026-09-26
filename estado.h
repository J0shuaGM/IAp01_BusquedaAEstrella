// Universidad de La Laguna Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Inteligencia Artificial
// Curso: 3º
// Practica 1: Buesqueda en estrella
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 24/09/2026
// Archivo: estado.h, declaracion de la estructura de datos de estado

#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <vector>
#include <cmath>

struct Estado {
  int fila_, columna_; 
  std::pair<int, int> posicion{fila_, columna_};

  int costeAcumulado_; //g(s)
  int valorHeuristica_; // h(s)
  int valorFuncion_; //f(s) = g(s) + h(s)

  Estado* padre_; 

  Estado(int fila, int columna, int costeG = 0, int costeH = 0, Estado* padre = nullptr)
      : fila_(fila), columna_(columna), costeAcumulado_(costeG), valorHeuristica_(costeH), valorFuncion_(costeG + costeH), padre_(padre) {}
  
  bool operator>(const Estado& otro) const {
    return this->fila_ > otro.fila_;
  }
  
  bool CompararPos(const Estado& otro) const {
    return (this->fila_ == otro.fila_ && this->columna_ == otro.columna_);
  }
};

struct ComparadorEstado {
  bool operator()(const Estado* a, const Estado* b) {
    return a->valorFuncion_ > b->valorFuncion_;
  }
};

#endif