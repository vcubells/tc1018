//
//  Libro.cpp
//  busquedaGenerica
//
//  Created by Vicente Cubells Nonell on 22/01/15.
//
//

#include "Libro.h"

Libro::Libro() : Libro("Sin título", 0, "---")
{
    
}

Libro::Libro(std::string t, int ap, std::string i) : titulo(t), anio_pub(ap), isbn(i)
{
    
}

std::ostream & operator <<(std::ostream & os, Libro & libro)
{
    os << libro.titulo << std::endl;
    
    return os;
}