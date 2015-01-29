//
//  BusquedaGenerica.h
//  busquedaGenerica
//
//  Created by Vicente Cubells Nonell on 22/01/15.
//
//

#ifndef __busquedaGenerica__BusquedaGenerica__
#define __busquedaGenerica__BusquedaGenerica__

template <typename T>
class BusquedaGenerica {
public:
    static bool busquedaSecuencial(T [], T , int );
    static bool busquedaBinaria(T [], T, int, int);
    
    /* Variantes que regresan la posición o -1 si no existe */
    static int busquedaSecuencialPosicion(T [], T , int );
    static int busquedaBinariaPosicion(T [], T, int, int);
};

template <typename T>
bool BusquedaGenerica<T>::busquedaSecuencial(T v[], T valor, int longitud)
{
    bool existe = false;
    int indice = 0;
    
    if (longitud <= 0) return existe;
    
    while (!existe && indice < longitud) {
        if (v[indice++] == valor) {
            existe = true;
        }
    }
    
    return existe;
}

template <typename T>
bool BusquedaGenerica<T>::busquedaBinaria(T v[], T valor, int inferior, int superior)
{
    if (inferior >= superior)
    {
        return false;
    }
    else  {
        int mitad = (inferior + superior) / 2;
        
        if (v[mitad] == valor) {
            return true;
        }
        else if (valor < v[mitad])
            return busquedaBinaria(v, valor, inferior, mitad);
        else
            return busquedaBinaria(v, valor, mitad + 1, superior);
    }
}

/* Implementaciones de variantes que regresan la pisición */

template <typename T>
int BusquedaGenerica<T>::busquedaSecuencialPosicion(T v[], T valor, int longitud)
{
    int existe = -1;
    int indice = 0;
    
    if (longitud <= 0) return existe;
    
    while (existe == -1 && indice < longitud) {
        if (v[indice++] == valor) {
            existe = indice;
        }
       
    }
    
    return existe;
}

template <typename T>
int BusquedaGenerica<T>::busquedaBinariaPosicion(T v[], T valor, int inferior, int superior)
{
    if (inferior >= superior)
    {
        return -1;
    }
    else  {
        int mitad = (inferior + superior) / 2;
        
        if (v[mitad] == valor) {
            return mitad;
        }
        else if (valor < v[mitad])
            return busquedaBinaria(v, valor, inferior, mitad);
        else
            return busquedaBinaria(v, valor, mitad + 1, superior);
    }
}

#endif /* defined(__busquedaGenerica__BusquedaGenerica__) */
