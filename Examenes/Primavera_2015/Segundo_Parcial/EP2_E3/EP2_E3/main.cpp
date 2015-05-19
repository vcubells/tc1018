//
//  main.cpp
//  EP2_E3
//
//  Created by Vicente Cubells Nonell on 13/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#include <iostream>
#include "../../../../../Tema_6_Estructuras_lineales/LinkedList/LinkedList/LinkedList.h"

using namespace vcn;

void addSets(LinkedList<char> *, LinkedList<char> *);
LinkedList<char> * multiSets(LinkedList<char> *, LinkedList<char> *);


int main(int argc, const char * argv[]) {
    
    char * cadena = "(({3}+({1,4,2}))*({1,2,3,4,5}*{4,3,2,5}*{2,3,4,5,6}+{}))+{}";
    
    
    

    
    return 0;
}


void addSets(LinkedList<char> * first, LinkedList<char> * second)
{
    for (auto item : *first) {
        second->insertBack(item.getInfo());
    }
    
    delete second;
}

LinkedList<char> * multiSets(LinkedList<char> * first, LinkedList<char> * second)
{
    LinkedList<char> * temp = new LinkedList<char>();
    char element;
    
    for (auto item : *first) {
        element = item.getInfo();
        
        if ( second->search(element) )
        {
            temp->insertBack(element);
        }
    }
    
    delete first;
    delete second;
    
    return temp;
    
}