//
//  Auto.h
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef ___EP__Auto__
#define ___EP__Auto__

#include <iostream>
#include <string>

class Auto {
private:
    int codigo;
    std::string marca;
    int modelo;
    float kilometraje;
    
public:
    Auto();
    Auto(int, std::string, int, float);
    
    int getCodigo();
    void setCodigo(int value);
    
    std::string getMarca();
    void setMarca(std::string value);
    
    int getModelo();
    void setModelo(int value);
    
    float getKilometraje();
    void setKilometraje(float value);
    
    friend std::ostream & operator <<(std::ostream &, Auto &);
    
};

#endif /* defined(___EP__Auto__) */
