//
//  main.cpp
//  suma_vector
//
//  Created by Vicente Cubells Nonell on 19/01/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>

int suma(int [], int, int);

int main(int argc, const char * argv[]) {

    const int N = 10000;
    
    int numeros[N];
    
    srand((int) time(NULL));
    
    for (int i = 0; i < N; ++i)
    {
        numeros[i] = rand() % 5;
    }
    
    std::cout << "Suma = " << suma(numeros, 0, N) << std::endl;
    
    return 0;
}

int suma(int numeros[], int i, int n)
{
    if ( i == n)
    {
        return 0;
    }
    else {
        return numeros[i] + suma(numeros, i+1, n);
    }
}