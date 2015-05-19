//
//  main.cpp
//  EF_E3
//
//  Created by Vicente Cubells Nonell on 12/05/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include "../../../../../Tema_7_Estructuras_no_lineales/BinaryTree/BinaryTree/BinaryTree.h"

using namespace vcn;

void generaArbolIterativo(BinaryTree<char> * arbol, std::string preOrden, std::string enOrden);
bool estaIzquierda(char raiz, char insertar, std::string inOrden);

int main(int argc, const char * argv[]) {
    
    /* Definición de los recorridos */
    std::string preOrden = "GEAIBMCLDFKJH";
    std::string enOrden = "IABEGLDCFMKHJ";
    
    /* Crear un árbol vacío */
    BinaryTree<char> * arbol = new BinaryTree<char>();
    
    /* Generar el árbol a partir de los recorridos dados */
    generaArbolIterativo(arbol, preOrden, enOrden);
    
    /* Verificar que los recorridos son iguales a los originales */
    arbol->preOrder();
    
    std::cout << std::endl;
    
    arbol->inOrder();

    /* Borrar el árbol con todos sus nodos */
    delete arbol;
    
    return 0;
}


         
void generaArbolIterativo(BinaryTree<char> * arbol, std::string preOrden, std::string enOrden)
{
    /* Insertar la raíz del árbol */
    arbol->insert(nullptr, preOrden[0]);
    
    long size = preOrden.length();
    
    /* Insertar los demás nodos */
    for(int i = 1; i < size; ++i)  {
        bool inserto = false;
        
        BNode<char> * tmp = arbol->getRoot();
        
        while(!inserto){
            if(estaIzquierda(tmp->getInfo(), preOrden[i], enOrden)){
                if (tmp->getLeft()) {
                    inserto = false;
                }
                else {
                    inserto = arbol->insert(tmp, preOrden[i]);
                }
                
                tmp = tmp->getLeft();
            }
            else{
                if (tmp->getRight()) {
                    inserto = false;
                }
                else {
                    tmp->setRight( new BNode<char>(preOrden[i]) );
                    tmp->getRight()->setParent(tmp);
                    inserto = true;
                }
                
                tmp = tmp->getRight();
            }
        }
    }
}

bool estaIzquierda(char raiz, char insertar, std::string inOrden)
{
    bool isIzquierda = true;

    long size = inOrden.length();
    
    for(int i = 0; i < size; ++i){
        if(inOrden[i] == insertar){
            break;
        }
        else if(inOrden[i] == raiz){
            isIzquierda = false;
            break;
        }
    }
    
    return isIzquierda;
}
