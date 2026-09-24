// Universidad de La Laguna Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Inteligencia Artificial
// Curso: 3º
// Practica 1: Buesqueda en estrella
// Autor: Joshua Gomez Marrero
// Correo: alu0101477398@ull.edu.es
// Fecha: 24/09/2026
// Archivo: tools.cc

#include "tools.h"



/**
 * @brief Funcion que asegura el correcto uso de la linea de ejecucion
 * @param argc Entero que contiene el numero de argumentos pasados por linea de ejecucion
 * @param argv Array que contiene los argumentos pasados por linea de ejecucion
*/
void Usage(int argc, char* argv[]) {
  switch (argc) {
    case 2: {
      std::string parametro = argv[1];
      if (parametro == "--help") {
        std::cout << "El programa se encarga de simular una busqueda A* para econtrar un mejor camino de un punto A a B" << std::endl; 
        std::cout << "Para ello es necesario pasar un fichero que contenga el entorno que donde realizar la simulación" << std::endl;
        std::cout << "El formatno del fichero debera ser el siguiente: " << std::endl;
        std::cout << "2 2 2 2 2 2 10\n"
               "2 2 2 2 -1 2 2\n"
               "2 2 2 8 -1 8 8\n"
               "2 2 0 2 -1 8 8\n"
               "2 2 2 2 2 5 2\n"
               "2 2 -1 -1 -1 -1 -1\n"
               "2 2 2 2 2 2 2\n";
        std::cout << "Donde 0 indica la posiscion inicial del robot, 10 la posicion objetivo, -1 un obtaculo, el resto de valores corresponden al coste de movimiento (2, 5, 8)" << std::endl;
        std::exit(EXIT_SUCCESS);
      }
      break;
    }
    default: {
      std::cerr << argv[0] << ": Modo de empleo: ./p01_single_grades entorno.txt" << std::endl;
      std::cout << "Pruebe " << argv[0] << " --help para obtener mas informacion" << std::endl;
      std::exit(EXIT_SUCCESS);
    }
  }
}