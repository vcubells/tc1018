//
//  Ciudad.h
//  grafo_matriz_adyacencia
//
//  Created by Vicente Cubells Nonell on 20/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __grafo_matriz_adyacencia__Ciudad__
#define __grafo_matriz_adyacencia__Ciudad__

#include <iostream>
#include <string>

class Ciudad {
    std::string nombre = "Sin definir";
    int habitantes = 0;
    
    public:
    
    Ciudad() { } ;
    Ciudad(std::string _nombre, int _hab) : nombre(_nombre), habitantes(_hab) { }
    ~Ciudad() { }
    std::string getName() const
    {
        return nombre;
    }
    
    friend std::ostream & operator <<(std::ostream &, const Ciudad &);
    
};

#endif /* defined(__grafo_matriz_adyacencia__Ciudad__) */
