//
//  OrdenamientoGenerico.h
//  ordenamientoGenerico
//
//  Created by Vicente Cubells Nonell on 05/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __ordenamientoGenerico__OrdenamientoGenerico__
#define __ordenamientoGenerico__OrdenamientoGenerico__

#include <iostream>

template <class T>
class Ordenamiento {
public:
    static void burbuja(T [], int, bool(*) (T, T));
    static void insercion(T [], int, bool(*) (T, T));
    static void seleccion(T [], int, bool(*) (T, T));
    
    static bool asc(T, T);
    static bool desc(T, T);
    
};

template <class T>
bool Ordenamiento<T>::asc(T a, T b)
{
    return a > b;
}

template <class T>
bool Ordenamiento<T>::desc(T a, T b)
{
    return a < b;
}

template <class T>
void Ordenamiento<T>::burbuja(T v[] , int n, bool compara (T, T))
{
    T temp;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            //if (v[j-1] > v[j])
            if ( compara(v[j-1], v[j]) )
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
}

template <class T>
void Ordenamiento<T>::insercion(T v[], int n, bool compara (T, T))
{
    T index;
    
    for (int i=1; i < n; i++)
    {
        index = v[i];
        
        int j = i-1;
        
        //while (j >= 0 && v[j] > index)
        while ( j >= 0 && compara(v[j], index) )
        {
            v[j + 1] = v[j];
            j--;
        }
        
        v[j+1] = index;
    }
}

template <class T>
void Ordenamiento<T>::seleccion(T v[], int n, bool compara (T, T))
{
    int minimo = 0;
    T temp;
    
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            //if (v[minimo] > v[j])
            if ( compara(v[minimo], v[j]) )
                minimo = j;
        }
        temp = v[minimo];
        v[minimo] = v[i];
        v[i] = temp;
    }
}

#endif /* defined(__ordenamientoGenerico__OrdenamientoGenerico__) */
