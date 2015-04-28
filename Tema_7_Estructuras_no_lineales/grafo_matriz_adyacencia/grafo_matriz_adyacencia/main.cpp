//
//  main.cpp
//  grafo_matriz_adyacencia
//
//  Created by Vicente Cubells Nonell on 20/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

#include "Ciudad.h"

int main(int argc, const char * argv[]) {
    
    const int numero_ciudades = 5;
    
    srand((int) time( nullptr));
    
    std::vector<Ciudad *> ciudades(numero_ciudades) ;
    
    /* Generar listado de ciudades */
    for (int i = 0; i < numero_ciudades; ++i) {
        std::string cname = "Ciudad ";
        cname += std::to_string(i+1);
        ciudades[i] = new Ciudad( cname , rand() % 10000000);
    }
    
    /* Mostrar las ciudades */
    for (auto c : ciudades) {
        std::cout << *c;
    }
    
    /* Crear matriz de adyacencia */
    std::vector < std::vector<int> > matriz_adyacencia(numero_ciudades);
    
    for (int i = 0; i < numero_ciudades; ++i) {
        matriz_adyacencia[i] = std::vector<int>(numero_ciudades);
        std::fill(matriz_adyacencia[i].begin(), matriz_adyacencia[i].end(), -1);
        matriz_adyacencia[i][i] = 0;
    }
    
    
    /* Adicionar rutas al grafo */
    matriz_adyacencia[0][1] = 30;
    matriz_adyacencia[0][4] = 100;
    
    matriz_adyacencia[1][0] = 50;
    matriz_adyacencia[1][3] = 75;
    
    matriz_adyacencia[2][3] = 20;
    
    matriz_adyacencia[3][1] = 60;
    
    matriz_adyacencia[4][2] = 15;

    
    /* Mostrar matriz de adyacencia */
    std::cout << " --- Matriz de Adyacencia --- " << std::endl;
    
    int i = 0;
    for (auto fila : matriz_adyacencia) {
        std::cout << ciudades[i++]->getName() << "\t";
        std::copy(fila.begin(),
                  fila.end(), std::ostream_iterator<int>(std::cout, "\t"));
        
        std::cout << std::endl;
    }
    
    
    
    
    
    
    return 0;
}
