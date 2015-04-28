//
//  Edge.h
//  Graph
//
//  Created by Vicente Cubells Nonell on 23/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef Graph_Edge_h
#define Graph_Edge_h

#include <vector>

template <class V, class E>
class Vertex;

template <class V, class E>
class Edge {
    E info;
    Vertex<V, E> * target = nullptr;
    
public:
    Edge() { }
    Edge(E _info, Vertex<V, E> * _target)
    : info(_info), target(_target) { }
    
    ~Edge() { target = nullptr; }
    
    E getInfo() const;
    void setInfo(const E &);
    
    Vertex<V, E> * getTarget() const;
    void setTarget(const Vertex<V, E> *);
    
    template <class Vn, class En>
    friend std::ostream & operator <<(std::ostream & , const  Edge<Vn, En> &);

};

template <class V, class E>
E Edge<V, E>::getInfo() const
{
    return info;
}

template <class V, class E>
void Edge<V, E>::setInfo(const E & value)
{
    info = value;
}

template <class V, class E>
Vertex<V, E> * Edge<V, E>::getTarget() const
{
    return target;
}

template <class V, class E>
void Edge<V, E>::setTarget(const Vertex<V, E> * vertex)
{
    target = vertex;
}

template <class V, class E>
std::ostream & operator <<(std::ostream & os , const  Edge<V, E> & edge  )
{
    os << edge.info << " ---> " << edge.getTarget()->getInfo() << std::endl;
    
    return os;
}

#endif
