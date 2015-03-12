//
//  Juego.cpp
//  ejemplo_suicidas
//
//  Created by Vicente Cubells Nonell on 12/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include "Juego.h"

Juego::Juego()
{
    jugadores = new CircularLinkedList<Suicida>();
}

Juego::~Juego()
{
    delete jugadores;
}

void Juego::adicionarJugador(Suicida suicida)
{
    jugadores->insertBack(suicida);
}

void Juego::jugar()
{
    if (jugadores->size() < 2) {
        std::cout << " ALERTA: Para jugar deben existir al menos 2 jugadores ...";
        std::cout << std::endl;
        
        return;
    }
    
    srand((int)time(nullptr));
    
    int index;
    
    Node<Suicida> * jugadorAEliminar;
    Node<Suicida> * jugadorQueElimina;
    
    std::cout << " ¡¡¡ Comienza el juego ... !!!" << std::endl;
    
    while (jugadores->size() > 1)
    {
        index = rand() % jugadores->size();
        
        jugadorQueElimina = jugadores->at(index);
        
        jugadorAEliminar = jugadorQueElimina->getNext();
        
        std::cout << *jugadorQueElimina << " acaba de matar a " << *jugadorAEliminar;
        std::cout << std::endl;
        
        jugadorAEliminar = jugadores->LinkedList<Suicida>::remove(jugadorAEliminar);
        
        delete jugadorAEliminar;
        
        /* Intervalos de 1 segundo */
        sleep(1);
    }
    
    std::cout << "Se acabó el juego y solo sobrevivió el jugador ";
    std::cout << *jugadores->first() << std::endl;
}

std::ostream & operator <<(std::ostream & os, const Juego & juego)
{
    os << "--- Lista de jugadores activos --- " << std::endl;
    
  //  os << juego.jugadores << std::endl;
    
    return os;
}