//
//  Computadora.cpp
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 24/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Computadora.h"


namespace vcn {
    
    std::ostream & operator <<(std::ostream & os, vcn::Computadora & c)
    {
        os << "Display : " << c.pantalla << " pixeles"<< std::endl;
        os << "RAM     : " << c.ram << " GB" << std::endl;
        os << "CPU     : " << c.frecuencia << " GHz" << std::endl;
        
        return os;
    }

}