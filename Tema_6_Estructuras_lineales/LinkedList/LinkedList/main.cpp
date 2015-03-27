//
//  main.cpp
//  LinkedList
//
//  Created by Vicente Cubells Nonell on 23/02/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <string>
#include "Node.h"
#include "Computadora.h"
#include "LinkedList.h"

using namespace vcn;

int main(int argc, const char * argv[]) {
    
    /* Crear un Node entero */
    Node<int> first(1);
    
    /* Crear un Node float */
    Node<float> second(3.45);
    
    /* Crear un Node string */
    Node<std::string> cad("Esto es una cadena");
    
    /* Crear un Node de un tipo definido por el usuario */
    Computadora laptop;
    
    Node<Computadora> pc(laptop);
    
    /* Visualizar todos los tipos de nodos */
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << cad << std::endl;
    std::cout << pc << std::endl;
    
    /* Demostrar el uso de la clase genércia LinkedList<T> */
    
    /* Declaración de una lista de enteros */
    LinkedList<int> numeros;
    
    /* Determinar el tamaño */
    std::cout  << "Size = " << numeros.size() << std::endl;
    
    /* Determinar si la lista está vacía */
    std::cout  << "Empty = " << (numeros.empty() ? "true" : "false") << std::endl;
    
    /* Insertar elemento en la lista */
    numeros.insert(1, 0);
    numeros.insert(-1, -2);
    numeros.insert(-2, 0);
    numeros.insert(2, 10);
    numeros.insert(10, numeros.size());
    numeros.insert(5, 2);
    numeros.insertFront(-10);
    numeros.insertBack(20);
    
    /* Obtener el primer elemento */
    std::cout  << "First = " << numeros.first() << std::endl;
    
    /* Crear un nuevo nodo  e insertarlo en la lista */
    Node<int> * newnode = new Node<int>(30);
    
    numeros.insert(newnode, 6);
    
    /* Imprimir el contenido de la lista */
    std::cout << numeros << std::endl;
    
    /* Obtener el iésimo elemento  */
    int pos = numeros.size()-1;
    Node<int> * node = numeros.at(pos);
    
    std::cout  << "At(" << pos << ") = " << (node ? *node : Node<int>()) << std::endl;
    
    /* Obtener el iésimo elemento con el operador [] */
    pos = 100;
    node = numeros[pos];
    
    std::cout  << "numeros[" << pos << "] = " << (node ? *node : Node<int>()) << std::endl;
    
    /* Obtener la posición de un elemento dado un apuntador al mismo */
    node = numeros.at(0);
    
    std::cout  << "Node está en posición " << numeros.at(node) << std::endl;
    
    /* Borrar un nodo de la lista */
    Node<int> * removenode = numeros.remove(6);
    
    if (removenode) {
        std::cout << "Nodo a borrar = " << *removenode << std::endl;
        delete removenode;
    }
    
    /* Imprimir el contenido de la lista */
    std::cout << numeros << std::endl;
    
    /* Borrar toda la lista y liberar la memoria de todos los nodos 
     * Solo como demostración ya que aquí se invoca al destructor de la lista
     * de manera automática
    */
    
    numeros.clear();
    
}
