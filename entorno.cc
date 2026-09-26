// Universidad de La Laguna Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Inteligencia Artificial
// Curso: 3º
// Practica 1: Buesqueda en estrella
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 24/09/2026
// Archivo: entorno.h, definicion de la clase entorno

#include "entorno.h"
#include <sstream>

Entorno::Entorno(const std::ifstream& entrada) {
  std::string linea;
  std::ifstream& flujo = const_cast<std::ifstream&>(entrada);
  filas_ = 0;
  columnas_ = 0;
  entorno_.clear();
  while (std::getline(flujo, linea)) {
    std::istringstream stream(linea);
    std::vector<int> fila;
    int valor;
    while (stream >> valor) {
      fila.push_back(valor);
    }
    if (fila.empty()) {
      continue;
    }
    const int indiceFila = static_cast<int>(entorno_.size());
    for (int columna = 0; columna < static_cast<int>(fila.size()); ++columna) {
      if (fila[columna] == 0) {
        origen_ = {indiceFila, columna};
      } else if (fila[columna] == 10) {
        destino_ = {indiceFila, columna};
      }
    }
    columnas_ = std::max(columnas_, static_cast<int>(fila.size()));
    entorno_.push_back(fila);
  }
  filas_ = static_cast<int>(entorno_.size());
}

bool Entorno::MovimientoValido(int fila, int columna) {
  if(fila < 0 || fila >= filas_) {
    return false; 
  } else if(columna < 0 || columna >= static_cast<int>(entorno_[fila].size())) {
    return false; 
  } else if(this->Coste(fila, columna) == -1) {
    return false;
  }
  return true; 
}

int Entorno::Coste(int fila, int columna) {
  if(entorno_[fila][columna] == 10) return 2; 
  return entorno_[fila][columna];
}

std::ostream& operator<<(std::ostream& os, const Entorno& entorno) {
  std::vector<std::vector<int>> mapa = entorno.getEntorno();
  for (const auto& fila : mapa) {
    for (int valor : fila) {
      os << valor << " ";
    }
    os << std::endl;
  }
  return os;
}