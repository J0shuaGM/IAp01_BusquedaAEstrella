// Universidad de La Laguna Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Inteligencia Artificial
// Curso: 3º
// Practica 1: Buesqueda en estrella
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 24/09/2026
// Archivo: entorno.h, delcaracion de la clase entorno

#ifndef ENTORNO_H
#define ENTRONO_H

#include <iostream>
#include <vector>
#include <fstream>


class Entorno {
  public: 
    //Constructor
    Entorno(const std::ifstream& entrada);

    //Destructor 
    ~Entorno(void) {}

    //Getters
    std::vector<std::vector<int>> getEntorno(void) { return entorno_; }
    int getFilas(void) { return filas_; }
    int getColumnas(void) { return columnas_; }
    std::pair<int, int> getOrigen(void) { return origen_; }
    std::pair<int, int> getDestino(void) { return destino_; }

    //Getters constantes
    std::vector<std::vector<int>> getEntorno(void) const { return entorno_; }
    int getFilas(void) const { return filas_; }
    int getColumnas(void) const { return columnas_; }
    std::pair<int, int> getOrigen(void) const { return origen_; }
    std::pair<int, int> getDestino(void) const { return destino_; }

    //Metodos
    int Coste(int fila, int columna) { return entorno_[fila][columna]; }
    bool MovimientoValido(int fila, int columna);

    //Sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream& os, const Entorno& entorno);

  private: 
    std::vector<std::vector<int>> entorno_;
    int filas_, columnas_; 
    std::pair<int, int> origen_, destino_;
};

#endif