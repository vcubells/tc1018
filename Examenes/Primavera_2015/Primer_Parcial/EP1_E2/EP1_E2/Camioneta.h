//
//  Camioneta.h
//  EP1_E2
//
//  Created by Vicente Cubells Nonell on 19/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef ___EP__Camioneta__
#define ___EP__Camioneta__

#include <iostream>

#include "Auto.h"

class Camioneta : public Auto {
private:
    std::string traccion;
    
public:
    Camioneta();
    Camioneta(int, std::string, int, float, std::string);
    
    std::string getTraccion();
    void setTraccion(std::string value);
    
    friend std::ostream & operator <<(std::ostream & os, Camioneta & a);
    
};

#endif /* defined(___EP__Camioneta__) */
