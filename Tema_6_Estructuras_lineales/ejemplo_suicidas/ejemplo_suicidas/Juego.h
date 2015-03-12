//
//  Juego.h
//  ejemplo_suicidas
//
//  Created by Vicente Cubells Nonell on 12/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef __ejemplo_suicidas__Juego__
#define __ejemplo_suicidas__Juego__

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "Suicida.h"
#include "../../CircularLinkedList/CircularLinkedList/CircularLinkedList.h"

class Juego {
private:
    CircularLinkedList<Suicida> * jugadores = nullptr;
    
public:
    Juego();
    ~Juego();
    
    void adicionarJugador(Suicida);
    void jugar();
    
    friend std::ostream & operator <<(std::ostream &, const Juego &);
};

#endif /* defined(__ejemplo_suicidas__Juego__) */
