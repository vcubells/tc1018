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
};

template <typename T>
bool BusquedaGenerica<T>::busquedaSecuencial(T v[], T valor, int longitud)
{
    bool existe = false;
    int indice = 0;
    
    if (longitud <= 0) return false;
    
    while (!existe && indice < longitud) {
        if (v[indice++] == valor) {
            existe = true;
        }
    }
    
    return existe;
}

#endif /* defined(__busquedaGenerica__BusquedaGenerica__) */
