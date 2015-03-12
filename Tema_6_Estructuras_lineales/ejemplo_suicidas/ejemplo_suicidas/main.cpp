//
//  main.cpp
//  ejemplo_suicidas
//
//  Created by Vicente Cubells Nonell on 12/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Juego.h"

int main(int argc, const char * argv[]) {
    
    using namespace vcn;
    
    Juego * suicidas = new Juego();
    
    /* Adicionar jugadores */
    
    suicidas->adicionarJugador( {"Juan"} );
    suicidas->adicionarJugador( {"Maria"} );
    suicidas->adicionarJugador( {"Pedro"} );
    suicidas->adicionarJugador( {"Elena"} );
    suicidas->adicionarJugador( {"Jorge"} );
    suicidas->adicionarJugador( {"Juana"} );
    
    /* Lista de jugadores */
    std::cout << "--- Listado de jugadores --- " << std::endl;
    std::cout << *suicidas << std::endl;
    
    suicidas->jugar();
    
    delete suicidas;
    
    return 0;
}
