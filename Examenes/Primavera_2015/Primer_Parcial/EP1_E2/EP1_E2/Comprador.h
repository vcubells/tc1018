//
//  Comprador.h
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef ___EP__Comprador__
#define ___EP__Comprador__

#include <iostream>

class Comprador {
private:
    std::string nombre;
    std::string  apellidos;
    std::string ife;
    
public:
    Comprador();
    Comprador(std::string, std::string, std::string );
    
    std::string getNombre();
    void setNombre(std::string value);
    
    std::string  getApellidos();
    void setApellidos(std::string value);
    
    std::string getIfe();
    void setIfe(std::string value);
    
    bool operator ==(Comprador &);

    friend std::ostream & operator <<(std::ostream &, Comprador &);
};

#endif /* defined(___EP__Comprador__) */
