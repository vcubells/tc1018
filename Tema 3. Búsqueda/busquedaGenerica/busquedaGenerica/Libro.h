//
//  Libro.h
//  busquedaGenerica
//
//  Created by Vicente Cubells Nonell on 22/01/15.
//
//

#ifndef __busquedaGenerica__Libro__
#define __busquedaGenerica__Libro__

#include <iostream>
#include <string>

class Libro {
private:
    std::string titulo;
    int anio_pub;
    std::string isbn;
    
public:
    Libro();
    Libro(std::string, int, std::string);
    
    friend std::ostream & operator <<(std::ostream &, Libro &);
    
};
#endif /* defined(__busquedaGenerica__Libro__) */
