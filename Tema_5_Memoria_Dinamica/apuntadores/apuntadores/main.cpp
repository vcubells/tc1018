//
//  main.cpp
//  apuntadores
//
//  Created by Vicente Cubells Nonell on 16/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

class Int {
    int number;
    Int * next = nullptr;
    
public:
    Int(int n) : number(n) {}
    void setNext(Int * value) { next = value; }
    Int * getNext() { return next; }
    
};

int main(int argc, const char * argv[]) {
    
    int n = 5;
    
    int * ptr  = &n;
    
    *ptr = 25;
    
    std::cout << " n = " << n << std::endl;
    std::cout << " &n = " << &n << std::endl;
    std::cout << " ptr = " << ptr << std::endl;
    std::cout << " &ptr = " << &ptr << std::endl;
    std::cout << " *ptr = " << *ptr << std::endl;
    
    std::cout << "Entre el número de elementos: ";
    
    int x;
    
    std::cin >> x;
    
    int * numeros = new int[x];
    
    /* Inicializar un arreglo utilizando aritmética de apuntadores */
//     int i = 0;
//     
//     for( int * p = numeros; p < (numeros + x); ++p)
//     {
//        *p = i++;
//     }
    
    /* Inicializar un arreglo utilizando un for tradicional */
    for (int i = 0; i < x; ++i) {
        numeros[i] = i; // Equivalente a *(numeros+i) = i;
    }
    
    /* Visualizar el contenido de un arreglo utilizando un for tradicional y aritmética de apuntadores */
    for (int i = 0; i < x; ++i)
    {
        std::cout << *(numeros+i) << std::endl;
    }
    
    /* Redimensionando un arreglo */
    std::cout << "Entre el nuevo número de elementos: ";
    
    std::cin >> x;
    
    numeros = (int *)realloc(numeros, x * sizeof(int));
    
    for (int i = 0; i < x; ++i)
    {
        std::cout << *(numeros+i) << std::endl;
    }

    
    /* Ejemplo de enlazar números */
    
    Int a(1);
    Int b(2);
    
    
    a.setNext(&b);
    
    /* Liberar la memoria reservada para el arreglo */
    delete[] numeros;
    
    return 0;
}
