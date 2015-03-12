//
//  Computadora.h
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 24/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __LinkedList__Computadora__
#define __LinkedList__Computadora__

#include <iostream>

namespace vcn {
    
    class Computadora {
        std::string pantalla;
        int ram;
        float frecuencia;
    public:
        
        Computadora() : Computadora("0x0", 0, 0.0) { }
        
        Computadora(std::string _pantalla, int _ram, float _frecuencia)
        : pantalla(_pantalla), ram(_ram), frecuencia(_frecuencia)
        {}
        
        friend std::ostream & operator <<(std::ostream & os, Computadora &);
    };

}
#endif /* defined(__LinkedList__Computadora__) */
