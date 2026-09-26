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



void Robot::ejecutarBusqueda() {
  std::priority_queue<Estado*, std::vector<Estado*>, ComparadorEstado> abiertos;
  std::vector<Estado*> cerrados;

  Estado inicial(entorno_.getOrigen().first, entorno_.getOrigen().second);
  inicial.costeAcumulado_ = 0; //g(s)
  inicial.valorHeuristica_ = funcionHeuristica(inicial.fila_, inicial.columna_, entorno_.getDestino().first, entorno_.getDestino().second); //h(s)
  inicial.valorFuncion_ = inicial.costeAcumulado_ + inicial.valorHeuristica_; //f(s)
  inicial.padre_ = nullptr;
  abiertos.push(new Estado(inicial));

  int iterador = 0; 
  bool solucion_encontrada = false; 

  while(!abiertos.empty()) {
    //IMPRIMIR ITERACION ANTERIOR
    imprimirIteracion(iterador, abiertos, cerrados);
    ++iterador; 

    Estado actual = *abiertos.top();
    abiertos.pop();
    if(actual.posicion == entorno_.getDestino()) {
      std::vector<Estado*> camino_encontrado; 
      Estado* ruta = new Estado(actual); 
      while(ruta != nullptr) {
        camino_encontrado.push_back(ruta);
        ruta = ruta->padre_;
      }
      std::reverse(camino_encontrado.begin(), camino_encontrado.end());

      //IMPRIMIR RESULTADO
      imprimirResultado(camino_encontrado);
      solucion_encontrada = true;
      break;
    }
    cerrados.push_back(new Estado(actual));
    for(int i = 0; i < 4; ++i) {
      int fila_vecino = actual.fila_ + MovimientoFila_[i]; 
      int columna_vecino = actual.columna_ + MovimientoColumna_[i]; 
      Estado vecino(fila_vecino, columna_vecino);
      if(!entorno_.MovimientoValido(fila_vecino, columna_vecino)) {
        continue;
      }
      bool en_cerrado = false;
      for(auto estado : cerrados) {
        if(estado->CompararPos(vecino)) {
          en_cerrado = true;
          break;
        }
      }
      if(en_cerrado) continue;

      int vecino_costeAcumulado = actual.costeAcumulado_ + entorno_.Coste(fila_vecino, columna_vecino); 
      int vecino_heuristica = funcionHeuristica(fila_vecino, columna_vecino, entorno_.getDestino().first, entorno_.getDestino().second);
      int vecino_costeFinal = vecino_costeAcumulado + vecino_heuristica;
      bool ya_abierto = false;
      std::priority_queue<Estado*, std::vector<Estado*>, ComparadorEstado> temporal;
      while (!abiertos.empty()) {
        Estado* estado_abierto = abiertos.top();
        abiertos.pop();
        if (estado_abierto->CompararPos(vecino)) {
          ya_abierto = true;
          if (vecino_costeAcumulado < estado_abierto->costeAcumulado_) {
            estado_abierto->costeAcumulado_ = vecino_costeAcumulado;
            estado_abierto->valorHeuristica_ = vecino_heuristica;
            estado_abierto->valorFuncion_ = vecino_costeFinal;
            estado_abierto->padre_ = new Estado(actual);
          }
        }
        temporal.push(estado_abierto);
      }
      abiertos.swap(temporal);
      if (!ya_abierto) {
        vecino.costeAcumulado_ = vecino_costeAcumulado;
        vecino.valorHeuristica_ = vecino_heuristica;
        vecino.valorFuncion_ = vecino_costeFinal;
        vecino.padre_ = new Estado(actual);
        abiertos.push(new Estado(vecino));
      }
    }
  }
  if(!solucion_encontrada) {
    imprimirNoResultado();
  }
}

void Robot::imprimirIteracion(int iterador, std::priority_queue<Estado*, std::vector<Estado*>, ComparadorEstado>& abiertos, const std::vector<Estado*>& cerrado) {
  std::priority_queue<Estado*, std::vector<Estado*>, ComparadorEstado> abiertos_copia = abiertos;

  std::cout << "Iteracion " << iterador << std::endl;
  std::cout << "--------------" << std::endl;
  std::cout << "Abiertos = ";
  while(!abiertos_copia.empty()) {
    Estado estado = *abiertos_copia.top();
    abiertos_copia.pop();
    std::cout << "(" << estado.fila_ << ", " << estado.columna_ << ") ";
  }
  std::cout << std::endl << "Cerrados = "; 
  for(auto estado : cerrado) {
    std::cout << "(" << estado->fila_ << ", " << estado->columna_ << ") ";
  }
  std::cout << std::endl << "--------------------------" << std::endl;
}

void Robot::imprimirResultado(const std::vector<Estado*>& camino_encontrado) {
  int coste = 0;
  std::cout << "Camino: ";
  for(auto estado : camino_encontrado) {
    int fila = estado->fila_;
    int columna = estado->columna_;
    coste = coste + entorno_.Coste(fila, columna);
    std::cout << "(" << estado->fila_ << ", " << estado->columna_ << ") -> ";
  }
  std::cout << std::endl;
  std::cout << "Coste: " << coste << std::endl;

}

void Robot::imprimirNoResultado() {
  std::cout << "No se ha encontrado ninguna solucion al problema" << std::endl;
  exit(EXIT_SUCCESS);
}