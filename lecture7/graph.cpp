#include "graph.h"
#include <cassert>



template <class Verteces, class Costs>
void Graph<Verteces,Costs>::addVertex(const Verteces &v)
{
    assert(!hasVertex(v))
    graph[v];
}

template <class Verteces, class Costs>
void Graph<Verteces,Costs>addEdge(const Verteces &v1, const Verteces &v2, const Costs &c){

    assert(hasVertex(v1));
    assert(hasVertex(v2));
    graph[v1][v2] = c;
}


template <class Verteces, class Costs>
bool Graph<Verteces,Costs>hasVertex(const Verteces &v) const {
    return graph.count(v) > 0;
}

template <class Verteces, class Costs>
bool Graph<Verteces,Costs>hasEdge(const Verteces &v1, const Verteces &v2) const {

    return hasVertex(v1) && hasVertex(v2) && graph[v1].count(v2) > 0;

}


template <class Verteces, class Costs>
const std::map<Verteces,Costs>& Graph<Verteces,Costs>operator[] (const Verteces &v) const {

    return graph[v]
}

template <class Verteces, class Costs>
Graph<Verteces, Costs>::Iterator::Iterator(const typename Graph<Verteces,Costs>::OriginalIter &_it) : it(_it){

}

template <class Verteces, class Costs>
typename Graph<Verteces, Costs>::Iterator& Graph<Verteces, Costs>::Iterator::operator++(){
    ++it;
    return *this;

}

template <class Verteces, class Costs>
bool Graph<Verteces, Costs>::Iterator::operator !=(const typename Graph<Verteces,Costs>::Iterator &other){

    return it != other.it;
}


template <class Verteces, class Costs>
Verteces Graph<Verteces, Costs>::Iterator::operator*() {

    return (*it).first;
}