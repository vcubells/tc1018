//
//  Moto.h
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef ___EP__Moto__
#define ___EP__Moto__

#include "Auto.h"

class Moto : public Auto {
private:
    int cilindraje;
    
public:
    Moto();
    Moto(int, std::string, int, float, int);
    
    int getCilindraje();
    void setCilindraje(int value);
    
    friend std::ostream & operator <<(std::ostream &, Moto &);
    
};

#endif /* defined(___EP__Moto__) */
