//
//  Persona.h
//  ordenamientoGenerico
//
//  Created by Vicente Cubells Nonell on 09/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __ordenamientoGenerico__Persona__
#define __ordenamientoGenerico__Persona__

#include <iostream>
#include <string>
#include <ostream>

class Persona {
private:
    std::string nombre;
    std::string apellidos;
    int edad;
    
public:
    Persona() : Persona("", "", 0) {}
    Persona(std::string _nombre, std::string _apellidos , int _edad) : nombre(_nombre), apellidos(_apellidos), edad(_edad) {}
    
    bool operator >(Persona & persona);
    bool operator <(Persona & persona);
    
    friend std::ostream & operator << (std::ostream & os, const Persona & persona);
    
};
#endif /* defined(__ordenamientoGenerico__Persona__) */
