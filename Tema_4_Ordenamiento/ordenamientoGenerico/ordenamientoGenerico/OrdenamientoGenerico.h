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
    
    static void quicksort(T [], int, int, bool(*) (T, T));
    static void mergesort(T [], int, int, bool(*) (T, T), int);
    static void merge(T [], int, int, int, bool(*) (T, T), int);
    
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

template <class T>
void Ordenamiento<T>::quicksort(T v[], int primero, int ultimo, bool compara (T, T))
{
    int izquierdo = primero;
    int derecho = ultimo;
    T temp;
    
    //Se selecciona pivote
    T pivote = v[primero];
    
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && !compara(v[izquierdo], pivote)) izquierdo++; // <=
            while ( compara(v[derecho], pivote) ) derecho--; // >
            
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = v[derecho];
                v[derecho] = v[izquierdo];
                v[izquierdo] = temp;
            }
        }
        
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = v[derecho];
        v[derecho] = v[primero];
        v[primero] = temp;
        
        // Paso recursivo
        quicksort ( v, primero, derecho-1, compara);
        quicksort ( v, izquierdo, ultimo, compara);
    }
}

template <class T>
void Ordenamiento<T>::mergesort(T v[], int l, int n, bool compara (T, T), int N)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergesort (v, l, m, compara, N);
        mergesort (v, m+1, n, compara, N);
        merge (v, l, m, n, compara, N);
    }
}

template <class T>
void Ordenamiento<T>::merge(T v[], int l, int m, int n, bool compara (T, T), int N)
{
    int i, j, k;
    T aux[N];   //Vector auxiliar
    
    for(i=m+1;i>l;i--)
        aux[i-1] = v[i-1];
    
    for (j=m; j<n; j++)
        aux[n+m-j] = v[j+1];
    
    for(k=l;k<=n;k++)       //Mezcla
        if (!compara(aux[i], aux[j])) // <
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
}


#endif /* defined(__ordenamientoGenerico__OrdenamientoGenerico__) */
