//
//  main.cpp
//  EF_E2
//
//  Created by Vicente Cubells Nonell on 12/05/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

#define N 27

template <typename T>
void alfombraSierpinski(T alfombra [N][N], int x1, int y1, int x2, int y2, int iteraciones, int actual);

template <typename T>
void dibujaAlfombra(T alfombra [N][N]);

int main(int argc, const char * argv[]) {
    
    /* Definir la matriz */
    int alfombra[N][N] = {0};
    
    alfombraSierpinski<int>(alfombra, 0, 0, N, N, 9, 0);
    
    dibujaAlfombra<int>(alfombra);
    
    return 0;
}

template <typename T>
void alfombraSierpinski(T alfombra [N][N], int x1, int y1, int x2, int y2, int iteraciones, int actual)
{
    if ( (actual == iteraciones) || (x2 - x1) % 3 != 0 ) { return; }
    
    int fraccion = (x2 - x1) / 3;
    
    /* Sacar el de en medio */
    for (int i = x1 + fraccion; i < x2 - fraccion; ++i) {
        for (int j = y1 + fraccion; j < y2 - fraccion; ++j) {
            alfombra[i][j] = 1;
        }
    }
    
    /* Llamadas recursivas de cada uno de los 8 cuadrados restantes */
    
    alfombraSierpinski(alfombra, x1, y1, x1+fraccion, y1+fraccion, iteraciones, actual+1);
    alfombraSierpinski(alfombra, x1+fraccion, y1, x2-fraccion, y1+fraccion, iteraciones, actual+1);
    alfombraSierpinski(alfombra, x2-fraccion, y1, x2, y1+fraccion, iteraciones, actual+1);
    alfombraSierpinski(alfombra, x1, y1+fraccion, x1+fraccion, y2-fraccion, iteraciones, actual+1);
    alfombraSierpinski(alfombra, x2-fraccion, y1+fraccion, x2, y2-fraccion, iteraciones, actual+1);
    alfombraSierpinski(alfombra, x1, y2-fraccion, x1+fraccion, y2, iteraciones, actual+1);
    alfombraSierpinski(alfombra, x1+fraccion, y2-fraccion, x2-fraccion, y2, iteraciones, actual+1);
    alfombraSierpinski(alfombra, x2-fraccion, y2-fraccion, x2, y2, iteraciones, actual+1);
}


template <typename T>
void dibujaAlfombra (T alfombra [N][N])
{
    /* Dibujar la alfombra */
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << alfombra[i][j] << "\t";
        }
        
        std::cout << std::endl;
    }
}