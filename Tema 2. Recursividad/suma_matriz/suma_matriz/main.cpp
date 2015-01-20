//
//  main.cpp
//  suma_matriz
//
//  Created by Vicente Cubells Nonell on 19/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

#define N 4
#define M 6

void imprimeMatriz(int m[N][M]);
int sumaMatriz(int m[N][M], int f, int c);

int main(int argc, const char * argv[])
{
    
    int matriz[N][M] = {0};
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            matriz[i][j] = rand() % 5;
        }
    }
    
    std::cout << " ------- Matriz -------------" << std::endl;
    imprimeMatriz(matriz);
    
    std::cout << "La suma de los elementos de la matriz es = " << sumaMatriz(matriz, N-1, M-1) << std::endl;
    
    
    return 0;
}


void imprimeMatriz(int m[N][M])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int sumaMatriz(int m[N][M], int f, int c)
{
    if (f == 0 && c == 0) {
        return m[f][c];
    }
    else if (c == 0) {
        return m[f][c] + sumaMatriz(m, f-1, M-1);
    }
    else {
        return m[f][c] + sumaMatriz(m, f, c-1);
    }
}
